// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// master (golden) testbench, checking all the features (uses adHoc testing)
`include "debug_headerfile.sv"
import dbg_pkg::*;

module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic [31:0] readdata, pc, instr;
	logic memwrite;
	mem_debug debug;
	integer instn_cycle = 1;
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
		reset <= 1; # 22; reset <= 0;
		#400;
		$stop;
	end
	// generate clock to sequence tests
	always begin
		clk <= 1; # 5; clk <= 0; # 5;
	end
	// check results
	always @(negedge clk) begin
		if (!reset) begin
			if (memwrite) begin
				$display ("instn_cycle : %d pc %x store : dataadr: %d writedata: %d", instn_cycle, pc, dataadr, $signed(writedata));
				if (dataadr===84 & $signed(writedata)===7) begin
					$display("Simulation succeeded");
					$stop;
				end 
			end
			`ifdef mem_debug
			else if (debug.regwriteM) begin
				if (debug.memtoregM) begin
					$display ("instn_cycle : %d pc %x load : dataadr: %d readdata: %d", instn_cycle, pc, dataadr, $signed(readdata));
				end
				else begin
					if (debug.dmem_addr === 32'bx) begin
						$display ("instn_cycle : %d pc %x nop/squashed instn-taken branch: data: %d", instn_cycle, pc, dataadr);
					end
					else begin
						$display ("instn_cycle : %d pc %x ALU/Addi : data: %d", instn_cycle, pc, dataadr);
					end
				end		
			end

	        else begin
				if (dataadr === 0)
	            	$display ("instn_cycle : %d pc %x bubble/branch : data: %d", instn_cycle, pc, dataadr);
				else 
	            	$display ("instn_cycle : %d pc %x branch : data: %d", instn_cycle, pc, dataadr);
	        end
			`endif
			instn_cycle++;
		end
	end
endmodule