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
    
endpackage : cache_types