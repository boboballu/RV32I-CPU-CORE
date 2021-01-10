// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/

/* Change this config if the L2 supports 2 ports for read and write at the same time. */
//`define dual_ported_L2
`define single_ported_L2

/* is the cache is fully associative, change the define to FA */
`define SA      // FA, SA are the possible options

/* cache_params - modular param definition for each cache module in the design */
`define cache_param_1 \
/* Modifiable parameters */ \
parameter BLOCKS    = (16 / 4), \
parameter SETS      = 32, \
parameter ASSOC     = 2, \
/* Parameters not meant to be modified */ \
parameter INDEX_BIT_SIZE 	= ($clog2(SETS)), \
parameter BLOCK_BIT_SIZE  	= ($clog2(BLOCKS)), \
parameter TAG_BIT_SIZE		= 30 - INDEX_BIT_SIZE - BLOCK_BIT_SIZE, \
parameter LRU_BIT_SIZE      = ($clog2(ASSOC)), \
parameter RAM_SIZE          = 65536, \
parameter CACHE_SIZE 		= SETS * ASSOC * (BLOCKS*4)
