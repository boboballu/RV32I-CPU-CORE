// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the controller has main and alu decoder 
// main decoder - for identifying instruction type
// alu decoder -  specifies alu finctionality for different opcode

// controller:
// inputs - instnD ([31:26]op & [5:0]funct); equalD - to determin pcsrcD
// pcsrcD and jumpD - change next PC (to the PC mux), flush IF_ID pipeline
// regwriteD - write EN for reg file
// memtoregD - for load instn
// memwriteD - for store instn
// regdstD 	 - destination selection mux (instn[15:11] for R-R instn type, instn[25:21] otherwise)
// alusrcD   - alu B source operand selection mux
// alucontrol- alu operation

module controller(	input logic [5:0] op, funct,
					input logic equalD,
					output logic pcsrcD, jumpD,
					output logic regwriteD,
					output logic memtoregD, memwriteD,
					output logic regdstD,
					output logic alusrcD,
					output logic [2:0] alucontrolD  );

	logic [1:0] aluop;
	logic branchD;

	maindec md(	.op(op), 
				.memtoregD(memtoregD), .memwriteD(memwriteD),
				.branchD(branchD), .alusrcD(alusrcD), 
				.regdstD(regdstD), .regwriteD(regwriteD), 
				.jumpD(jumpD), .aluop(aluop)  );

	aludec ad(	.funct(funct), 
				.aluop(aluop), 
				.alucontrolD(alucontrolD)  );
	assign pcsrcD = branchD & equalD;
endmodule : controller

// maindec: generate all the control signals
module maindec(	input logic [5:0] op,
				output logic memtoregD, memwriteD,
				output logic branchD, alusrcD,
				output logic regdstD, regwriteD,
				output logic jumpD,
				output logic [1:0] aluop  );

	logic [8:0] controls;
	assign {regwriteD, regdstD, alusrcD, branchD, memwriteD, memtoregD, jumpD, aluop} = controls;
	always_comb begin
		case(op)
			6'b000000: controls <= 9'b110000010; // RTYPE
			6'b100011: controls <= 9'b101001000; // LW
			6'b101011: controls <= 9'b001010000; // SW
			6'b000100: controls <= 9'b000100001; // BEQ
			6'b001000: controls <= 9'b101000000; // ADDI
			6'b000010: controls <= 9'b000000100; // J
			default: controls <= 9'bxxxxxxxxx; // illegal op
		endcase
	end
endmodule : maindec

// aludec: generate all the alu control signals
module aludec(	input logic [5:0] funct,
				input logic [1:0] aluop,
				output logic [2:0] alucontrolD  );
	always_comb
	case(aluop)
		2'b00: alucontrolD <= 3'b010; // add (for lw/sw/addi)
		2'b01: alucontrolD <= 3'b110; // sub (for beq)
		default: case(funct) // R-type instructions
					6'b100000: alucontrolD <= 3'b010; // add
					6'b100010: alucontrolD <= 3'b110; // sub
					6'b100100: alucontrolD <= 3'b000; // and
					6'b100101: alucontrolD <= 3'b001; // or
					6'b101010: alucontrolD <= 3'b111; // slt
					default: alucontrolD <= 3'bxxx; // ???
				endcase
	endcase
endmodule : aludec
/********************************************************************************/