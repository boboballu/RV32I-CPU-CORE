// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// this file has all pipeline stages (flip-flops) for the processor

// 0th stage - pc_IF stage
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

// 1st stage - IF_ID stage
// stage ctrl inputs - clk, en (active low), clear
// data inputs - rd, pcplus4F
// data outputs - instnD, pcplus4D
module if_id ( 	input logic clk,
				input logic en, clear,
				input logic	[31:0] rd, pcplus4F,
				output logic [31:0] instnD, pcplus4D  );
	always_ff @(posedge clk) begin
		if (clear) begin
			pc <= 0;
		end
		else if(!en) begin
			instnD <= rd;
			pcplus4D <= pcplus4F;
		end
	end
endmodule : if_id
/********************************************************************************/

// 2nd stage - id_ex stage
// stage ctrl inputs - clk, en (active low), clear
// controller inputs - regwriteD, memtoregD, memwriteD, regdstD, alusrcD, alucontrolD
// controller outputs- regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE
// data inputs - A, B, rsD, rtD, rdD, signimmD
// data outputs - AE, BE, rsE, rtE, rdE, signimmE
module id_ex (	input logic clk,
				input logic en, clear,
				input logic regwriteD, memtoregD, memwriteD, regdstD, alusrcD,
				input logic [1:0] alucontrolD,
				input logic [31:0] A, B, signimmD, input logic [4:0] rsD, rtD, rdD,
				output logic regwriteE, memtoregE, memwriteE, regdstE, alusrcE,
				output logic [1:0] alucontrolE,
				output logic [31:0] AE, BE, signimmE, input logic [4:0] rsE, rtE, rdE
				);
	always_ff @(posedge clk) begin
		if (clear) begin
			{regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE} <= 0;
			{rsE, rtE, rdE, AE, BE, signimmE} <= 512'b0;
		end
		else if (!en) begin
			{regwriteE, memtoregE, memwriteE, regdstE, alusrcE, alucontrolE} <= {regwriteD, memtoregD, memwriteD, regdstD, alusrcD, alucontrolD}
			{rsE, rtE, rdE, AE, BE, signimmE} <= {rsD, rtD, rdD, A, B, signimmD};
		end
	end
endmodule : id_ex
/********************************************************************************/

