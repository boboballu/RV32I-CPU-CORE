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
	
	logic memtoreg, alusrc, regdst;
	logic regwrite, jump, pcsrc, zero;
	logic [2:0] alucontrol; logic alu_sub;
	
	controller controller(.op(instr[6:0]), 
				.funct3(instr[14:12]), 
				.funct7(instr[31:25]), 
				.zero(zero), 
				.memtoreg(memtoreg), .memwrite(memwrite), 
				.pcsrc(pcsrc), .alusrc(alusrc), 
				.regdst(regdst), .regwrite(regwrite), 
				.jump(jump), 
				.alucontrol(alucontrol), 
				.alu_sub(alu_sub)
				);

	datapath datapath(.clk(clk), .reset(reset), 
				.memwrite(memwrite), 
				.memtoreg(memtoreg), .pcsrc(pcsrc), 
				.alusrc(alusrc), .regdst(regdst), 
				.regwrite(regwrite), .jump(jump), 
				.alucontrol(alucontrol), .alu_sub(alu_sub), 
				.zero(zero), 
				.pc(pc), 
				.instr(instr), 
				.aluout(aluout), .writedata(writedata), 
				.readdata(readdata)	
				);

endmodule
