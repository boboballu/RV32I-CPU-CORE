// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module datapath(input logic clk, reset,
				input logic memwrite,
				input logic memtoreg, pcsrc,
				input logic alusrc, regdst,
				input logic regwrite, jump,
				input logic [2:0] alucontrol, input logic alu_sub,
				output logic zero,
				output logic [31:0] pc,
				input logic [31:0] instr,
				output logic [31:0] aluout, writedata,
				input logic [31:0] readdata);
	
	logic [4:0] writereg;
	logic [31:0] pcnext, pcnextbr, pcplus4, pcbranch;
	logic [31:0] signimm, branchimm;
	logic [31:0] srca, srcb;
	logic [31:0] result;
	logic [31:0] jumpimm;
	// next PC logic
	assign pcplus4 = pc + 32'd4;
	//assign branchimm = signimm << 2; // signextended immediate left shifted by 2;  
	assign jumpimm = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0}; // riscv - for jump
	assign branchimm = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0}; // riscv - for branch
	always_ff @(posedge clk, posedge reset) begin
		if (reset) begin
			pc <= 0;
		end
		else begin
			case( {pcsrc, jump} )
				2'b00: pc <= pcplus4;
				//2'b01: pc <= {pcplus4[31:28], instr[25:0], 2'b00};  // jump
				//2'b10: pc <= pcplus4 + branchimm;  // branch
				2'b01: pc <= pc + jumpimm; // riscv - jump
				2'b10: pc <= pc + branchimm; // riscv - branch
				default pc <= pcplus4;
			endcase
		end
	end
	// register file logic
	regfile rf(clk, regwrite, instr[19:15], instr[24:20], writereg, result, srca, writedata); // riscv - rs1 and rs2
	assign signimm = memwrite ? {{20{instr[31]}},instr[31:25], instr[11:7]} : {{20{instr[31]}}, instr[31:20]}; // riscv - Imm for I type
	//assign writereg = regdst ? instr[15:11] : instr[20:16]; // regfile write address
	assign writereg = instr[11:7]; // riscv - dest reg
	assign result = jump ? pcplus4 :(memtoreg ? readdata : aluout); // riscv - jump : regfile write data
	// ALU logic
	assign srcb = alusrc ? signimm : writedata; // srcb mux
	alu alu(srca, srcb, alucontrol, alu_sub, aluout, zero);
endmodule

/// Generic blocks /////

/// ALU  //////
module alu (	input logic [31:0] srca, 
				input logic [31:0] srcb, 
				input logic [2:0] alucontrol, input logic alu_sub,
				output logic [31:0] aluout, 
				output logic zero
			);
	
	assign zero = (aluout == 32'd0) ? 1 : 0;
	always_comb begin
		if (!alu_sub) begin
			case(alucontrol)
				3'b000: aluout <= srca + srcb;
				3'b110: aluout <= srca | srcb;
				3'b111: aluout <= srca & srcb;
				3'b010: aluout <= (srca < srcb) ? 32'd1 : 32'd0;
				default: aluout<= 32'bx;
			endcase
		end
		else begin
			aluout <= srca - srcb;
		end
	end
endmodule

module regfile(input logic clk,
				input logic we3,
				input logic [4:0] ra1, ra2, wa3,
				input logic [31:0] wd3,
				output logic [31:0] rd1, rd2);
	logic [31:0] rf[31:0];
	// three ported register file
	// read two ports combinationally
	// write third port on rising edge of clk
	// register 0 hardwired to 0
	// note: for pipelined processor, write third port
	// on falling edge of clk
	always_ff @(posedge clk) begin
		if (we3) rf[wa3] <= wd3;
	end
	assign rd1 = (ra1 != 0) ? rf[ra1] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2] : 0;
endmodule