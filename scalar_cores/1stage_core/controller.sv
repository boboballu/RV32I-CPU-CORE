// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

// controller
// input : 6' op - to identify instn
// input : 3' funct3 - as mentioned in risv isa
// input : 7' funct7 - as mentioned in riscv isa
// input : br_taken(from alu for beq)

module controller(	input logic [6:0] op, 
					input [2:0] funct3,
					input [6:0] funct7,
					input logic br_taken,
					output logic branch, jump, jalr,
					output logic memtoreg, memwrite,
					output logic pcsrc, alusrc,
					output logic regwrite,
					output logic [2:0] alucontrol,
					output logic alu_sub,
					output logic auipc, lui
				 );

	logic [1:0] aluop;

	maindec md(op, auipc, lui, memtoreg, memwrite, branch, alusrc, regwrite, jump, jalr, aluop);
	aludec ad(funct3, funct7, aluop, alucontrol, alu_sub);
	assign pcsrc = branch & br_taken;

endmodule
 
module maindec(	input logic [6:0] op, // riscv - opcode
				output logic auipc, lui,
				output logic memtoreg, memwrite,
				output logic branch, alusrc,
				output logic regwrite,
				output logic jump,
				output jalr,
				output logic [1:0] aluop
			  );

	logic [8:0] controls;
	assign {regwrite, alusrc, branch, memwrite, memtoreg, jump, jalr, auipc, lui} = controls;
	always_comb begin
		case(op)
			7'b0110011: begin controls <= 9'b100000000;   aluop <= 2'b10; end // RTYPE
			7'b0000011: begin controls <= 9'b110010000;   aluop <= 2'b00; end // LW
			7'b0100011: begin controls <= 9'b010100000;   aluop <= 2'b00; end // SW
			7'b0010011: begin controls <= 9'b110000000;   aluop <= 2'b00; end // ADDI
			7'b1100011: begin controls <= 9'b001000000;   aluop <= 2'b01; end // BEQ
			7'b1101111: begin controls <= 9'b100001000;   aluop <= 2'b00; end // J
			7'b1100111: begin controls <= 9'b100001100;	  aluop <= 2'b00; end // JALR
			7'b0010111: begin controls <= 9'b100000010;   aluop <= 2'b00; end // auipc
			7'b0110111: begin controls <= 9'b100000001;   aluop <= 2'b00; end // lui
			default   : begin controls <= 9'b000000000;   aluop <= 2'b00; end // illegal op - nop
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