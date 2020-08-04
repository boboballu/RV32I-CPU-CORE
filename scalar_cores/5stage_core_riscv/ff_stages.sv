// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// this file has all pipeline stages (flip-flops) for the processor
import dbg_pkg::*;

// 1st stage - pc_IF stage
// stage ctrl inputs - clk, en (active low), clear
// data input 	  - pc 
// output 		  - pcF
module pc_if (	input logic clk, reset,
				input logic en, clear,
				
				input logic [31:0] pc,
				
				output logic [31:0] pcF 
);

	always_ff @(posedge clk or negedge reset) begin
		if (clear | !reset) begin
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
module if_id ( 	input logic clk, reset,
				input logic en, clear,
				
				input logic	[31:0] rd, pcF, pcplus4F,
				
				output logic [31:0] instnD, pcD, pcplus4D  
);

	always_ff @(posedge clk or negedge reset) begin
		if (clear | !reset) begin
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

module id_ex (	input logic clk, reset,
				input logic en, clear,
				
				input logic jumpD, jalrD, input logic [31:0] pcD, pcplus4D,
				input logic regwriteD, memtoregD, memwriteD, alusrcD,
				input logic [2:0] alucontrolD, input logic alu_subD, input logic [2:0] funct3D,
				input logic auipcD, luiD, 
				input logic [31:0] a, b, signimmD, input logic [4:0] rsD, rtD, rdD, input logic [31:0] utypeimmD,
				input logic branchD, input logic [31:0] branchimmD,
				
				output logic jumpE, jalrE, output logic [31:0] pcE, pcplus4E,
				output logic regwriteE, memtoregE, memwriteE, alusrcE,
				output logic [2:0] alucontrolE, output logic alu_subE, output logic [2:0] funct3E,
				output logic auipcE, luiE,
				output logic [31:0] aE, bE, signimmE, output logic [4:0] rsE, rtE, rdE, output logic [31:0] utypeimmE,
				output logic branchE, output logic [31:0] branchimmE
);

	always_ff @(posedge clk or negedge reset) begin
		if (clear | !reset) begin
			{regwriteE, memtoregE, memwriteE, alusrcE, alucontrolE, alu_subE, funct3E} <= 'b0;
			{rsE, rtE, rdE, aE, bE, signimmE, utypeimmE} <= 'b0;
			{auipcE, luiE} <= 'b0;
			{jumpE, jalrE} <= 'b0;
			pcE 		<= 'b0;
			pcplus4E 	<= 'b0;
			branchE		<= 'b0;
			branchimmE	<= 'b0;
		end
		else if (!en) begin
			{regwriteE, memtoregE, memwriteE, alusrcE, alucontrolE, alu_subE, funct3E} <= {regwriteD, memtoregD, memwriteD, alusrcD, alucontrolD, alu_subD, funct3D};
			{rsE, rtE, rdE, aE, bE, signimmE, utypeimmE} <= {rsD, rtD, rdD, a, b, signimmD, utypeimmD};
			{auipcE, luiE} <= {auipcD, luiD};
			{jumpE, jalrE} <= {jumpD, jalrD};
			pcE			<= pcD;
			pcplus4E 	<= pcplus4D;
			branchE		<= branchD; 
			branchimmE	<= branchimmD;
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
module ex_mem (	input logic clk, reset,
				input logic en, clear,
				
				input logic [2:0] funct3E,
				input logic regwriteE, memtoregE, memwriteE,
				input logic [31:0] aluoutE, writedataE, input logic [4:0] writeregE,
				input logic branchE, input logic [31:0] branchimmE,
				
				output logic [2:0] funct3M,
				output logic regwriteM, memtoregM, memwriteM,
				output logic [31:0] aluoutM, writedataM, output logic [4:0] writeregM,
				output logic branchM, output logic [31:0] branchimmM
);

	always_ff @(posedge clk or negedge reset) begin
		if (clear | !reset) begin
			{regwriteM, memtoregM, memwriteM, funct3M} <= 'b0;
			{aluoutM, writedataM, writeregM} <= 'b0;
			branchM 	<= 'b0;
			branchimmM 	<= 'b0; 
		end
		else if (!en) begin
			{regwriteM, memtoregM, memwriteM, funct3M} <= {regwriteE, memtoregE, memwriteE, funct3E};
			{aluoutM, writedataM, writeregM}  <= {aluoutE, writedataE, writeregE};
			branchM 	<= branchE;
			branchimmM	<= branchimmE;
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
module mem_wb (	input logic clk, reset,
				input logic en, clear,
				
				input logic regwriteM, memtoregM,
				input logic [31:0] aluoutM, readdataM, input logic [4:0] writeregM,
				input logic branchM, input logic [31:0] branchimmM,
				
				output logic regwriteW, memtoregW,
				output logic [31:0] aluoutW, readdataW, output logic [4:0] writeregW,
				output logic branchW, output logic [31:0] branchimmW
);

	always_ff @(posedge clk or negedge reset) begin
		if (clear | !reset) begin
			{regwriteW, memtoregW} <= 0;
			{aluoutW, readdataW, writeregW} <= 0;
			branchW 	<= 'b0;
			branchimmW 	<= 'b0;
		end
		else if (!en) begin
			{regwriteW, memtoregW} <= {regwriteM, memtoregM};
			{aluoutW, readdataW, writeregW} <= {aluoutM, readdataM, writeregM};
			branchW 	<= branchM;
			branchimmW 	<= branchimmM;
		end
	end
endmodule : mem_wb

