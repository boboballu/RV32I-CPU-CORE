// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`include "defs_params_common.svh"
// cache_types contain all the cache parameters
// import cache_types::*;

module cache_module 
#(
    `cache_param_1
)(
	input logic clock, reset,
	
    input logic req, we,
	input logic [31:0] addr,
	input logic [3:0] byte_mask, 
	input logic [31:0] write_word,
	output logic miss, 
	output logic [31:0] read_word,

    // mem is 2 ported; one is for read and other for write
    output logic mem_req,
    `ifdef single_ported_L2
    output logic [31:0] mem_addr,
    `endif
    `ifdef dual_ported_L2
    output logic [31:0] mem_read_addr,
    output logic [31:0] mem_write_addr,
    `endif

    output logic mem_we,
	input logic [BLOCKS-1:0] [31:0] mem_read_block,
    output logic [BLOCKS-1:0] [31:0] mem_write_block,
    input logic mem_miss
);


    typedef struct packed {
        logic [(LRU_BIT_SIZE-1):0] lru;
        logic [TAG_BIT_SIZE-1:0] tag;
        logic valid, dirty;
        logic [BLOCKS-1:0] [31:0] block;
    } block_t;
    
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
    `ifdef dual_ported_L2
    logic [31:0] mem_addr;
    `endif
    `ifdef single_ported_L2
    logic [31:0] mem_read_addr, mem_write_addr;
    `endif
    logic mem_done;

    // only MSB 30 bits [31:2] of the address are taken into consideration
    assign addr_tag     = addr[(TAG_BIT_SIZE+INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2-1):(INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2)];
    `ifdef FA
    assign addr_index   = 0;
    `else
    assign addr_index   = addr[(INDEX_BIT_SIZE+BLOCK_BIT_SIZE+2-1):(BLOCK_BIT_SIZE+2)];
    `endif
    assign addr_offset  = addr[(BLOCK_BIT_SIZE+2-1):2];

    // read_word output
    assign read_word    = cache[addr_index][assoc_match_index].block[addr_offset];
    
    assign mem_read_addr    = addr;
    assign mem_write_addr   = req ? {cache[addr_index][assoc_lru_index].tag, addr_index, addr_offset, 2'b00} : 0;
    assign mem_write_block  = req ? cache[addr_index][assoc_lru_index].block : '{default:0};
    
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

    // wb - wa state machine
    cache_miss_fetch cache_miss_fetch (
        .clock(clock), .reset(reset),
        .miss(miss), 
        .lru_blk_valid(cache[addr_index][assoc_lru_index].valid), .lru_blk_dirty(cache[addr_index][assoc_lru_index].dirty),
        .mem_write_addr(mem_write_addr), .mem_read_addr(mem_read_addr),
        .mem_miss(mem_miss),
    
        .mem_req(mem_req), .mem_we(mem_we), .mem_done(mem_done),
        .mem_addr(mem_addr)
    );    
    
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
            // update LRU during hit and a miss - when mem_miss is low
            if ( (!miss) | (miss & (!mem_done)) ) begin
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
        if (miss & (!mem_done)) begin
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

module cache_miss_fetch (
    input logic clock, reset,
    input logic miss, 
    input logic lru_blk_valid, lru_blk_dirty,
    input logic [31:0] mem_write_addr, mem_read_addr,
    input logic mem_miss,

    output logic mem_req, mem_we, mem_done,
    output logic [31:0] mem_addr
    );

    // 2 possibilities - 
    // 1) only write allocate; invalid / non dirty block eviction
    // 2) write back - write allocate; valid & dirty block eviction
    parameter s0 = 2'b00, s1 = 2'b01, s2 = 2'b10, s3 = 2'b11;

    logic [1:0] current_state;  // register
    logic [1:0] next_state;     // wire

    always_ff @ (posedge clock or negedge reset) begin
        if (!reset) current_state <= s0;
        else        current_state <= next_state;
    end
    
    always_comb begin
        mem_req     = miss;
        mem_addr    = mem_read_addr;
        mem_we      = 0;
        mem_done    = mem_miss; 
        case (current_state)
            s0: begin
                next_state = s0;
                if ( miss & lru_blk_valid & lru_blk_dirty ) begin
                    mem_req     = 1;
                    mem_addr    = mem_write_addr;
                    mem_we      = 1;
                    next_state  = s1;
                end
            end
            s1: begin
                mem_req     = miss;
                mem_addr    = mem_write_addr;
                mem_we      = 1;
                mem_done    = 1;
                next_state  = s1;
                if (!mem_miss) begin
                    mem_req = 0;
                    mem_we  = 0;
                    next_state = s2;
                end
            end
            s2: begin
                next_state  = s2;
                if (!mem_miss) begin
                    next_state = s0;
                end
            end
        endcase
    end
endmodule : cache_miss_fetch