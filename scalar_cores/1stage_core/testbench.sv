// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DBG
import dbg_pkg::*; 

module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic memwrite;

	// mem check variables filled from command line args
	integer D_cache_address, D_cache_data;
	
	// debug variable
	`ifdef DBG
	mem_debug dbg;
	`endif	
	// instantiate device to be tested
	top dut (.clk(clk), .reset(reset), 
			.writedata(writedata), .dataadr(dataadr), 
			.memwrite(memwrite)
			`ifdef DBG
			, .dbg(dbg)
			`endif
			);
	
	// initialize test
	initial begin
		if ( !$value$plusargs("D_cache_address=%d", D_cache_address)) begin
	        $display("FATAL: +D_cache_address plusarg not found on command line");
	        $fatal;
	    end
	    if ( !$value$plusargs("D_cache_data=%d", D_cache_data)) begin
	        $display("FATAL: +D_cache_data plusarg not found on command line");
	        $fatal;
	    end
	    $display("%m found +D_cache_address=%d", D_cache_address);
	   	$display("%m found +D_cache_data=%d", D_cache_data);

		#20000 
		$display (); $display ();
		$stop;
	end

/********************************************************************************/
	// reset generator
	initial begin
		reset <= 1; # 22; reset <= 0;
		$display (); $display ();
		$display ("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==", 4000);
		$display (); $display ();
	end	
	// generate clock to sequence tests
	always begin
		clk <= 1; # 5; clk <= 0; # 5;
	end
	
/********************************************************************************/

	// check results
	always @(negedge clk) begin
		// if (!reset) begin
		// 	if ((dbg.instn_type_str[dbg.op] != "illegal") && (dbg.instn_type_str[dbg.op] != "J") && (dbg.pc != 'hc)) begin
		// 		$write ("%t; pc: %d; op: %s; rd :%d; rs1: %d; rs2: %d;\n", $time, dbg.pc, dbg.instn_type_str[dbg.op], dbg.rd, dbg.rs1, dbg.rs2);
		// 	end
		// end
		// if (dbg.instn_type_str[dbg.op] == "LW") begin
		// 	$display("%t load-> addr: %d; regwrite %b; result :%08x", $time, dataadr, dbg.regwrite, dbg.result);
		// end

		// if (memwrite) begin
		// 	$display ("%t: dataadr: %d  writedata: %x", $time, dataadr, signed'(writedata));
		// 	if (dataadr===D_cache_address) begin
		// 		if (writedata===D_cache_data) begin
		// 			$display("Simulation succeeded");
		// 		end
		// 		else begin
		// 			$display("Simulation stops when sw at mem[84] is encountered");
		// 			//$stop;
		// 		end
		// 	end
		// end
		if (memwrite) begin
			if (dataadr == 65532) begin
				$write("%c", writedata);
			end
		end


	end

	// final begin
	// 	$display ();
	// 	$display ();
	// end

endmodule : testbench

/********************************************************************************/