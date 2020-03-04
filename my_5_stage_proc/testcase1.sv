// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// testbench for testcase1 - all alu instns, load , store (branch and jump not tested)
/****important*****change imem file path to ./assembler/testcase1 in top_test.sv*/
module testcase1();
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
        #400;
        $stop;
	end
	// generate clock to sequence tests
	always begin
		clk <= 1; # 5; clk <= 0; # 5;
	end
	// check results
	always @(negedge clk) begin
		if (memwrite) begin
			$display ("pc: %d store : dataadr: %d  writedata: %d", pc, dataadr, $signed(writedata));
			if (dataadr===116 & writedata===6) begin
				$display("Simulation succeeded");
				$stop;
			end
		end
        else begin
            $display ("pc %d load : dataadr: %d  readdata: %d", pc, dataadr, $signed(readdata));
        end
	end
endmodule