// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DATAPATH
`include "debug_headerfile.svh"
module datapath(input logic clk, reset,

				controller_if c_bus,
				output logic [31:0] pc,
				output logic [31:0] aluout, writedata,
				input logic [31:0] readdata,
				output logic [3:0] dmem_mask,
				output logic memaccess,
				input logic Iwait, Dwait
);

/********************************************************************************/
	// all functions necessary for load store and c_bus.branch instns
	// are present in the following include
	`include "datapath_functions.svh"
/********************************************************************************/
	logic [4:0] rs1, rs2;
	logic [4:0] rd;
	logic [31:0] pcplus4;
	logic [31:0] signimm, branchimm, jumpimm, stypeimm, itypeimm, utypeimm;
	logic [31:0] srca, srcb;

	logic [31:0] result;

	logic [31:0] srcb_net0;

	logic [2:0] funct3;
	logic [6:0] funct7;

	logic en_pc_reg;

	// pcplus4 adder
	assign pcplus4 = pc + 32'd4;
	// en_pc_reg: hold PC if Iwait or Dwait is high
	assign en_pc_reg = Iwait | Dwait;
	// memaccess: datapath output : is fet if either memtoreg or memwrite is high
	assign memaccess = c_bus.memtoreg | c_bus.memwrite;

	instn_decode instn_decode
				(	.instr(c_bus.instr),
					.funct3(funct3), .funct7(funct7),
					.jumpimm(jumpimm), .branchimm(branchimm), .utypeimm(utypeimm), .itypeimm(itypeimm), .stypeimm(stypeimm),
					.rs1(rs1), .rs2(rs2), .rd(rd)
				);
	// stype and itype corresponds lw sw and imm instns - goes through ALU
	assign signimm = c_bus.memwrite ? stypeimm : itypeimm; // ld st addresses are computed in alu.

	always_ff @(posedge clk or negedge reset) begin
		if (!reset) begin
			pc <= 0;
		end
		else begin
			if (!en_pc_reg) begin
				casez( {c_bus.pcsrc, c_bus.jump, c_bus.jalr} )
					3'b000: pc <= pcplus4;
					3'b010: pc <= pc + jumpimm; // riscv - c_bus.jump
					3'b001: pc <= (itypeimm + srca) & (32'hffff_fffe); // riscv - c_bus.jalr
					3'b100: pc <= pc + branchimm; // riscv - c_bus.branch
					default pc <= pcplus4;
				endcase
			end
		end
	end


	// register file logic
	regfile rf(	.clk(clk), .reset(reset),
				.en_pc_reg(en_pc_reg), .we3(c_bus.regwrite),
				.rs1(rs1), .rs2(rs2), .rd(rd),
				.wd3(result),
				.rs1_data(srca), .rs2_data(srcb_net0)); // riscv - rs1 and rs2
	// ALU logic
	assign srcb = c_bus.alusrc ? signimm : srcb_net0; // srcb mux
	alu alu(.srca(srca), .srcb(srcb), .alucontrol(c_bus.alucontrol),
			.alu_sub(c_bus.alu_sub), .aluout(aluout));

	always_comb begin
		if (c_bus.jump | c_bus.jalr) begin
			result = pcplus4;
		end
		else if (c_bus.auipc) begin
			result = pc + utypeimm;
		end
		else if (c_bus.lui) begin
			result = utypeimm;
		end
		else if (c_bus.memtoreg) begin
			result = load_compute (funct3, aluout, readdata);
		end
		else begin
			result = aluout;
		end

		store_compute (funct3, aluout, srcb_net0, dmem_mask, writedata);
		c_bus.br_taken  = br_compute (c_bus.branch, funct3, srca, srcb);
	end

endmodule : datapath

/********************************************************************************/

/// Generic blocks /////

/// ALU  //////
module alu 	(	input logic [31:0] srca,
				input logic [31:0] srcb,
				input logic [2:0] alucontrol, input logic alu_sub,
				output logic [31:0] aluout /*output logic c_bus.br_taken*/
);

	//assign c_bus.br_taken = (aluout == 32'd0) ? 1 : 0;
	always_comb begin
		if (!alu_sub) begin
			case(alucontrol)
				3'b000: aluout = srca + srcb; // ADD
				3'b001: aluout = srca << srcb[4:0]; // SLL
				3'b010: aluout = ( signed'(srca) < signed'(srcb) ) ? 32'd1 : 32'd0; // SLT
				3'b011: aluout = (srca < srcb) ? 32'd1 : 32'd0; // SLTU
				3'b100: aluout = srca ^ srcb; // XOR
				3'b101: aluout = srca >> srcb[4:0]; // SRL
				3'b110: aluout = srca | srcb; // OR
				3'b111: aluout = srca & srcb; // AND
				default: aluout<= 32'b0;
			endcase
		end
		else begin
			case (alucontrol)
				3'b000:	aluout = srca - srcb; // SUB, BEQ
				3'b101: aluout = signed'(srca) >>> srcb[4:0]; // SRA
				default: aluout = 32'b0;
			endcase
		end
	end
endmodule : alu

module regfile	(	input logic clk, reset,

					input logic en_pc_reg, we3,
					input logic [4:0] rs1, rs2, rd,
					input logic [31:0] wd3,

					output logic [31:0] rs1_data, rs2_data
);
	bit [31:0] rf[31:0];
	// three ported register file
	// read two ports combinationally
	// write third port on rising edge of clk
	// register 0 hardwired to 0
	// note: for pipelined processor, write third port
	// on falling edge of clk

	always_ff @(posedge clk or negedge reset) begin
		if (!reset) begin
			rf <= '{default:'0};
		end
		else begin
			if (!en_pc_reg) begin
				if (we3) rf[rd] <= wd3;
			end
		end
	end
	assign rs1_data = (rs1 != 0) ? rf[rs1] : 0;
	assign rs2_data = (rs2 != 0) ? rf[rs2] : 0;
endmodule : regfile

module instn_decode 	(
							input logic [31:0] instr,
							output logic [2:0] funct3, output logic [6:0] funct7,
							output logic [31:0] jumpimm, branchimm, utypeimm, stypeimm, itypeimm,
							output logic [4:0] rs1, rs2, rd
);
	// control funct signals from instr
	assign funct3 = instr[14:12];
	assign funct7 = instr[31:25];

	// source and destination reg addrs
	assign rs1 = instr[19:15];
	assign rs2 = instr[24:20];
	assign rd  = instr[11:7]; // dest reg

	// all the immediate logics
	assign jumpimm   = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0}; // riscv - for jump
	assign branchimm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0}; // riscv - for branch
	assign utypeimm  = {instr[31:12], {12'b0}}; // riscv - for lui and auipc
	// stype and itype corresponds lw sw and imm instns - goes through ALU
	assign stypeimm  = {{20{instr[31]}},instr[31:25], instr[11:7]}; // store
	assign itypeimm  = {{20{instr[31]}}, instr[31:20]}; // load, jalr and imm-arth

endmodule : instn_decode
