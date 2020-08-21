// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`include "debug_headerfile.svh"
import dbg_pkg::*;

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite
);
	// logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	// riscv_32i riscv_32i(clk, reset, pc, instr, memwrite, dataadr, writedata, readdata);
	logic Iwait, Dwait;
	logic memaccessM;
	
	riscv_32i riscv_32i (.clk(clk), .reset(reset),
			.pc_imem(pc),
			.imem_instn(instr),
			.dmem_we(memwrite),
			.dmem_addr(dataadr), .dmem_wd(writedata),
			.memaccessM(memaccessM),
			.dmem_rd(readdata),
			.Iwait(Iwait), .Dwait(Dwait)
	);

	mem_bus Bus();
	unified_L1_cache L1_cache (.Bus(Bus));
	imem imem(.a(pc), .rd(instr), .Iwait(Iwait), .Bus(Bus));
	dmem dmem(	.clk(clk), .we(memwrite), .a(dataadr), 
				.wd(writedata), .Dmemaccess(memaccessM),
				.rd(readdata), .Dwait(Dwait), .Bus(Bus)
	);
endmodule : top