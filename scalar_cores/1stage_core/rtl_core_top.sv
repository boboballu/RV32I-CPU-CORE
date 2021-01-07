
// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define RTL_CORE_TOP
`include "defs_params_common.svh"
import dbg_pkg::*;
module riscv_32i(input logic clk, reset,

			// instruction mem interface signals
			output logic [31:0] imem_pc_addr,
			output logic imem_req,
			input logic [31:0] imem_instn,
			input logic imem_wait,

			// data mem interface signals
			output logic dmem_we,
			output logic [31:0] dmem_addr, dmem_wd,
			output logic [3:0] dmem_mask,
			output logic dmem_req,
			input logic [31:0] dmem_rd,
			input logic dmem_wait
);

	assign dmem_we = c_bus.memwrite;
	assign imem_req = 1;
/********************************************************************************/
	controller_if c_bus(.instr(imem_instn));
	controller controller( 	.c_bus(c_bus.ctrl) 	);
	datapath datapath	(	.clk(clk), .reset(reset),
							.c_bus(c_bus.dp),
							.pc(imem_pc_addr),
							.aluout(dmem_addr), .writedata(dmem_wd),
							.readdata(dmem_rd),
							.dmem_mask(dmem_mask),
							.memaccess(dmem_req),
							.Iwait(imem_wait), .Dwait(dmem_wait)
	);

endmodule : riscv_32i
