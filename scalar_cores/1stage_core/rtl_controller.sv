// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define RTL_CONTROLLER
`include "defs_params_common.svh"
module controller	(	controller_if c_bus );

	logic [1:0] aluop;

	maindec maindec (	.c_bus(c_bus),
						.aluop(aluop)
	);
	aludec aludec 	(	.c_bus(c_bus),
						.aluop(aluop)
	);
	assign c_bus.pcsrc = c_bus.branch & c_bus.br_taken;

endmodule : controller

module maindec(	controller_if c_bus,
				output logic [1:0] aluop
);

	logic [8:0] controls;
	assign {c_bus.regwrite, c_bus.alusrc, c_bus.branch, c_bus.memwrite,
			c_bus.memtoreg, c_bus.jump, c_bus.jalr, c_bus.auipc, c_bus.lui} = controls;

	always_comb begin
		case(c_bus.op)
			7'b0110011: begin controls = 9'b100000000;   aluop = 2'b10; end // R-TYPE
			7'b0000011: begin controls = 9'b110010000;   aluop = 2'b00; end // I-TYPE LOAD
			7'b0100011: begin controls = 9'b010100000;   aluop = 2'b00; end // S-TYPE STORE
			7'b0010011: begin controls = 9'b110000000;   aluop = 2'b11; end // I-TYPE IMMEDIATE ARTHMETIC
			7'b1100011: begin controls = 9'b001000000;   aluop = 2'b01; end // B-TYPE CONDITIONAL BRANCH
			7'b1101111: begin controls = 9'b100001000;   aluop = 2'b00; end // J-TYPE UNCONDITIONAL JUMP AND LINK
			7'b1100111: begin controls = 9'b100000100;	 aluop = 2'b00; end // I-TYPE UNCODTIIONAL JUMP AND LINK REG
			7'b0010111: begin controls = 9'b100000010;   aluop = 2'b00; end // U-TYPE AUIPC (Add upper immediate to PC and store to reg)
			7'b0110111: begin controls = 9'b100000001;   aluop = 2'b00; end // U-TYPE LUI		(Load(set) upper immediate and store to reg)
			default   : begin controls = 9'b000000000;   aluop = 2'b00; end // illegal op - nop
		endcase
	end
endmodule : maindec

module aludec(
				controller_if c_bus,
				input logic [1:0] aluop
);

	always_comb
	case(aluop)
		2'b00:	begin c_bus.alucontrol = 3'b000; c_bus.alu_sub = 1'b0; end 	// add (for lw/sw/J)
		2'b01: 	begin c_bus.alucontrol = 3'b000; c_bus.alu_sub = 1'b1; end 	// sub (for beq) - this doesnt make sence now since branch is taken care by branch_compute
		2'b10: 	begin c_bus.alucontrol = c_bus.funct3; c_bus.alu_sub = c_bus.funct7[5]; end // R-type
		2'b11: 	begin 
					c_bus.alucontrol = c_bus.funct3; 
					if (c_bus.funct3 == 3'b101)
						c_bus.alu_sub = c_bus.funct7[5]; 
					else
						c_bus.alu_sub = 1'b0;
				end // Imm-arth
		default: begin c_bus.alucontrol = 3'b000; c_bus.alu_sub = 1'b0; end
	endcase
endmodule : aludec
