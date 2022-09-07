// block size is interms of words (1 word = 4 byte)
// cache types - package
package cache_types;

    // parameter RAM_SIZE         = 65536;
    // parameter TAG_SIZE        = 17;
    // parameter INDEX_SIZE     = 11;
    // parameter BLOCK_SIZE      = 2;
    // parameter ASSOC           = 2;

    typedef struct packed {
        logic lru;
        logic [27:0] tag;
        logic valid, dirty;
        logic [1:0] [31:0] block;
    } block_t;
    
endpackage

import cache_types::*;

module cache_module(
    input logic clock, reset,
    
    input logic req, we,
    input logic [31:0] addr,
    input logic [3:0] byte_mask, 
    input logic [31:0] write_block,
    output logic miss, 
    output logic [31:0] read_block,

    // mem is 2 ported; one is for read and other for write
    output logic mem_req,
    output logic [31:0] mem_read_addr,
    input logic [1:0] [31:0] mem_read_block,

    output logic mem_we,
    output logic [31:0] mem_write_addr,
    output logic [1:0] [31:0] mem_write_block,
    input logic mem_miss
);
    logic [27:0] addr_tag;
    logic [0:0] addr_index;
    logic [0:0] addr_offset;

    // indices and assocs
    block_t [1:0] [1:0] cache;

    // comb - 1) assoc_match_index
    logic [0:0] assoc_match_index;
    // 4) comb - assoc_lru_index - cache block to be replaced
    logic [0:0] assoc_lru_index = 0;
    logic [0:0] assoc_mru_index;

    // only MSB 30 bits [31:2] of the address are taken into consideration
    assign addr_tag     = addr[31:4];
    assign addr_index   = addr[3];
    assign addr_offset  = addr[2];

    // read_block output
    assign read_block = cache[addr_index][assoc_match_index].block[addr_offset];
    assign mem_read_addr = addr;

    // posedge clock blocks are required for 
    // 1) reset;
    // 2) cache write during cpu write - cache hit; 
    // 3a) cache write during cache miss and fetch from low level cache - cpu read;
    // 3b) cache write during cache miss and fetch from low level cache - cpu write;
    // 4) lru update;

    // 1) reset - initializing the cache after reset
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            for (integer i=0; i<2; i++) begin
                for (integer j=0; j<2; j++) begin
                    cache[i][j] <= '{default:0, lru:j, block:{32'd2,32'd2}};
                end
            end
        end
    end

    // 2) cache write during cpu write
    // 3a) cache write during cache miss and fetch from low level cache - cpu read;
    // 3b) cache write during cache miss and fetch from low level cache - cpu write;
    always_ff @(posedge clock) begin
        if (reset & req) begin
            cache_write ();
        end
    end

    // generate mem_req and mem_we to fetch a block from L2 during cache miss
    always_comb begin
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
    end
    
    // assoc_match_index - takes cache[addr_index] (cache_line) and returns miss and index of match
    always_comb begin
        if (req) begin
            miss = 1;
            assoc_match_index = assoc_lru_index;
            for (int i=0; i<2; i++) begin
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
    end

    // 4) LRU implementation
    // update the lru always 
    always_ff @(posedge clock) begin
        if (reset & req) begin
            // update LRU durng hit and a miss - when mem_miss is low
            if ( (!miss) | (miss & (!mem_miss)) ) begin
                for (int i=0; i<2; i++) begin
                    if (cache[addr_index][i].lru < cache[addr_index][assoc_match_index].lru) begin
                        cache[addr_index][i].lru = cache[addr_index][i].lru+1;
                    end
                end
                cache[addr_index][assoc_match_index].lru <= 0;
            end
        end
    end

    always_comb begin
        if (req) begin
            assoc_lru_index = 1; // lowest
            assoc_mru_index = 0; // highest
            for (int i=0; i<2; i++) begin
                if (cache[addr_index][i].lru == 1) assoc_lru_index = i;
                if (cache[addr_index][i].lru == 0) assoc_mru_index = i;
            end
        end
        else begin
            assoc_lru_index = 0; // lowest
            assoc_mru_index = 1; // highest
        end
    end

    function void cache_write ();
        // 2) cpu write - cache hit
        if ((!miss) & we) begin
            cache[addr_index][assoc_match_index].dirty <= 1;
            if (byte_mask[0]) cache[addr_index][assoc_match_index].block[addr_offset][7:0] <= write_block[7:0];
            if (byte_mask[1]) cache[addr_index][assoc_match_index].block[addr_offset][15:8] <= write_block[15:8];
            if (byte_mask[2]) cache[addr_index][assoc_match_index].block[addr_offset][23:16] <= write_block[23:16];
            if (byte_mask[3]) cache[addr_index][assoc_match_index].block[addr_offset][31:24] <= write_block[31:24];
        end

        // read and write misses
        // 3a and 3b) cpu write/read - cache miss
        if (miss & (!mem_miss)) begin
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

                if (byte_mask[0]) cache[addr_index][assoc_lru_index].block[addr_offset][7:0] <= write_block[7:0];
                if (byte_mask[1]) cache[addr_index][assoc_lru_index].block[addr_offset][15:8] <= write_block[15:8];
                if (byte_mask[2]) cache[addr_index][assoc_lru_index].block[addr_offset][23:16] <= write_block[23:16];
                if (byte_mask[3]) cache[addr_index][assoc_lru_index].block[addr_offset][31:24] <= write_block[31:24];
            end
        end
    endfunction : cache_write


endmodule : cache_module
