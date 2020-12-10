// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

// cache types - package
package cache_types;
    // These 3 parameters are meant to be changed
    // block size is in-terms of words (1 word = 4 byte)
    parameter BLOCKS            = 32 / 4;   // (32 bytes -> 8 words) in terms of words
    parameter SETS              = 64;       // Number of sets in the cache
    parameter ASSOC       	    = 4;        // N way associative

	parameter INDEX_BIT_SIZE 	= ($clog2(SETS));
    parameter BLOCK_BIT_SIZE  	= ($clog2(BLOCKS));
    parameter TAG_BIT_SIZE		= 30 - INDEX_BIT_SIZE - BLOCK_BIT_SIZE;

    parameter LRU_BIT_SIZE      = ($clog2(ASSOC));

    parameter RAM_SIZE          = 65536;
    parameter CACHE_SIZE 		= SETS * ASSOC * (BLOCKS*4);

	typedef struct packed {
		logic [(LRU_BIT_SIZE-1):0] lru;
		logic [TAG_BIT_SIZE-1:0] tag;
		logic valid, dirty;
		logic [BLOCKS-1:0] [31:0] block;
    } block_t;
    
endpackage

import cache_types::*;

module cache_module(
	input logic clock, reset,
	
    input logic req, we,
	input logic [31:0] addr,
	input logic [3:0] byte_mask, 
	input logic [31:0] write_word,
	output logic miss, 
	output logic [31:0] read_word,

    // mem is 2 ported; one is for read and other for write
    output logic mem_req,
    output logic [31:0] mem_read_addr,
	input logic [BLOCKS-1:0] [31:0] mem_read_block,

    output logic mem_we,
    output logic [31:0] mem_write_addr,
	output logic [BLOCKS-1:0] [31:0] mem_write_block,
    input logic mem_miss
);
    logic [TAG_BIT_SIZE-1:0] addr_tag;
    logic [INDEX_BIT_SIZE-1:0] addr_index;
    logic [BLOCK_BIT_SIZE-1:0] addr_offset;

    // indices and assocs
    block_t [SETS-1:0] [ASSOC-1:0] cache;

    // comb - 1) assoc_match_index
    logic [LRU_BIT_SIZE-1:0] assoc_match_index;
    // 4) comb - assoc_lru_index - cache block to be replaced
    logic [LRU_BIT_SIZE-1:0] assoc_lru_index = 0;
    logic [LRU_BIT_SIZE-1:0] assoc_mru_index;

    // 5) wb_wa implementation
    logic [31:0] mem_addr; logic mem_ctl_we;

    wb_wa_fsm wb_wa_fsm (clock, reset, 
    mem_we, mem_miss,
    mem_write_addr, mem_read_addr,
    mem_addr, mem_ctl_we);

    // only MSB 30 bits [31:2] of the address are taken into consideration
    assign addr_tag     = addr[(TAG_BIT_SIZE+INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2-1):(INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2)];
    assign addr_index   = addr[(INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2-1):(BLOCK_BIT_SIZE+2)];
    assign addr_offset  = addr[(BLOCK_BIT_SIZE+2-1):2];

    // read_word output
    assign read_word    = cache[addr_index][assoc_match_index].block[addr_offset];
    assign mem_read_addr= addr;

    // posedge clock blocks are required for 
    // 1) reset;
    // 2) cache write during cpu write - cache hit; 
    // 3a) cache write during cache miss and fetch from low level cache - cpu read;
    // 3b) cache write during cache miss and fetch from low level cache - cpu write;
    // 4) lru update;

    // 1) reset - initializing the cache after reset
    always_ff @(posedge clock or negedge reset) begin : initialization
		if (!reset) begin
			for (integer i=0; i<SETS; i++) begin
				for (integer j=0; j<ASSOC; j++) begin
					cache[i][j] <= '{default:0, lru:j};
				end
			end
        end
    end : initialization

    // 2) cache write during cpu write
    // 3a) cache write during cache miss and fetch from low level cache - cpu read;
    // 3b) cache write during cache miss and fetch from low level cache - cpu write;
    always_ff @(posedge clock) begin : CpuToCache_writes
        if (reset & req) begin
            cache_write ();
        end
    end : CpuToCache_writes

    // generate mem_req and mem_we to fetch a block from NEXT LEVEL during cache miss
    always_comb begin : cache_miss_fetch
        if (req) begin
            mem_req = miss;
            mem_write_addr = {cache[addr_index][assoc_lru_index].tag, addr_index, addr_offset, 2'b00};
            mem_we = mem_req & cache[addr_index][assoc_lru_index].valid & cache[addr_index][assoc_lru_index].dirty;
            mem_write_block = cache[addr_index][assoc_lru_index].block;
        end
        else begin
            mem_req = 0;
            mem_write_addr = 0;
            mem_we = 0;
            mem_write_block = '{default:0};
        end
    end : cache_miss_fetch
    
    // assoc_match_index - takes cache[addr_index] (cache_line) and returns miss and index of match
    always_comb begin : lru_match_index_cache_hit
        if (req) begin
            miss = 1;
            assoc_match_index = assoc_lru_index;
            for (int i=0; i<ASSOC; i++) begin
                if ((cache[addr_index][i].tag == addr_tag) & cache[addr_index][i].valid == 1) begin
                    assoc_match_index = i; miss = 0;
                end
            end
        end
        else begin
            // defaults
            miss = 0;
            assoc_match_index = 0;
        end
    end : lru_match_index_cache_hit

    // 4) LRU implementation
    // update the lru always 
    always_ff @(posedge clock) begin : lru_implementation
        if (reset & req) begin
            // update LRU durng hit and a miss - when mem_miss is low
            if ( (!miss) | (miss & (!mem_miss)) ) begin
                for (int i=0; i<ASSOC; i++) begin
                    if (cache[addr_index][i].lru < cache[addr_index][assoc_match_index].lru) begin
                        cache[addr_index][i].lru <= cache[addr_index][i].lru+1;
                    end
                end
                cache[addr_index][assoc_match_index].lru <= 0;
            end
        end
    end : lru_implementation

    always_comb begin : lru_extreme_blocks
        if (req) begin
            assoc_mru_index = 0;        // lowest
            assoc_lru_index = ASSOC-1;  // highest
            for (int i=0; i<ASSOC; i++) begin
                if (cache[addr_index][i].lru == ASSOC-1) assoc_lru_index = i;
                if (cache[addr_index][i].lru == 0) assoc_mru_index = i;
            end
        end
        else begin
            assoc_lru_index = 0;        // lowest
            assoc_mru_index = ASSOC-1;  // highest
        end
    end : lru_extreme_blocks


    function void cache_write ();
        // 2) cpu write - cache hit
        if ((!miss) & we) begin
            cache[addr_index][assoc_match_index].dirty <= 1;
            if (byte_mask[0]) cache[addr_index][assoc_match_index].block[addr_offset][7:0] <= write_word[7:0];
            if (byte_mask[1]) cache[addr_index][assoc_match_index].block[addr_offset][15:8] <= write_word[15:8];
            if (byte_mask[2]) cache[addr_index][assoc_match_index].block[addr_offset][23:16] <= write_word[23:16];
            if (byte_mask[3]) cache[addr_index][assoc_match_index].block[addr_offset][31:24] <= write_word[31:24];
        end

        // read and write misses
        // 3a and 3b) cpu write/read - cache miss
        if (miss & (!mem_miss) & (!mem_we)) begin
            cache[addr_index][assoc_lru_index].tag <= addr_tag;
            // 3a) cpu read miss
            if (!we) begin
                cache[addr_index][assoc_lru_index].dirty <= 0;
                cache[addr_index][assoc_lru_index].valid <= 1;
                cache[addr_index][assoc_lru_index].block <= mem_read_block;
            end
            // 3b) cpu write miss
            else begin
                cache[addr_index][assoc_lru_index].dirty <= 1;
                cache[addr_index][assoc_lru_index].valid <= 1;
                cache[addr_index][assoc_lru_index].block <= mem_read_block;

                if (byte_mask[0]) cache[addr_index][assoc_lru_index].block[addr_offset][7:0] <= write_word[7:0];
                if (byte_mask[1]) cache[addr_index][assoc_lru_index].block[addr_offset][15:8] <= write_word[15:8];
                if (byte_mask[2]) cache[addr_index][assoc_lru_index].block[addr_offset][23:16] <= write_word[23:16];
                if (byte_mask[3]) cache[addr_index][assoc_lru_index].block[addr_offset][31:24] <= write_word[31:24];
            end
        end
    endfunction : cache_write


endmodule : cache_module

module wb_wa_fsm (
    input logic clock, reset, 
    input logic mem_we, mem_miss,
    input logic [31:0] mem_write_addr, mem_read_addr,
    output logic [31:0] mem_addr,
    output logic mem_ctl_we
    );

    parameter s0 = 2'b00, s1 = 2'b01, s2 = 2'b10, s3 = 2'b11;

    logic [1:0] p_state; // reg
    logic [1:0] n_state; // wire
    always_ff @ (posedge clock or negedge reset) begin
        if (!reset) p_state <= s0;
        else        p_state <= n_state;
    end

    always_comb begin
        case (p_state)
            s0: begin
                mem_addr = mem_read_addr;
                mem_ctl_we = 0;
                n_state = s0;
                if (mem_we) begin
                    mem_addr = mem_write_addr;
                    mem_ctl_we = 1;
                    n_state = s1;
                end
            end

            s1: begin
                mem_addr = mem_write_addr;
                mem_ctl_we = 1;
                n_state = s1;
                if (!mem_miss) begin
                    mem_addr = mem_read_addr;
                    mem_ctl_we = 0;
                    n_state = s0;
                end
            end
        endcase
    end

endmodule : wb_wa_fsm