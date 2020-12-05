// block size is interms of words (1 word = 4 byte)
// cache types - package
package cache_types;

	parameter RAM_SIZE 		= 65536;
	parameter TAG_SIZE		= 17;
	parameter INDEX_SIZE 	= 11;
	parameter BLOCK_SIZE  	= 2;
	parameter ASSOC       	= 2;

	typedef struct packed {
		logic [($clog2(ASSOC)-1):0] lru;
		logic [TAG_SIZE-1:0] tag;
		logic valid, dirty;
		logic [BLOCK_SIZE-1:0] [31:0] block;
	} block_t;

	typedef block_t cache_line_t [ASSOC-1:0];
	
	typedef cache_line_t cache_t [INDEX_SIZE-1];
endpackage

import cache_types::*;

module cache_module(
	input logic clock, reset,
	
	input logic req, we,
	input logic [31:0] addr,
	input logic [BLOCK_SIZE-1:0] block_mask,
	input logic [3:0] byte_mask, 
	input block_t write_block,
	output logic miss, 
	output block_t read_block,

	output logic mem_req, mem_we,
	input logic mem_miss,
	input block_t mem_req_blk,
	output block_t mem_wb_block
);

	cache_t cache;
	logic [TAG_SIZE-1:0] tag;
	logic [INDEX_SIZE-1] index;
	logic [BLOCK_SIZE-1:0] blk;

	logic blk_match, valid_match, tag_match;
	logic [($clog2(ASSOC)-1):0] matched_blk;

	logic fetched_blk_available;

	logic [($clog2(ASSOC)-1):0] read_blk_miss;

	assign tag 	= addr[(TAG_SIZE+INDEX_SIZE+BLOCK_SIZE-1):(INDEX_SIZE+BLOCK_SIZE)];
	assign index= addr[(INDEX_SIZE+BLOCK_SIZE-1):(BLOCK_SIZE)];
	assign blk 	= addr[(BLOCK_SIZE-1):0];

	assign miss  = ! (blk_match | fetched_blk_available);
	assign read_block = miss ? cache[index][read_blk_miss] : cache[index][matched_blk];

	always_ff @(posedge clock or negedge reset) begin
		read_blk_miss = 0;
		// initializing the cache after reset
		if (!reset) begin
			mem_req <= 0;
			mem_we 	<= 0;
			mem_wb_block <= '{default:'0};
			fetched_blk_available <= 0;
			for (integer i=0; i<INDEX_SIZE; i++) begin
				for (integer j=0; j<ASSOC; j++) begin
					cache[i][j] <= '{default:0, lru:j};
				end
			end
		end
		else begin
			// defaults
			mem_req <= 0;
			mem_we 	<= 0;
			mem_wb_block <= '{default:'0};
			fetched_blk_available <= 0;

			if (req) begin
				// hit condition - update LRU
				if (blk_match) begin
					// update LRU
					for (integer i=0; i<ASSOC; i++) begin
						if (matched_blk != i) begin
							if (cache[index][i].lru < read_block.lru) begin
								cache[index][i].lru <= cache[index][i].lru + 1;								
							end 
						end
					end
					cache[index][matched_blk].lru <= 0;
					if (we) begin
						for (integer i=0; i<BLOCK_SIZE; i++) begin
							if (block_mask[i]) begin
								if ( byte_mask[0] ) cache[index][matched_blk].block[i][7:0] 	<= write_block.block[i][7:0];
								if ( byte_mask[1] ) cache[index][matched_blk].block[i][15:8] 	<= write_block.block[i][15:8];
								if ( byte_mask[2] ) cache[index][matched_blk].block[i][23:16] 	<= write_block.block[i][23:16];
								if ( byte_mask[3] ) cache[index][matched_blk].block[i][31:24] 	<= write_block.block[i][31:24];
							end
						end
						cache[index][matched_blk].dirty <= 1;
					end
				end
				// miss condition - 1) fetch block from lower mem hierarchy
				// 2) find the block with max lru count, writeback this block to memory
				// 3) replace the tag, data; assert valid=1 and dirty=we
				// 4) update lru 
				else begin
					// cache block fill
					mem_req <= 1;
					if (!mem_miss) begin
						for (integer i=0; i<ASSOC; i++) begin
							if (cache[index][i].lru == ASSOC-1) begin
								read_blk_miss = i;
								// write_back the block to memory, that gets replaced
								if ( (cache[index][i].valid) & (cache[index][i].dirty) ) begin
									mem_we <= 1;
								end
								mem_wb_block <= cache[index][i];
								
								// fill the cache line with new block requested from memory
								cache[index][i].valid <= 1;
								cache[index][i].dirty <= we;
								cache[index][i].tag <= tag;
								if (we) begin
									for (integer j=0; j<BLOCK_SIZE; j++) begin
										if (block_mask[j]) begin
											if ( byte_mask[0] ) cache[index][i].block[j][7:0] <= write_block.block[j][7:0];
											else cache[index][i].block[j][7:0] <= mem_req_blk.block[j][7:0];
											
											if ( byte_mask[1] ) cache[index][i].block[j][15:8] <= write_block.block[j][15:8];
											else cache[index][i].block[j][15:8] <= mem_req_blk.block[j][15:8];
											
											if ( byte_mask[2] ) cache[index][i].block[j][23:16] <= write_block.block[j][23:16];
											else cache[index][i].block[j][23:16] <= mem_req_blk.block[j][23:16];
											
											if ( byte_mask[3] ) cache[index][i].block[j][31:24] <= write_block.block[j][31:24];
											else cache[index][i].block[j][31:24] <= mem_req_blk.block[j][31:24];
										end
									end
								end
								else begin
									cache[index][i].block <= mem_req_blk.block;
								end
								// update the lru of the newly replaced block
								cache[index][i].lru <= 0;
								// indicate the cpu that the fetched block is available
								fetched_blk_available <= 1;
							end
							else begin
								// update the lru for other blocks in the assoc
								cache[index][i].lru <= cache[index][i].lru + 1;
							end
						end
					end
				end
			end
		end
	end

	// reading a cache block
	always_comb begin
		valid_match = 1'b0;
		tag_match = 1'b0;
		blk_match = 1'b0;
		matched_blk = 0;
		if (req) begin
			for (integer clines=0; clines < ASSOC; clines++) begin
				if (cache[index][clines].valid) begin
					valid_match = 1'b1;
					if (cache[index][clines].tag == tag) begin
						tag_match = 1'b1;
						blk_match = 1'b1;
						matched_blk = clines;
					end
				end
			end
		end
	end

endmodule : cache_module