// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// this file has all pipeline stages (flip-flops) for the processor
`include "debug_headerfile.sv"
import dbg_pkg::*;
// 1st stage - pc_IF stage
// stage ctrl inputs - clk, en (active low), clear
// data input 	  - pc 
// output 		  - pcF
module pc_if (	input logic clk,
				input logic en, clear,
				input logic [31:0] pc,
				output logic [31:0] pcF  );
	always_ff @(posedge clk) begin
		if (clear) begin
			pcF <= 0;
		end
		else if(!en) begin
			pcF <= pc;
		end
	end
endmodule : pc_if
/********************************************************************************/

// 2nd stage - IF_ID stage
// stage ctrl inputs - clk, en (active low), clear
// data inputs - rd, pcplus4F
// data outputs - instnD, pcplus4D
// riscv additions - pc
module if_id ( 	input logic clk,
				input logic en, clear,
				input logic	[31:0] rd, pcF, pcplus4F,
				output logic [31:0] instnD, pcD, pcplus4D  );
	always_ff @(posedge clk) begin
		if (clear) begin
			instnD <= 0;
			pcD <= 0;
			pcplus4D <= 0;
		end
		else if(!en) begin
			instnD <= rd;
			pcD <= pcF;
			pcplus4D <= pcplus4F;
		end
	end
endmodule : if_id
/********************************************************************************/

// 3rd stage - id_ex stage
// stage ctrl inputs - clk, en (active low), clear
// controller inputs - regwriteD, memtoregD, memwriteD, regdstD, alusrcD, alucontrolD
// controller outputs- regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE
// data inputs - a, b, rsD, rtD, rdD, signimmD
// data outputs - aE, bE, rsE, rtE, rdE, signimmE
// riscv additions - jump, pcplus4, alu_sub 
// riscv modifications - regdst no longer required
module id_ex (	input logic clk,
				input logic en, clear,
				input logic jumpD, input logic [31:0] pcplus4D,
				input logic regwriteD, memtoregD, memwriteD, alusrcD,
				input logic [2:0] alucontrolD, input logic alu_subD,
				input logic [31:0] a, b, signimmD, input logic [4:0] rsD, rtD, rdD,
				output logic jumpE, output logic [31:0] pcplus4E,
				output logic regwriteE, memtoregE, memwriteE, alusrcE,
				output logic [2:0] alucontrolE, output logic alu_subE,
				output logic [31:0] aE, bE, signimmE, output logic [4:0] rsE, rtE, rdE
				`ifdef BR_RESOLVE_M // BR evaluation in EX stage - pipeline registers
				, input logic [31:0] pcbranchD,
				  output logic [31:0] pcbranchE,
				  input logic branchD,
				  output logic branchE
				`endif
			 );

	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteE, memtoregE, memwriteE, alusrcE, alucontrolE, alu_subE} <= 0;
			{rsE, rtE, rdE, aE, bE, signimmE} <= 0;
			jumpE <= 0;
			pcplus4E <= 0;
			`ifdef BR_RESOLVE_M
			pcbranchE <= 0;
			branchE <= 0;
			`endif
		end
		else if (!en) begin
			{regwriteE, memtoregE, memwriteE, alusrcE, alucontrolE, alu_subE} <= {regwriteD, memtoregD, memwriteD, alusrcD, alucontrolD, alu_subD};
			{rsE, rtE, rdE, aE, bE, signimmE} <= {rsD, rtD, rdD, a, b, signimmD};
			jumpE <= jumpD;
			pcplus4E <= pcplus4D;
			`ifdef BR_RESOLVE_M
			pcbranchE <= pcbranchD;
			branchE <= branchD;
			`endif
		end
	end
endmodule : id_ex
/********************************************************************************/

// 4th stage - ex_mem stage
// stage ctrl inputs - clk, en (active low), clear
// controller inputs - regwriteE, memtoregE, memwriteE
// controller outputs - regwriteM, memtoregM, memwriteM
// data inputs - aluoutE, writedataE,   [4:0]writeregE(dest addr)
// data outputs - aluoutM, writedataM, 	[4:0]writeregM(dest addr)
module ex_mem (	input logic clk,
				input logic en, clear,
				input logic regwriteE, memtoregE, memwriteE,
				input logic [31:0] aluoutE, writedataE, input logic [4:0] writeregE,
				output logic regwriteM, memtoregM, memwriteM,
				output logic [31:0] aluoutM, writedataM, output logic [4:0] writeregM
				`ifdef BR_RESOLVE_M // BR evaluation in EX stage - pipeline registers
				, input logic [31:0] pcbranchE,
				  output logic [31:0] pcbranchM,
				  input logic branchE, zeroE,
				  output logic branchM, zeroM
				`endif
				);

	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteM, memtoregM, memwriteM} <= 0;
			{aluoutM, writedataM, writeregM} <= 0;
			`ifdef BR_RESOLVE_M
			branchM <= 0;
			zeroM   <= 0;
			pcbranchM <= 0;
			`endif
		end
		else if (!en) begin
			{regwriteM, memtoregM, memwriteM} <= {regwriteE, memtoregE, memwriteE};
			{aluoutM, writedataM, writeregM}  <= {aluoutE, writedataE, writeregE};
			`ifdef BR_RESOLVE_M
			branchM <= branchE;
			zeroM   <= zeroE;
			pcbranchM <= pcbranchE;
			`endif
		end
	end
endmodule : ex_mem
/********************************************************************************/

// 5th stage - mem_wb stage
// stage ctrl inputs - clk, en (active low), clear
// controller inputs - regwriteM, memtoregM
// controller outputs- regwriteW, memtoregW
// data inputs - aluoutM, readdataM, writeregM
// data outputs - aluoutW, readdataW, writeregW
module mem_wb (	input logic clk,
				input logic en, clear,
				input logic regwriteM, memtoregM,
				input logic [31:0] aluoutM, readdataM, input logic [4:0] writeregM,
				output logic regwriteW, memtoregW,
				output logic [31:0] aluoutW, readdataW, output logic [4:0] writeregW
				);
	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteW, memtoregW} <= 0;
			{aluoutW, readdataW, writeregW} <= 0;
		end
		else if (!en) begin
			{regwriteW, memtoregW} <= {regwriteM, memtoregM};
			{aluoutW, readdataW, writeregW} <= {aluoutM, readdataM, writeregM};
		end
	end
endmodule : mem_wb

