// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// master (golden) testbench, checking all the features (uses adHoc testing)
// master testbench updated (15/7/2020)- mimics terminal by dumping writes to the address 'd65532
int term_address = 65532;
`include "debug_headerfile.svh"
import dbg_pkg::*;

module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic [31:0] readdata, pc, instr;
	logic memwrite;
	mem_debug debug;
	int instn_cycle = 1;

	// mem check variables filled from command line args
	int D_cache_address, D_cache_data;
	// instantiate device to be tested
	top dut (.clk(clk), .reset(reset), 
			.writedata(writedata), .dataadr(dataadr),
            .readdata(readdata), .pc(pc), .instr(instr), 
			.memwrite(memwrite)
			`ifdef mem_debug
			, .debug(debug)
			`endif
	);
	// initialize test
	initial begin
		if ( !$value$plusargs("D_cache_address=%d", D_cache_address)) begin
	        $display("WARN: +D_cache_address plusarg not found on command line");
	    end
	    if ( !$value$plusargs("D_cache_data=%d", D_cache_data)) begin
	        $display("WARN: +D_cache_data plusarg not found on command line");
	    end
	    $display("%m found +D_cache_address=%d", D_cache_address);
	   	$display("%m found +D_cache_data=%d", D_cache_data);

		#20000;
		// terminal footer
		$display (); $display ();
		$stop;
	end

/********************************************************************************/
	// reset generation / terminal header
	initial begin
		reset <= 1; # 22; reset <= 0;
		$display (); $display ();
		$display ("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==", term_address);
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
		// 	if (memwrite) begin
		// 		$display ("instn_cycle : %d pc %x store : dataadr: %d writedata: %x", instn_cycle, pc, dataadr, $signed(writedata));
		// 		if (dataadr===D_cache_address & $signed(writedata)===D_cache_data) begin
		// 			$display("Simulation succeeded");
		// 			$stop;
		// 		end
		// 	end
		// 	`ifdef mem_debug
		// 	else if (debug.regwriteM) begin
		// 		if (debug.memtoregM) begin
		// 			$display ("instn_cycle : %d pc %x load : dataadr: %d readdata: %x", instn_cycle, pc, dataadr, $signed(readdata));
		// 		end
		// 		else begin
		// 			if (debug.dmem_addr === 32'bx) begin
		// 				$display ("instn_cycle : %d pc %x nop/squashed instn-taken branch: data: %d", instn_cycle, pc, dataadr);
		// 			end
		// 			else begin
		// 				$display ("instn_cycle : %d pc %x ALU/Addi : data: %d", instn_cycle, pc, dataadr);
		// 			end
		// 		end		
		// 	end

	    //     else begin
		// 		if (dataadr === 0)
	    //         	$display ("instn_cycle : %d pc %x bubble/branch : data: %d", instn_cycle, pc, dataadr);
		// 		else 
	    //         	$display ("instn_cycle : %d pc %x branch : data: %d", instn_cycle, pc, dataadr);
	    //     end
		// 	`endif
		// 	instn_cycle++;
		// end

		if (memwrite) begin
			if (dataadr == term_address) begin
				$write("%d", writedata);
			end
		end
	end
endmodule : testbench