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
			output logic memaccess,
			input logic [31:0] readdata,
			input logic Iwait, Dwait
);

	assign memwrite = c_bus.memwrite;

/********************************************************************************/
	controller_if c_bus(.instr(instr));
	controller controller( 	.c_bus(c_bus.ctrl) 	);
	datapath datapath	(	.clk(clk), .reset(reset),
							.c_bus(c_bus.dp),
							.pc(pc),
							.aluout(aluout), .writedata(writedata),
							.readdata(readdata),
							.memaccess(memaccess),
							.Iwait(Iwait), .Dwait(Dwait)
	);

endmodule : riscv_32i
