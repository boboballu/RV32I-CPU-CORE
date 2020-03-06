// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// master (golden) testbench, checking all the features (uses adHoc testing)

module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic [31:0] readdata, pc, instr;
	logic memwrite;
	// instantiate device to be tested
	top dut (.clk(clk), .reset(reset), 
			.writedata(writedata), .dataadr(dataadr),
            .readdata(readdata), .pc(pc), .instr(instr), 
			.memwrite(memwrite));
	// initialize test
	initial begin
		reset <= 1; # 22; reset <= 0;
		#1000;
		$stop;
	end
	// generate clock to sequence tests
	always begin
		clk <= 0; # 5; clk <= 0; # 5;
	end
	// check results
	always @(negedge clk) begin
		if (memwrite) begin
			$display ("dataadr: %d  writedata: %d", dataadr, writedata);
			if (dataadr===84 & writedata===7) begin
				$display("Simulation succeeded");
				$stop;
			end 
			else if (dataadr !==80) begin
				$display("Simulation failed");
				$stop;
			end
		end
	end
endmodule