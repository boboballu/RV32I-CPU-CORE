// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module riscv_32i(input logic clk, reset,
			output logic [31:0] pc,
			input logic [31:0] instr,
			output logic memwrite,
			output logic [31:0] aluout, writedata,
			input logic [31:0] readdata);
	
	logic memtoreg, alusrc;
	logic regwrite; 
	logic branch, jump, jalr, pcsrc, br_taken;
	logic [2:0] alucontrol; logic alu_sub;
	logic auipc, lui;
	
	controller controller(.op(instr[6:0]), 
				.funct3(instr[14:12]), 
				.funct7(instr[31:25]), 
				.br_taken(br_taken), 
				.branch(branch), .jump(jump), .jalr(jalr),
				.memtoreg(memtoreg), .memwrite(memwrite), 
				.pcsrc(pcsrc), .alusrc(alusrc), 
				.regwrite(regwrite), 
				.alucontrol(alucontrol), 
				.alu_sub(alu_sub),
				.auipc(auipc), .lui(lui)
				);

	datapath datapath(.clk(clk), .reset(reset), 
				.auipc(auipc), .lui(lui),
				.memwrite(memwrite), 
				.memtoreg(memtoreg), .pcsrc(pcsrc), 
				.alusrc(alusrc),
				.regwrite(regwrite), .jump(jump), .branch(branch), .jalr(jalr),
				.alucontrol(alucontrol), .alu_sub(alu_sub), 
				.br_taken(br_taken), 
				.pc(pc), 
				.instr(instr), 
				.aluout(aluout), .writedata(writedata), 
				.readdata(readdata)
				);

endmodule
