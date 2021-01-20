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
`define RTL_CACHE_IMPL
`include "defs_params_common.svh"
import dbg_pkg::*;

interface mem_bus;
	logic clk;

	// instruction mem interface signals
	logic imem_req;
	logic [31:0] imem_addr, imem_instn;
	logic imem_wait;

	// data mem interface signals
	logic dmem_wait;
	logic [31:0] dmem_addr, dmem_rd, dmem_wd;
	logic dmem_we;
	logic dmem_req;
	logic [3:0] dmem_mask;

	modport Imem (	input imem_instn, imem_wait,

					output imem_addr, imem_req
	);

	modport Dmem (	input dmem_rd, dmem_wait,

					output clk,

					output dmem_addr, dmem_we, dmem_wd, dmem_req, dmem_mask
	);

	modport L1_cache (
					input clk,

					input imem_addr, dmem_addr, dmem_we, dmem_wd, dmem_req,

					output imem_instn, dmem_rd, imem_wait, dmem_wait
	);
endinterface : mem_bus


module cache_mem_glue_logic # (
		parameter BLOCKS = 4
	)
	(
	input logic clk, reset,
	input logic mem_req,
    input logic [31:0] mem_addr,
    output logic [BLOCKS-1:0] [31:0] mem_read_block,
    input logic mem_we,
    input logic [BLOCKS-1:0] [31:0] mem_write_block,
    output logic mem_miss,
	mem_bus Bus
	);

	logic [31:0] blk_counter_current, blk_counter_next;
	logic [BLOCKS-1:0] [31:0] mem_read_reg;

	assign Bus.dmem_addr = mem_addr + (2 * blk_counter_current);
	assign mem_read_block = mem_read_reg;

	always@(posedge clk or negedge reset) begin
		if (!reset) begin
			blk_counter_current <= 0;
		end
		else begin
			blk_counter_current <= blk_counter_next;
			if (mem_req) begin
				if (!Bus.dmem_wait) begin
					if (mem_we) begin
						Bus.dmem_wd <= mem_write_block[blk_counter_current];
					end
					else begin
						mem_read_reg[blk_counter_current] <= Bus.dmem_rd;
					end
				end
			end
		end
	end

	always_comb begin
		mem_miss = 1;
		blk_counter_next = blk_counter_current;
		case (blk_counter_current)
			0 : begin
				if (mem_req) begin
					if (!Bus.dmem_wait) begin
						blk_counter_next = blk_counter_current + 1;
					end
				end
				else begin
					mem_miss = 0;
				end
			end
			(BLOCKS-1) : begin
				if (mem_req) begin
					if (!Bus.dmem_wait) begin
						blk_counter_next = 0;
						mem_miss = 0;
					end
				end
			end
			default : begin
				if (mem_req) begin
					if (!Bus.dmem_wait) begin
						blk_counter_next = blk_counter_current + 1;
					end
				end
			end
		endcase
	end	
endmodule : cache_mem_glue_logic

// imem & dmem connects to the mem_bus and CPU
module dmem # (
	`DCACHE
	)
	(
	input logic clk, reset,
	input logic dmem_we,
	input logic [31:0] dmem_addr, dmem_wd,
	input logic [3:0] dmem_mask,
	input logic dmem_req,

	output logic [31:0] dmem_rd,
	output logic dmem_wait,
	mem_bus.Dmem Bus
	);

	// assign Bus.clk 				= clk;
	// assign Bus.dmem_addr 		= dmem_addr;
	// assign Bus.dmem_we 			= dmem_we;
	// assign Bus.dmem_wd 			= dmem_wd;
	// assign Bus.dmem_req			= dmem_req;
	// assign Bus.dmem_mask			= dmem_mask;
	// assign dmem_rd 				= Bus.dmem_rd;
	// assign dmem_wait 			= Bus.dmem_wait;
	/*-------------------------------------------------*/

	logic mem_req;
    logic [31:0] mem_addr;
    logic [BLOCKS-1:0] [31:0] mem_read_block;
    logic mem_we;
    logic [BLOCKS-1:0] [31:0] mem_write_block;
    logic mem_miss;

	cache_module cache  (
        .clock(clk), .reset(reset),
	
        .req(dmem_req), .we(dmem_we),
        .addr(dmem_addr),
        .byte_mask(dmem_mask), 
        .write_word(dmem_wd),
        .miss(dmem_wait), 
        .read_word(dmem_rd),

        .mem_req(mem_req),
        .mem_addr(mem_addr),
        .mem_read_block(mem_read_block),
        
        .mem_we(mem_we),
        .mem_write_block(mem_write_block),
        
        .mem_miss(mem_miss)
    );

endmodule : dmem

module imem(input logic [31:0] imem_addr,
			input logic imem_req,
			output logic [31:0] imem_instn,
			output logic imem_wait,
			mem_bus.Imem Bus
);
	assign Bus.imem_addr 		= imem_addr;
	assign Bus.imem_req			= imem_req;
	assign imem_instn  			= Bus.imem_instn;
	assign imem_wait			= Bus.imem_wait;
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
	bit [31:0] MEM [(RAM_SIZE/4)-1:0]; // 64 KB of memory

	// Imem read memory
	initial begin
		`ifdef MEM_BINARY
		$readmemb(EXEC, MEM);
		`else
		$readmemh(EXEC, MEM);
		`endif
	end

	// Imem read - returns instn only if imem_req is 1
	assign Bus.imem_instn = Bus.imem_req ? MEM[Bus.imem_addr[31:2]] : 'b0;

	// Dmem read and write implementation
	assign Bus.dmem_rd = Bus.dmem_req ? MEM[Bus.dmem_addr[31:2]] : 'b0;
	always_ff @(posedge Bus.clk) begin
		if (Bus.dmem_we) begin
			// MEM[Bus.dmem_addr[31:2]] <= Bus.dmem_wd;
			if ( Bus.dmem_mask[0] ) MEM[Bus.dmem_addr[31:2]][7:0] 	<= Bus.dmem_wd[7:0];
			if ( Bus.dmem_mask[1] ) MEM[Bus.dmem_addr[31:2]][15:8] 	<= Bus.dmem_wd[15:8];
			if ( Bus.dmem_mask[2] ) MEM[Bus.dmem_addr[31:2]][23:16] <= Bus.dmem_wd[23:16];
			if ( Bus.dmem_mask[3] ) MEM[Bus.dmem_addr[31:2]][31:24] <= Bus.dmem_wd[31:24];
		end
	end

	`ifdef imem_wait
	// not using the state-machine wait - which is an over thought implementation; completely unnecessary
	// mem_wait_data #( .LSB_BITS(2'b11) ) waitI (.clk(Bus.clk), .addr(Bus.imem_addr), .wait_data(Bus.imem_wait));
	always @(posedge Bus.clk) begin
		if ($urandom_range(0, 7) == 7)
			Bus.imem_wait = 1;
		else
			Bus.imem_wait = 0;
	end
	`else
	assign Bus.imem_wait = 0;
	`endif

	`ifdef dmem_wait
	// not using the state-machine wait - which is an over thought implementation; completely unnecessary
	// mem_wait_data #( .LSB_BITS(2'b11) ) waitD (.clk(Bus.clk), .addr(Bus.dmem_addr), .wait_data(Bus.dmem_wait));
	always @(posedge Bus.clk) begin
		if ($urandom_range(0, 7) == 7)
			Bus.dmem_wait = 1;
		else
			Bus.dmem_wait = 0;
	end
	`else
	assign Bus.dmem_wait = 0;
	`endif

endmodule : unified_L1_cache