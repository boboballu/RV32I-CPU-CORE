// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

// controller
// input : 6' op - to identify instn
// input : 3' funct3 - as mentioned in risv isa
// input : 7' funct7 - as mentioned in riscv isa
// input : zero(from alu for beq)

module controller(	input logic [6:0] op, 
					input [2:0] funct3,
					input [6:0] funct7,
					input logic zero,
					output logic memtoreg, memwrite,
					output logic pcsrc, alusrc,
					output logic regdst, regwrite,
					output logic jump,
					output logic [2:0] alucontrol,
					output logic alu_sub
				 );

	logic [1:0] aluop;
	logic branch;

	maindec md(op, memtoreg, memwrite, branch, alusrc, regdst, regwrite, jump, aluop);
	aludec ad(funct3, funct7, aluop, alucontrol, alu_sub);
	assign pcsrc = branch & zero;

endmodule
 
module maindec(	input logic [6:0] op, // riscv - opcode
				output logic memtoreg, memwrite,
				output logic branch, alusrc,
				output logic regdst, regwrite,
				output logic jump,
				output logic [1:0] aluop
			  );

	logic [6:0] controls;
	assign {regwrite, regdst, alusrc, branch, memwrite, memtoreg, jump} = controls;
	always_comb begin
		case(op)
			7'b0110011: begin controls <= 7'b1100000;   aluop <= 2'b10; end // RTYPE
			7'b0000011: begin controls <= 7'b1010010;   aluop <= 2'b00; end // LW
			7'b0100011: begin controls <= 7'b0010100;   aluop <= 2'b00; end // SW
			7'b0010011: begin controls <= 7'b1010000;   aluop <= 2'b00; end // ADDI
			7'b1100011: begin controls <= 7'b0001000;   aluop <= 2'b01; end // BEQ
			7'b1101111: begin controls <= 7'b0000001;   aluop <= 2'b00; end // J
			default   : begin controls <= 7'bxxxxxxx;   aluop <= 2'bxx; end // illegal op
		endcase
	end
endmodule

module aludec(	
				input logic [2:0] funct3,
				input logic [6:0] funct7,
				input logic [1:0] aluop,
				output logic [2:0] alucontrol,
				output logic alu_sub
			 );

	always_comb
	case(aluop)
		2'b00: begin alucontrol <= 3'b000; alu_sub <= 1'b0; end // add (for lw/sw/addi/J)
		2'b01: begin alucontrol <= 3'b000; alu_sub <= 1'b1; end // sub (for beq)
		default: begin alucontrol <= funct3; alu_sub = funct7[5]; end // R-type 
	endcase
endmodule