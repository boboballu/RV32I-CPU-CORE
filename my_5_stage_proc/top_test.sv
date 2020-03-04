// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
module top(input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite);
	// logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	// mips mips(clk, reset, pc, instr, memwrite, dataadr, writedata, readdata);
	mips mips (.clk(clk), .reset(reset),
			.pc_imem(pc),
			.imem_instn(instr),
			.dmem_we(memwrite),
			.dmem_addr(dataadr), .dmem_wd(writedata),
			.dmem_rd(readdata) 	);
	imem imem(.a(pc[31:2]), .rd(instr));
	dmem dmem(.clk(clk), .we(memwrite), .a(dataadr), .wd(writedata), .rd(readdata));
endmodule

module dmem(input logic clk, we,
			input logic [31:0] a, wd,
			output logic [31:0] rd);
	bit [31:0] RAM[63:0];
	assign rd = RAM[a[31:2]]; // word aligned
	always_ff @(posedge clk) begin
		if (we) RAM[a[31:2]] <= wd;
	end
endmodule

module imem(input logic [29:0] a,
			output logic [31:0] rd);
	bit [1023:0] RAM[63:0];
	initial begin
		$readmemh("./assembler/testcase1", RAM);
	end
	assign rd = RAM[a]; // word aligned
endmodule