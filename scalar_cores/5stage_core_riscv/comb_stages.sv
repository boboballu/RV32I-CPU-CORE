// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define COMB_STAGES
`include "debug_headerfile.svh"
import dbg_pkg::*;

// all combinational circuitry in the datapath is put together in respective modules stage-wise.   
// 0th module in the machinary - purely combinatioal
// control signals - br_takenD
// Datapath nets inputs - pcplus4F[Fetch], pcbranchD[Decode], jump_targetD
// Datapath nets putput - pc [flopped in pc register]
module pc_gen (
				input logic branchD,
				input logic br_takenD, jumpD, jalrD, 
				input logic BTBHitF, BpredF, 
				input logic BTBHitD, BpredD,
				input logic [31:0] branchimmF, branchimmD, jumpimmD, itypeimmD,
				input logic [31:0] pcF, pcplus4F, pcD, pcplus4D,
				input logic [31:0] srcaD,
				
				output logic [31:0] pc
);
	
	//assign pc = br_takenD ? pcbranchD : pcplus4F;

	// always_comb begin
	// 	casex ({br_takenD, jumpD, jalrD})
	// 		3'b000: pc 	= pcplus4F;
	// 		3'b010: pc 	= pcD + jumpimmD; // riscv - c_bus.jump
	// 		3'b0x1: pc 	= (itypeimmD + srcaD) & (32'hffff_fffe); // riscv - c_bus.jalr
	// 		3'b1xx: pc 	= pcD + branchimmD; // riscv - c_bus.branch
	// 		default: pc = pcplus4F;
	// 	endcase
	// end

	always_comb begin
		casez ({branchD, BTBHitD, BpredD, br_takenD, jumpD, jalrD, BTBHitF, BpredF})
			// if branch and BTBHit (@ Decode)
			8'b1110????: pc = pcplus4D;				// branch miss predicted taken at fetch; recover to pcplus4D
			8'b1101????: pc = pcD + branchimmD;		// branch miss predicted not taken at fetch; recover to branchimmD

			// if branch and BTBMiss (@ Decode)
			8'b1011????: pc = pcD + branchimmD;		// branch to branchimmD 
			8'b1001????: pc = pcD + branchimmD;		// branch to branchimmD

			8'b0???10??: pc = pcD + jumpimmD;		// Jump instn
			8'b0???01??: pc = (itypeimmD + srcaD) & (32'hffff_fffe); // jalr instn

			// @ fetch
			8'b????0011: pc = pcF + branchimmF; 	// BTBHit, branch predicted taken, branch pc
			8'b????0010: pc = pcplus4F;				// BTBHit, branch predicted not taken, pcplus4F
			8'b????0001: pc = pcplus4F;				// BTBMiss, branch is predicted not taken
			8'b????0000: pc = pcplus4F;				// BTBMiss, branch is predicted not taken

			default: 	begin
							pc = pcplus4F;
							//assert(0);
						end
		endcase
	end
endmodule : pc_gen

/********************************************************************************/

// 1st module in the machinary - purely combinational (IMEM doesnt have a clk!)
// control signals - none
// input to imem - pc_imem
// input from imem - imem_instn
// datapath nets inputs - pc
// datapath nets outputs - instnF, pcplus4F
module IF_comb (
				input logic [31:0] pc,
				input logic [31:0] imem_instn,
				
				output logic [31:0] pc_imem,
				output logic [31:0] instnF,
				output logic [31:0] pcplus4F
);

	assign pc_imem 	= pc;
	assign instnF 	= imem_instn;
	assign pcplus4F = pc + 32'd4;
endmodule : IF_comb

/********************************************************************************/ 

// 2nd module in the machinary - reg file writes at negedge clk
// clock - clk
// control signals - regwriteW
// hazard signals - forwardAD, forwardBD
// bypass nets inputs - resultW, aluoutM
// datapath nets inputs - writeregW, instnD, pcplus4D, 
// datapath nets outputs - a, b, equalD, signimmD, pcbranchD, jump_targetD
// riscv addition - (in) pc, memwriteD
module ID_comb ( input logic clk, reset,
				 
				 input logic [31:0] pc,
				 input logic regwriteW,
				 input logic [4:0] rsD, rtD,
				 input logic [31:0] jumpimmD, branchimmD, itypeimmD, stypeimmD,
				 input logic forwardAD, forwardBD,
				 input logic memwriteD,
				 input logic [4:0] writeregW,
				 input logic [31:0] resultW, aluoutM,
				 
				 output logic [31:0] a, b, signimmD
);

	wire [31:0] A_reg, B_reg;
	regfile rf (.clk(clk), .reset(reset),
				
				.we3(regwriteW),
				.ra1(rsD), .ra2(rtD), .wa3(writeregW),
				.wd3(resultW),
				
				.rd1(A_reg), .rd2(B_reg)
			   );

	assign a = forwardAD ? aluoutM : A_reg;
	assign b = forwardBD ? aluoutM : B_reg;

	// assign jump_targetD = pc + jumpimmD;
	// assign pcbranchD = pc + branchimmD;	
	assign signimmD = memwriteD ? stypeimmD : itypeimmD;

	//assign equalD = (a - b) ? 1'b0 : 1'b1;
endmodule : ID_comb

// register file - writes during negedge of clk
module regfile(	input logic clk, reset,
				
				input logic we3,
				input logic [4:0] ra1, ra2, wa3,
				input logic [31:0] wd3,
				
				output logic [31:0] rd1, rd2
);
	bit [31:0] rf[31:0];
	// three ported register file
	// read two ports combinationally
	// write third port on falling edge of clk
	// register 0 hardwired to 0
	// note: for pipelined processor, write dest port
	// on falling edge of clk
	always_ff @(negedge clk or negedge reset) begin
		if (!reset) begin
			rf <= '{default:'0};
		end
		else begin
			if (we3) rf[wa3] <= wd3;
		end
	end
	assign rd1 = (ra1 != 0) ? rf[ra1] : 0;
	assign rd2 = (ra2 != 0) ? rf[ra2] : 0;
endmodule : regfile

/********************************************************************************/

// 3rd module in the machinary - purely combinational
// control signals - alusrcE, aluctrlE
// hazard signals - forwardAE, forwardBE
// datapath nets inputs - a, b, signimmE
// bypass nets inputs - resultW, aluoutM 
// datapath nets outputs - aluoutE, writedataE
// riscv addition - (in) jumpE, alu_subE, pcplus4E
module EX_comb (	input logic jumpE, jalrE, auipcE, luiE, input logic [31:0] pcE, pcplus4E,
					input logic alusrcE, input logic [2:0] alucontrolE, input logic alu_subE,
					input logic [1:0] forwardAE, input logic [1:0] forwardBE,
					input logic [31:0] a, input logic [31:0] b, input logic [31:0] signimmE, utypeimmE,
					input logic [31:0] resultW, input logic [31:0] aluoutM,
					
					output logic [31:0] aluoutE, output logic [31:0] writedataE
);
	logic [31:0] srcAE, srcBE, srcBE_net0, aluout_net0;
		
	assign writedataE = srcBE_net0;
	assign srcBE = alusrcE ? signimmE : srcBE_net0;

	always_comb begin
		case (forwardAE)
			2'b00: srcAE = a;	
			2'b01: srcAE = resultW;
			2'b10: srcAE = aluoutM;
			default: srcAE = 32'bx;
		endcase
	end

	always_comb begin
		case (forwardBE)
			2'b00: srcBE_net0 = b;
			2'b01: srcBE_net0 = resultW;
			2'b10: srcBE_net0 = aluoutM;
			default: srcBE_net0 = 32'bx;
		endcase
	end

	alu alu0 (	.srca(srcAE), .srcb(srcBE), 
				.alucontrol(alucontrolE), .alu_sub(alu_subE),
				
				.aluout(aluout_net0)
	);
	
	always_comb begin
		if (jumpE | jalrE) begin
			aluoutE = pcplus4E;
		end
		else if (auipcE) begin
			aluoutE = pcE + utypeimmE;
		end
		else if (luiE) begin
			aluoutE = utypeimmE;
		end
		else begin
			aluoutE = aluout_net0;
		end
	end
endmodule : EX_comb

// ALU 
module alu 	(	input logic [31:0] srca, 
				input logic [31:0] srcb, 
				input logic [2:0] alucontrol, input logic alu_sub,
				
				output logic [31:0] aluout
);

	always_comb begin
		if (!alu_sub) begin
			case(alucontrol)
				3'b000: aluout = srca + srcb; // ADD
				3'b001: aluout = srca << srcb[4:0]; // SLL
				3'b010: aluout = ( signed'(srca) < signed'(srcb) ); // SLT
				3'b011: aluout = (srca < srcb) ? 32'd1 : 32'd0; // SLTU
				3'b100: aluout = srca ^ srcb; // XOR
				3'b101: aluout = srca >> srcb[4:0]; // SRL
				3'b110: aluout = srca | srcb; // OR
				3'b111: aluout = srca & srcb; // AND
				default: aluout<= 32'bx;
			endcase
		end
		else begin
			case (alucontrol)
				3'b000:	aluout = srca - srcb; // SUB, BEQ
				3'b101: aluout = {srca, srca} >> srcb[4:0]; // SRA
				default: aluout= 32'bx;
			endcase
		end
	end
endmodule : alu

/********************************************************************************/

// 4th module in the machinary - (data cache write is clocked)
// control signals - memwriteM
// hazard signals -  none
// inputs to dmem - dmem_addr, dmem_wd, dmem_we
// input from dmem - dmem_ed
// datapath input nets - memwriteM, aluoutM_in, writedataM
// datapath output nets - readdataM, aluoutM_out
module MEM_comb (
				input logic [2:0] funct3M,
				input logic memwriteM,
				input logic [31:0] aluoutM_in, input logic [31:0] writedataM,
				input logic [31:0] dmem_rd,
				
				output logic [31:0] dmem_addr, dmem_wd,
				output logic [3:0] dmem_mask,
				output logic dmem_we,
				output logic [31:0] readdataM, aluoutM_out
);
	
	// assign dmem_addr = aluoutM_in;
	// assign dmem_wd = writedataM;
	// assign dmem_we = memwriteM;
	// assign readdataM = dmem_rd;
	// assign aluoutM_out = aluoutM_in;
	`include "ls_compute.svh"
	always_comb begin
		dmem_addr 	= aluoutM_in;
		aluoutM_out = aluoutM_in;
		dmem_we 	= memwriteM;
		readdataM 	= load_compute (funct3M, aluoutM_in, dmem_rd);
		//dmem_wd 	= store_compute(funct3M, aluoutM_in, dmem_rd, writedataM);
		// new store_compute implementation - 10/12/2020
		store_compute (funct3M, aluoutM_in, writedataM, dmem_mask, dmem_wd);
	end
	
endmodule : MEM_comb
/********************************************************************************/

// 5th module in the machinary - purely combinational
// control signals - memregW
// datapath nets inputs - readdataW, aluoutW
// datapath nets outputs - resultW
module WB_comb (input logic memtoregW,
				input logic [31:0] readdataW, input logic [31:0] aluoutW,
				
				output logic [31:0] resultW
);

	assign resultW = memtoregW ? readdataW : aluoutW;
endmodule : WB_comb
/********************************************************************************/