// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define CORE_TOP
`include "debug_headerfile.svh"
import dbg_pkg::*; 
module riscv_32i(input logic clk, reset,
			output logic [31:0] pc,
			input logic [31:0] instr,
			output logic memwrite,
			output logic [31:0] aluout, writedata,
			input logic [31:0] readdata
			`ifdef MEM_DEBUG
			, output mem_debug dbg
			`endif
);
	
	`ifdef MEM_DEBUG
	logic [31:0] result;
	`endif

	assign memwrite = c_bus.memwrite;
/********************************************************************************/
	`ifdef MEM_DEBUG
	assign dbg.pc 	 = pc;
	assign dbg.op 	 = c_bus.instr[6:0];
	assign dbg.rs1 	 = c_bus.instr[19:15];
	assign dbg.rs2   = c_bus.instr[24:20];
	assign dbg.rd    = c_bus.instr[11:7];

	assign dbg.result= result;

	assign dbg.dmem_we   = c_bus.memwrite;
	assign dbg.dmem_addr = aluout;
	assign dbg.dmem_wd   = writedata;
	assign dbg.dmem_rd   = readdata;

	assign dbg.alusrc   = c_bus.alusrc;
	assign dbg.regwrite = c_bus.regwrite;
	assign dbg.memtoreg = c_bus.memtoreg;
	`endif
/********************************************************************************/	
	controller_if c_bus(.instr(instr));
	controller controller( 	.c_bus(c_bus.ctrl) 	);
	datapath datapath	(	.clk(clk), .reset(reset), 
							.c_bus(c_bus.dp), 
							.pc(pc), 
							.aluout(aluout), .writedata(writedata), 
							.readdata(readdata)
							`ifdef MEM_DEBUG
							,.result(result)
							`endif
	);

endmodule : riscv_32i
