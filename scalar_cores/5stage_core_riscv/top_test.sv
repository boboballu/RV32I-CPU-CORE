// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`include "debug_headerfile.svh"
import dbg_pkg::*;

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite
);
	// logic [31:0] pc, instr, readdata;
	// instantiate processor and memories
	// riscv_32i riscv_32i(clk, reset, pc, instr, memwrite, dataadr, writedata, readdata);
	logic Iwait, Dwait;
	logic memaccessM;
	
	riscv_32i riscv_32i (.clk(clk), .reset(reset),
			.pc_imem(pc),
			.imem_instn(instr),
			.dmem_we(memwrite),
			.dmem_addr(dataadr), .dmem_wd(writedata),
			.memaccessM(memaccessM),
			.dmem_rd(readdata),
			.Iwait(Iwait), .Dwait(Dwait)
	);

	mem_bus Bus();
	imem imem(.a(pc), .rd(instr), .Iwait(Iwait), .Bus(Bus));
	dmem dmem(	.clk(clk), .we(memwrite), .a(dataadr), 
				.wd(writedata), .Dmemaccess(memaccessM),
				.rd(readdata), .Dwait(Dwait), .Bus(Bus)
	);
endmodule : top

/********************************************************************************/
// unified L1 Instn and Data memory defined in mem_bus interface
// imem & dmem connects to the mem_bus and CPU 
module dmem(input logic clk, we,
			input logic [31:0] a, wd,
			input logic Dmemaccess,
			output logic [31:0] rd,
			output logic Dwait,
			mem_bus Bus
);

	assign Bus.clk 			= clk;
	assign Bus.Daddr 		= a;
	assign Bus.Dwe 			= we;
	assign Bus.Dwritedata 	= wd;
	assign rd 				= Bus.Dreaddata;
	assign Dwait 			= Bus.Dwait;
	assign Bus.Dmemaccess	= Dmemaccess;

endmodule : dmem

module imem(input logic [31:0] a,
			output logic [31:0] rd,
			output logic Iwait,
			mem_bus Bus
);
	assign Bus.Iaddr 		= a;
	assign rd  				= Bus.Iinstn;
	assign Iwait			= Bus.Iwait;	
endmodule : imem

interface mem_bus;
	logic clk;
	logic [31:0] Iaddr, Iinstn;
	logic [31:0] Daddr, Dreaddata, Dwritedata;
	logic Dwe; 
	logic Dwait, Iwait;
	logic Dmemaccess;

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
	assign Dreaddata = Dmemaccess ? MEM[Daddr[31:2]] : 'b0;
	always_ff @(posedge clk) begin
		if (Dwe) MEM[Daddr[31:2]] <= Dwritedata;
	end

	// wait logic
	// Data wait simulation logic: if Daddr[3:2] is 2'b11 then wait is set
	// mealy state-machine implementation for Dwait
	assign Iwait = 0;

	parameter s0=2'd0, s1=2'd1, s2=2'd2;
	reg [1:0] cur_state, next_state;
	
	always_ff@(posedge clk) begin
		cur_state <= next_state;
	end
	
	always_comb begin
		case(cur_state)
			s0: begin
					if (Daddr[3:2] ==2'b11) begin
						Dwait = 1;
						next_state = s1;
					end
					else begin
						Dwait = 0;
						next_state = s0;
					end
				end
			s1: begin
					Dwait = 1;
					next_state = s2;
				end
			s2: begin
					Dwait = 0;
					next_state = s0;
				end
			default: begin
						next_state = s0;
						Dwait = 0;
					end
		endcase
	end

endinterface : mem_bus

/********************************************************************************/