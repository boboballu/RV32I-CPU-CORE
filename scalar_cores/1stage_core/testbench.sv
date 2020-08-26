// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define TESTBENCH
`include "debug_headerfile.svh"
import dbg_pkg::*; 

module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic memwrite;

	// mem check variables filled from command line args
	integer D_cache_address, D_cache_data;
	
	// debug variable
	`ifdef MEM_DEBUG
	mem_debug dbg;
	`endif	
	// instantiate device to be tested
	top dut (.clk(clk), .reset(reset), 
			.writedata(writedata), .dataadr(dataadr), 
			.memwrite(memwrite)
			`ifdef MEM_DEBUG
			, .dbg(dbg)
			`endif
	);
	
	// dump var for gtkwave
	`ifdef DUMP_VCD
	 initial begin
		$dumpfile("dumpwave.vcd")
		$dumpvars(0, testbench);
	end
	`endif

	// initialize test
	initial begin
		#EXE_TIME
		// console trailer
		$display (); $display ();
		$stop;
	end

/********************************************************************************/
	// reset generator
	initial begin
		reset <= 0; # 22; reset <= 1;
		$display (); $display ();
		$display ("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==", 65532);
		$display (); $display ();
	end	
	// generate clock to sequence tests
	always begin
		clk <= 1; # 5; clk <= 0; # 5;
	end
	
/********************************************************************************/
	// check results
`ifdef MEM_DEBUG
	always @(negedge clk) begin
		if (reset) begin
			if ((dbg.instn_type_str[dbg.op] != "illegal") && (dbg.instn_type_str[dbg.op] != "J") && (dbg.pc != 'hc)) begin
				$write ("%t; pc: %d; op: %s; rd :%d; rs1: %d; rs2: %d;\n", $time, dbg.pc, dbg.instn_type_str[dbg.op], dbg.rd, dbg.rs1, dbg.rs2);
			end
		end
		if (dbg.instn_type_str[dbg.op] == "LW") begin
			$display("%t load-> addr: %d; regwrite %b; result :%08x", $time, dataadr, dbg.regwrite, dbg.result);
		end

		if (memwrite) begin
			$display ("%t: dataadr: %d  writedata: %x", $time, dataadr, signed'(writedata));
			if (dataadr===D_cache_address) begin
				if (writedata===D_cache_data) begin
					$display("Simulation succeeded");
				end
				else begin
					$display("Simulation stops when sw at mem[%d] encountered", D_cache_address);
				end
			end
		end
		if (memwrite) begin
			if (dataadr == CONSOLE_ADDR) begin
				$write("%d", writedata);
			end
		end
	end

`else
/********************************************************************************/
	always @(reset, memwrite, dataadr) begin
		if (memwrite) begin
			//$display("here : %d", dataadr);
			if (dataadr == CONSOLE_ADDR) begin
				$write(CONSOLE_FORMAT, writedata);
			end
		end
	end
`endif
endmodule : testbench

/********************************************************************************/
