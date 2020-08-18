// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// all combinational circuitry in the datapath is put together in respective modules stage-wise.   
`include "debug_headerfile.svh"
import dbg_pkg::*;
// 0th module in the machinary - purely combinatioal
// control signals - pcsrcD
// Datapath nets inputs - pcplus4F[Fetch], pcbranchD[Decode], jump_targetD
// Datapath nets putput - pc [flopped in pc register]
module pc_gen (
				input logic pcsrcD, jumpD,
				input logic [31:0] pcbranchD, jump_targetD,
				input logic [31:0] pcplus4F,
				output logic [31:0] pc
			  );
	
	//assign pc = pcsrcD ? pcbranchD : pcplus4F;
	always_comb begin
		case ({pcsrcD, jumpD})
			2'b00: pc = pcplus4F;
			2'b01: pc = jump_targetD;
			2'b10: pc = pcbranchD;
			default: pc = pcplus4F;
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

	assign pc_imem = pc;
	assign instnF = imem_instn;
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
module ID_comb ( input logic clk,
				 input regwriteW,
				 input [31:0] instnD, pc, pcplus4D,
				 input forwardAD, forwardBD,
				 input memwriteD,
				 input [4:0] writeregW,
				 input [31:0] resultW, aluoutM,
				 //output [31:0] a, b, signimmD, 
				 output [31:0] pcbranchD, jump_targetD,
				 datapath_if.reg_in Ddo,
				 output equalD  
			   );

	wire [31:0] A_reg, B_reg;
	regfile rf (.clk(clk),
				.we3(regwriteW),
				.ra1(instnD[19:15]), .ra2(instnD[24:20]), .wa3(writeregW),
				.wd3(resultW),
				.rd1(A_reg), .rd2(B_reg)
			   );

	assign Ddo.srca = forwardAD ? aluoutM : A_reg;
	assign Ddo.srcb = forwardBD ? aluoutM : B_reg;

	assign jump_targetD = pc + {{11{instnD[31]}}, instnD[31], instnD[19:12], instnD[20], instnD[30:21], 1'b0};
	assign pcbranchD = pc + {{19{instnD[31]}}, instnD[31], instnD[7], instnD[30:25], instnD[11:8], 1'b0};	
	assign Dpo.signimm = memwriteD ? {{20{instnD[31]}},instnD[31:25], instnD[11:7]} : {{20{instnD[31]}}, instnD[31:20]};

	assign equalD = (a - b) ? 1'b0 : 1'b1;
endmodule : ID_comb

// register file - writes during negedge of clk
module regfile(input logic clk,
				input logic we3,
				input logic [4:0] ra1, ra2, wa3,
				input logic [31:0] wd3,
				output logic [31:0] rd1, rd2);
	bit [31:0] rf[31:0];
	// three ported register file
	// read two ports combinationally
	// write third port on rising edge of clk
	// register 0 hardwired to 0
	// note: for pipelined processor, write third port
	// on falling edge of clk
	always_ff @(negedge clk) begin
		if (we3) rf[wa3] <= wd3;
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
/********************************************************************************/ 
// riscv addition - (in) jumpE, alu_subE, pcplus4E
module EX_comb (	//input logic jumpE, 
					controller_if.reg_out Eci,
					input logic [31:0] pcplus4E,
					//input logic alusrcE, input logic [2:0] alucontrolE, input logic alu_subE,
					input logic [1:0] forwardAE, input logic [1:0] forwardBE,
					//input logic [31:0] a, input logic [31:0] b, input logic [31:0] signimmE,
					datapath_if.reg_out Edi,
					input logic [31:0] resultW, input logic [31:0] aluoutM,
					//output logic [31:0] aluoutE, output logic [31:0] writedataE
					datapath_if.reg_in Edo
					`ifdef BR_RESOLVE_M
					, output logic zeroE
					`endif
				);
	logic [31:0] srcAE, srcBE, srcBE_net0, aluout_net0;
	logic alu_zero_flag; // unconnected net
	
	`ifdef BR_RESOLVE_M
	assign zeroE = alu_zero_flag;
	`endif
	
	assign Edo.writedata = srcBE_net0;
	assign srcBE = Eci.alusrc ? Edi.signimm : srcBE_net0;

	assign Edo.aluout = Eci.jump ? pcplus4E : aluout_net0;
	always_comb begin
		case (forwardAE)
			2'b00: srcAE = Edi.srca;	
			2'b01: srcAE = resultW;
			2'b10: srcAE = aluoutM;
			default: srcAE = 32'bx;
		endcase
	end

	always_comb begin
		case (forwardBE)
			2'b00: srcBE_net0 = Edi.srcb;
			2'b01: srcBE_net0 = resultW;
			2'b10: srcBE_net0 = aluoutM;
			default: srcBE_net0 = 32'bx;
		endcase
	end

	alu alu0 (	.srca(srcAE), .srcb(srcBE), 
				.alucontrol(Eci.alucontroE), .alu_sub(Eci.alu_sub),
				.aluout(aluout_net0), .zero(alu_zero_flag)
			 );

endmodule : EX_comb

/// EX Stage - ALU  //////
module alu (	input logic [31:0] srca, input logic [31:0] srcb, 
				input logic [2:0] alucontrol, input logic alu_sub,
				output logic [31:0] aluout, output logic zero
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
				  input logic memwriteM,
				  input logic [31:0] aluoutM_in, input logic [31:0] writedataM,
				  input logic [31:0] dmem_rd,
				  output logic [31:0] dmem_addr, dmem_wd,
				  output logic dmem_we,
				  output logic [31:0] readdataM, aluoutM_out);
	
	assign dmem_addr = aluoutM_in;
	assign dmem_wd = writedataM;
	assign dmem_we = memwriteM;
	assign readdataM = dmem_rd;

	assign aluoutM_out = aluoutM_in;

endmodule : MEM_comb
/********************************************************************************/

// 5th module in the machinary - purely combinational
// control signals - memregW
// datapath nets inputs - readdataW, aluoutW
// datapath nets outputs - resultW
module WB_comb (input logic memtoregW,
				input logic [31:0] readdataW, input logic [31:0] aluoutW,
				output logic [31:0] resultW);
	assign resultW = memtoregW ? readdataW : aluoutW;
endmodule : WB_comb
/********************************************************************************/