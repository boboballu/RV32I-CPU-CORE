// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
// the top module used for test and verification //
`define RTL_TOP_TEST
`define RTL_CACHE_IMPL
`include "defs_params_common.svh"
import dbg_pkg::*;

module top(	input logic clk, reset,
			output logic [31:0] writedata, dataadr,
			output logic [31:0] readdata, pc, instr,
			output logic memwrite
);

	// icache imem and iram wires
	logic icache_req;
	logic [31:0] icache_addr, icache_read_word;
	logic icache_wait;
	
	logic imem_req;
	logic [31:0] imem_addr;
	logic [3:0] [31:0] imem_read_block;
	logic imem_miss;

	logic iram_req;
	logic [31:0] iram_addr, iram_read_word;
	logic iram_miss;


	// dcache dmem and dram wires
	logic dcache_req;
	logic [31:0] dcache_addr;
	logic [3:0] dcache_mask;
	logic [31:0] dcache_read_word, dcache_write_word;
	logic dcache_we, dcache_wait;
	
	logic dmem_req;
	logic [31:0] dmem_addr;
	logic [3:0] [31:0] dmem_read_block, dmem_write_block;
	logic dmem_we, dmem_miss;

	logic dram_req;
	logic [31:0] dram_addr;
	logic [31:0] dram_read_word, dram_write_word;
	logic dram_we, dram_miss;

	// top module output assignments
	assign writedata 	= dcache_write_word;
	assign dataadr		= dcache_addr;
	assign readdata		= dcache_read_word;
	assign pc			= icache_addr;
	assign instr		= icache_read_word;
	assign memwrite		= dcache_we;

	riscv_32i riscv_32i (
        .clk(clk), .reset(reset),

        // instruction mem interface signals
        .imem_pc_addr(icache_addr),
        .imem_req(icache_req),
        .imem_instn(icache_read_word),
        .imem_wait(icache_wait),

        // data mem interface signals
        .dmem_we(dcache_we),
        .dmem_addr(dcache_addr), .dmem_wd(dcache_write_word),
        .dmem_mask(dcache_mask),
        .dmem_req(dcache_req),
        .dmem_rd(dcache_read_word),
        .dmem_wait(dcache_wait)
	);

	mem_bus Bus();

	// Icache impl

	cache_module icache (
        .clock(clk), .reset(reset),
	
        .req(icache_req), .we(1'b0),
        .addr(icache_addr),
        .byte_mask(4'b1111), 
        .write_word(32'b0),
        .miss(icache_wait), 
        .read_word(icache_read_word),

        .mem_req(imem_req),
        .mem_addr(imem_addr),
        .mem_read_block(imem_read_block),
        
        .mem_we(),
        .mem_write_block(),
        
        .mem_miss(imem_miss)
    );

	
    ram_cache_glue icache_mem_glue (
        .clock(clk), .reset(reset),

        // cache side
        .mem_req(imem_req),
        .mem_addr (imem_addr),
        .mem_we(1'b0),
        .mem_read_block(imem_read_block),
        .mem_write_block(1'b0),
        .mem_miss(imem_miss),

        //ram side
        .ram_req (iram_req),
        .ram_addr (iram_addr),
        .ram_we (),
        .ram_read_word (iram_read_word),
        .ram_write_word (),
        .ram_miss (iram_miss)
    );

	imem imem(.imem_addr(iram_addr), .imem_instn(iram_read_word), .imem_req(iram_req), .imem_wait(iram_miss), .Bus(Bus));


    //imem imem(.imem_addr(icache_addr), .imem_instn(icache_read_word), .imem_req(icache_req), .imem_wait(icache_wait), .Bus(Bus));

	// Dcache impl

	cache_module dcache (
        .clock(clk), .reset(reset),
	
        .req(dcache_req), .we(dcache_we),
        .addr(dcache_addr),
        .byte_mask(dcache_mask), 
        .write_word(dcache_write_word),
        .miss(dcache_wait), 
        .read_word(dcache_read_word),

        .mem_req(dmem_req),
        .mem_addr(dmem_addr),
        .mem_read_block(dmem_read_block),
        
        .mem_we(dmem_we),
        .mem_write_block(dmem_write_block),
        
        .mem_miss(dmem_miss)
    );

	
    ram_cache_glue dcache_mem_glue (
        .clock(clk), .reset(reset),

        // cache side
        .mem_req(dmem_req),
        .mem_addr (dmem_addr),
        .mem_we(dmem_we),
        .mem_read_block(dmem_read_block),
        .mem_write_block(dmem_write_block),
        .mem_miss(dmem_miss),

        //ram side
        .ram_req (dram_req),
        .ram_addr (dram_addr),
        .ram_we (dram_we),
        .ram_read_word (dram_read_word),
        .ram_write_word (dram_write_word),
        .ram_miss (dram_miss)
    );	
	
	dmem dmem(	.clk(clk), .dmem_we(dram_we), .dmem_addr(dram_addr),
				.dmem_wd(dram_write_word), .dmem_mask(4'b1111), .dmem_req(dram_req),
				.dmem_rd(dram_read_word), .dmem_wait(dram_miss), .Bus(Bus)
	);

    //testing dmem pass through

    // dmem dmem(	.clk(clk), .dmem_we(dcache_we), .dmem_addr(dcache_addr),
	// 			.dmem_wd(dcache_write_word), .dmem_mask(dcache_mask), .dmem_req(dcache_req),
	// 			.dmem_rd(dcache_read_word), .dmem_wait(dcache_wait), .Bus(Bus)
	// );
    
    unified_L1_cache #(.RAM_SIZE(`L1_SIZE)) L1_cache (.Bus(Bus));
	
endmodule : top
