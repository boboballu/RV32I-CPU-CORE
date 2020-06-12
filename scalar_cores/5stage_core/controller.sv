// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the controller has main and alu decoder 
// main decoder - for identifying instruction type
// alu decoder 	- specifies alu finctionality for different opcode
`include "debug_headerfile.sv"
import dbg_pkg::*;
// controller:
// inputs - instnD (6'opD->[6:0] | 3'funct3D->[14:12] | 7'funct7D->[31:25]); equalD - to determin pcsrcD
// control outputs - 
// pcsrcD and jumpD - change next PC (to the PC mux), flush IF_ID pipeline
// regwriteD - write EN for reg file
// memtoregD - for load instn
// memwriteD - for store instn
// regdstD 	 - destination selection mux (instn[15:11] for R-R instn type, instn[25:21] otherwise)
// alusrcD   - alu B source operand selection mux
// alucontrol- alu operation
// riscv additions - (in) opD, funct3D, funct7D; (out) alu_subD
// riscv modifications - regdstD no longer required
module controller(	input logic [6:0] opD, input logic [2:0] funct3D, input logic [6:0] funct7D,
					input logic equalD,
					output logic branchD, pcsrcD, jumpD,
					output logic regwriteD,
					output logic memtoregD, memwriteD,
					output logic alusrcD,
					output logic [2:0] alucontrolD,
					output logic alu_subD
				 );

	logic [1:0] aluop;

	maindec md(	.opD(opD), 
				.memtoregD(memtoregD), .memwriteD(memwriteD),
				.branchD(branchD), .alusrcD(alusrcD), 
				.regwriteD(regwriteD), 
				.jumpD(jumpD), .aluop(aluop)
			  );

	aludec ad(	.funct3D(funct3D), .funct7D(funct7D), 
				.aluop(aluop), 
				.alucontrolD(alucontrolD),
				.alu_subD(alu_subD)
			 );

	assign pcsrcD = branchD & equalD;
endmodule : controller

// maindec: generate all the control signals
module maindec(	input logic [6:0] opD,
				output logic memtoregD, memwriteD,
				output logic branchD, alusrcD,
				output logic regwriteD,
				output logic jumpD,
				output logic [1:0] aluop
			  );

	logic [5:0] controls;
	assign {regwriteD, alusrcD, branchD, memwriteD, memtoregD, jumpD} = controls;
	always_comb begin
		case(opD)
			7'b0110011: begin controls <= 6'b100000;  aluop <= 2'b10; end // RTYPE
			7'b0000011: begin controls <= 6'b110010;  aluop <= 2'b00; end // LW
			7'b0100011: begin controls <= 6'b010100;  aluop <= 2'b00; end // SW
			7'b0010011: begin controls <= 6'b110000;  aluop <= 2'b00; end // ADDI
			7'b1100011: begin controls <= 6'b001000;  aluop <= 2'b01; end // BEQ
			7'b1101111: begin controls <= 6'b100001;  aluop <= 2'b00; end // JAL
			default   : begin controls <= 6'b000000;  aluop <= 2'b00; end // illegal op - nop
		endcase
	end
endmodule : maindec

// aludec: generate all the alu control signals
module aludec(	input logic [2:0] funct3D, [6:0] funct7D,
				input logic [1:0] aluop,
				output logic [2:0] alucontrolD,
				output logic alu_subD  
			 );

	always_comb begin
		case(aluop)
			2'b00:   begin alucontrolD <= 3'b000;  alu_subD <= 1'b0; 	   end // add (for lw/sw/addi/J)
			2'b01:   begin alucontrolD <= 3'b000;  alu_subD <= 1'b1; 	   end // sub (for beq)
			default: begin alucontrolD <= funct3D; alu_subD <= funct7D[5]; end // R-type 
		endcase
	end
endmodule : aludec
/********************************************************************************/