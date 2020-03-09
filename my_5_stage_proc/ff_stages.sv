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
module if_id ( 	input logic clk,
				input logic en, clear,
				input logic	[31:0] rd, pcplus4F,
				output logic [31:0] instnD, pcplus4D  );
	always_ff @(posedge clk) begin
		if (clear) begin
			instnD <= 0;
			pcplus4D <= 0;
		end
		else if(!en) begin
			instnD <= rd;
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
module id_ex (	input logic clk,
				input logic en, clear,
				input logic regwriteD, memtoregD, memwriteD, regdstD, alusrcD,
				input logic [2:0] alucontrolD,
				input logic [31:0] a, b, signimmD, input logic [4:0] rsD, rtD, rdD,
				output logic regwriteE, memtoregE, memwriteE, regdstE, alusrcE,
				output logic [2:0] alucontrolE,
				output logic [31:0] aE, bE, signimmE, output logic [4:0] rsE, rtE, rdE
				);
	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE} <= 0;
			{rsE, rtE, rdE, aE, bE, signimmE} <= 0;
		end
		else if (!en) begin
			{regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE} <= {regwriteD, memtoregD, memwriteD, regdstD, alusrcD, alucontrolD};
			{rsE, rtE, rdE, aE, bE, signimmE} <= {rsD, rtD, rdD, a, b, signimmD};
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
				);
	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteM, memtoregM, memwriteM} <= 0;
			{aluoutM, writedataM, writeregM} <= 0;
		end
		else if (!en) begin
			{regwriteM, memtoregM, memwriteM} <= {regwriteE, memtoregE, memwriteE};
			{aluoutM, writedataM, writeregM}  <= {aluoutE, writedataE, writeregE};
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

