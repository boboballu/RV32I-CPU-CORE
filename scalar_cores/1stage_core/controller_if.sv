// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define CONTROLLER_IF
`include "debug_headerfile.svh"
interface controller_if (input [31:0] instr);
	//logic [31:0] instr;
	logic [6:0] op; logic  [2:0] funct3; logic [6:0] funct7;
	logic br_taken; logic branch, jump, jalr;
	logic memtoreg, memwrite;
	logic pcsrc, alusrc;
	logic regwrite;
	logic [2:0] alucontrol; logic alu_sub;
	logic auipc, lui;


	// controller
	// input : 6' op - to identify instn
	// input : 3' funct3 - as mentioned in risv isa
	// input : 7' funct7 - as mentioned in riscv isa
	// input : br_taken(from alu for beq)

	assign op 	  = instr[6:0];
	assign funct3 = instr[14:12];
	assign funct7 = instr[31:25];

	modport ctrl(	input instr,
					input br_taken, op, funct3, funct7,
					output branch, jump, jalr,
					memtoreg, memwrite, pcsrc, alusrc, regwrite,
					alucontrol, alu_sub, auipc, lui
	);
	modport dp 	( 	input instr,
					output br_taken, op, funct3, funct7,
					input branch, jump, jalr,
					memtoreg, memwrite, pcsrc, alusrc, regwrite,
					alucontrol, alu_sub, auipc, lui
	);
endinterface : controller_if
