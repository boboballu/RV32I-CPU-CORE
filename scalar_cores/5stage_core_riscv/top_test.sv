// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`include "debug_headerfile.svh"
import dbg_pkg::*;

module top(input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite
			`ifdef mem_debug
			, output mem_debug debug
			`endif
);
	// logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	// riscv_32i riscv_32i(clk, reset, pc, instr, memwrite, dataadr, writedata, readdata);
	riscv_32i riscv_32i (.clk(clk), .reset(reset),
			.pc_imem(pc),
			.imem_instn(instr),
			.dmem_we(memwrite),
			.dmem_addr(dataadr), .dmem_wd(writedata),
			.dmem_rd(readdata)
			`ifdef mem_debug
			, .debug(debug)
			`endif
	);
		mem_bus Bus();
		imem imem(.a(pc), .rd(instr), .Bus(Bus));
		dmem dmem(.clk(clk), .we(memwrite), .a(dataadr), .wd(writedata), .rd(readdata), .Bus(Bus));
endmodule : top

/********************************************************************************/
// unified L1 Instn and Data memory defined in mem_bus interface
// imem & dmem connects to the mem_bus and CPU 
module dmem(input logic clk, we,
			input logic [31:0] a, wd,
			output logic [31:0] rd,
			mem_bus Bus
);
	
	assign Bus.clk = clk;
	assign Bus.Daddr = a;
	assign Bus.Dwe = we;
	assign Bus.Dwritedata = wd;
	assign rd = Bus.Dreaddata;

endmodule : dmem

module imem(input logic [31:0] a,
			output logic [31:0] rd,
			mem_bus Bus
);
	assign Bus.Iaddr = a;
	assign rd  = Bus.Iinstn;	
endmodule : imem

interface mem_bus;
	logic clk;
	logic [31:0] Iaddr, Iinstn;
	logic [31:0] Daddr, Dreaddata, Dwritedata;
	logic Dwe;
	
	// get the binary file from commandline args
	string EXEC;
	initial begin
		if ( !$value$plusargs("EXEC=%s", EXEC)) begin
	        $display("FATAL: +EXEC plusarg not found on command line");
	        $fatal;
	    end
	    $display("%m found +EXEC=%s", EXEC);
	end

	bit [31:0] MEM [131071:0]; // 512 KB of memory

	// Imem part
	initial begin
		$readmemh(EXEC, MEM);
	end
	assign Iinstn = MEM[Iaddr[31:2]];

	// Dmem part
	assign Dreaddata = MEM[Daddr[31:2]];
	always_ff @(posedge clk) begin
		if (Dwe) MEM[Daddr[31:2]] <= Dwritedata;
	end

endinterface : mem_bus

/********************************************************************************/
