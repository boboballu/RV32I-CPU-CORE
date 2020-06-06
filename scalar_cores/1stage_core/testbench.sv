// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
module testbench();
	logic clk;
	logic reset;
	logic [31:0] writedata, dataadr;
	logic memwrite;

	// instantiate device to be tested
	top dut (.clk(clk), .reset(reset), 
			.writedata(writedata), .dataadr(dataadr), 
			.memwrite(memwrite)
			);
	
	// initialize test
	initial begin
		reset <= 1; # 22; reset <= 0;
	end
	
	// generate clock to sequence tests
	always begin
		clk <= 1; # 5; clk <= 0; # 5;
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

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic memwrite
			);

	logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	riscv_32i riscv_32i(clk, reset, pc, instr, memwrite, dataadr, writedata, readdata);
	imem imem(pc[7:2], instr);
	dmem dmem(clk, memwrite, dataadr, writedata, readdata);
endmodule

module dmem(input logic clk, we,
			input logic [31:0] a, wd,
			output logic [31:0] rd);

	logic [31:0] RAM[63:0];
	assign rd = RAM[a[31:2]]; // word aligned
	always_ff @(posedge clk) begin
		if (we) RAM[a[31:2]] <= wd;
	end
endmodule

module imem(input logic [5:0] a,
			output logic [31:0] rd);

	logic [31:0] RAM[63:0];
	initial begin
		$readmemb("./memfile.dat", RAM);
	end
	assign rd = RAM[a]; // word aligned
endmodule