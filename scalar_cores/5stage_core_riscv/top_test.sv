// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`define TOP_TEST
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
	logic dmem_req, imem_req;
	logic [3:0] dmem_mask;
	
	riscv_32i riscv_32i (
			.clk(clk), .reset(reset),
			
			// instruction mem interface signals
			.pc_imem(pc),
			.imem_req(imem_req),
			.imem_instn(instr),
			.Iwait(Iwait),

			// data mem interface signals 
			.dmem_we(memwrite),
			.dmem_addr(dataadr), .dmem_wd(writedata),
			.dmem_mask(dmem_mask),
			.dmem_req(dmem_req),
			.dmem_rd(readdata),
			.Dwait(Dwait)
	);

	mem_bus Bus();
	unified_L1_cache #(.RAM_SIZE(`L1_SIZE)) L1_cache (.Bus(Bus));
	imem imem(.a(pc), .rd(instr), .Imemaccess(imem_req), .Iwait(Iwait), .Bus(Bus));
	dmem dmem(	.clk(clk), .we(memwrite), .a(dataadr), 
				.wd(writedata), .dmem_mask(dmem_mask), .Dmemaccess(dmem_req),
				.rd(readdata), .Dwait(Dwait), .Bus(Bus)
	);
endmodule : top