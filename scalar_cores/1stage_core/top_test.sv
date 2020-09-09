// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define TOP_TEST
`include "debug_headerfile.svh"
import dbg_pkg::*;

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite
);

	logic Iwait, Dwait, memaccess;
	// instantiate processor and memories
	riscv_32i riscv_32i(.clk(clk), .reset(reset),
						.pc(pc), .instr(instr),
						.memwrite(memwrite),
						.aluout(dataadr), .writedata(writedata),
						.memaccess(memaccess),
						.readdata(readdata),
						.Iwait(Iwait), .Dwait(Dwait)
	);

	mem_bus Bus();
	unified_L1_cache L1_cache (.Bus(Bus));
	imem imem(.a(pc), .rd(instr), .Iwait(Iwait), .Bus(Bus));
	dmem dmem(	.clk(clk), .we(memwrite), .a(dataadr), 
				.wd(writedata), .Dmemaccess(memaccess),
				.rd(readdata), .Dwait(Dwait), .Bus(Bus)
	);
endmodule : top