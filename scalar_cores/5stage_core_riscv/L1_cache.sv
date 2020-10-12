// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// L1 unified instruction and Data cache
// mem_bus interface    - defines the interface between core and L1 cache
// Imem and Dmem modules- modules that are interfaced with the core
// unified_l1_cache     - L1 cache module; 2 ported memory module
// mem_wait_data        - model for L1 cache miss
/********************************************************************************/
// unified L1 Instn and Data cache : interface
`define L1_CACHE
`include "debug_headerfile.svh"
import dbg_pkg::*;

interface mem_bus;
	logic clk;
	logic [31:0] Iaddr, Iinstn;
	logic [31:0] Daddr, Dreaddata, Dwritedata;
	logic Dwe;
	logic Dwait, Iwait;
	logic Dmemaccess;

	modport Imem (	input Iinstn, Iwait,

					output Iaddr
	);

	modport Dmem (	input Dreaddata, Dwait,

					output clk,

					output Daddr, Dwe, Dwritedata, Dmemaccess
	);

	modport L1_cache (
					input clk,

					input Iaddr, Daddr, Dwe, Dwritedata, Dmemaccess,

					output Iinstn, Dreaddata, Iwait, Dwait
	);
endinterface : mem_bus

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

module unified_L1_cache (mem_bus Bus);
	parameter RAM_SIZE = 65536;
	// get the binary file from commandline args
	string EXEC;
	initial begin
		if ( !$value$plusargs("EXEC=%s", EXEC)) begin
	        $display("FATAL: +EXEC plusarg not found on command line");
	        $fatal;
	    end
	    $display("%m found +EXEC=%s", EXEC);
	end

	// unified Instn and Data memory
	bit [31:0] MEM [RAM_SIZE-1:0]; // 256 KB of memory

	// Imem read memory
	initial begin
		`ifdef MEM_BINARY
		$readmemb(EXEC, MEM);
		`else
		$readmemh(EXEC, MEM);
		`endif
	end
	assign Bus.Iinstn = MEM[Bus.Iaddr[31:2]];

	// Dmem read and write implementation
	assign Bus.Dreaddata = Bus.Dmemaccess ? MEM[Bus.Daddr[31:2]] : 'b0;
	always_ff @(posedge Bus.clk) begin
		if (Bus.Dwe) MEM[Bus.Daddr[31:2]] <= Bus.Dwritedata;
	end

	`ifdef IWAIT
	// not using the state-machine wait - which is an over thought implementation; completely unnecessary
	// mem_wait_data #( .LSB_BITS(2'b11) ) waitI (.clk(Bus.clk), .addr(Bus.Iaddr), .wait_data(Bus.Iwait));
	always @(posedge Bus.clk) begin
		if ($urandom_range(0, 7) == 7)
			Bus.Iwait = 1;
		else
			Bus.Iwait = 0;
	end
	`else
	assign Bus.Iwait = 0;
	`endif

	`ifdef DWAIT
	// not using the state-machine wait - which is an over thought implementation; completely unnecessary
	// mem_wait_data #( .LSB_BITS(2'b11) ) waitD (.clk(Bus.clk), .addr(Bus.Daddr), .wait_data(Bus.Dwait));
	always @(posedge Bus.clk) begin
		if ($urandom_range(0, 7) == 7)
			Bus.Dwait = 1;
		else
			Bus.Dwait = 0;
	end
	`else
	assign Bus.Dwait = 0;
	`endif

endmodule : unified_L1_cache

/********************************************************************************/
// An over thought cache miss model - unnecessary as of today : 10/11/2020
// A Mealey State-machine model, which adds wait for mem access to location whose 2 LSB bits are '11
// if addr[3:2] is 2'b11 then wait is set
module mem_wait_data (	input logic clk,
                        input logic [31:0] addr,
                        output logic wait_data
);
	parameter LSB_BITS = 2'b11;
	parameter s0=2'd0, s1=2'd1, s2=2'd2;
	reg [1:0] cur_state, next_state;

	always_ff@(posedge clk) begin
		cur_state <= next_state;
	end

	always_comb begin
		case(cur_state)
		s0: begin
			if (addr[3:2] == LSB_BITS) begin
				wait_data = 1;
				next_state = s1;
			end
			else begin
				wait_data = 0;
				next_state = s0;
			end
		end
		s1: begin
			wait_data = 1;
			next_state = s2;
		end
		s2: begin
			wait_data = 0;
			next_state = s0;
		end
		default: begin
				next_state = s0;
				wait_data = 0;
			end
		endcase
	end
endmodule : mem_wait_data
