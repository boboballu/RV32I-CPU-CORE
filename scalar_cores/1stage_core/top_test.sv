// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DBG
//`define verilator
import dbg_pkg::*; 

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic memwrite
			`ifdef DBG
			, output mem_debug dbg
			`endif
);

	logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	riscv_32i riscv_32i(.clk(clk), .reset(reset), 
						.pc(pc), .instr(instr), 
						.memwrite(memwrite), 
						.aluout(dataadr), .writedata(writedata), 
						.readdata(readdata)
						`ifdef DBG
						, .dbg(dbg)
						`endif
	);

	mem_bus Bus();
	imem imem(.a(pc), .rd(instr), .Bus(Bus));
	dmem dmem(.clk(clk), .we(memwrite), .a(dataadr), .wd(writedata), .rd(readdata), .Bus(Bus));
endmodule : top

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
	// commenting for verilator

	`ifndef verilator
	string EXEC;
	initial begin
		if ( !$value$plusargs("EXEC=%s", EXEC)) begin
	        $display("FATAL: +EXEC plusarg not found on command line");
	        $fatal;
	    end
	    $display("%m found +EXEC=%s", EXEC);
	end
	`endif

	// end comment
	
	bit [31:0] MEM [131071:0]; // 512 KB of memory

	// Imem part
	initial begin
		`ifdef verilator
		$readmemh("/root/Heterogeneous-multicore/scalar_cores/1stage_core/memfile.dat", MEM);
		`else
		/*commenting for verilator*/ $readmemh(EXEC, MEM);
		`endif
	end
	/* verilator lint_off WIDTH */
	assign Iinstn = MEM[Iaddr[31:2]];

	// Dmem part
	/* verilator lint_off WIDTH */
	assign Dreaddata = MEM[Daddr[31:2]];
	always_ff @(posedge clk) begin
		if (Dwe) MEM[Daddr[31:2]] <= Dwritedata;
	end

endinterface : mem_bus