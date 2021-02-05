// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DEFS_PARAMS_COMMON
/********************************all defines*************************************/
// testbench.sv : modelsum VCD dump
//`define DUMP_VCD

// rtl_datapath.sv, tb_testbench.sv, rtl_core_top.sv : defs_params_common.svh is instanced in all the files
// `define MEM_DEBUG

// top_test.sv : uncomment this def for bin mem file read
//`define MEM_BINARY

/********************************************************************************/
`ifdef TB_TESTBENCH
// testbench.sv : console print format specifier
string CONSOLE_FORMAT = "%c";   // %d
// testbench.sv : variables
int HALT_ADDR    = ((4*1024*1024)+8);       // mem[400008] = 1 indicates execution is done
int CONSOLE_ADDR = ((4*1024*1024)+4);       // console output address
int EXE_TIME	 = 200000000;    // execution time in ps / clock period is 10ps

// D_cache_address and D_cache_data not used for testing anymore
int D_cache_address = 84;       // Unit mem_debug test; mem store address
int D_cache_data    = 7;        // Unit mem_debug test; mem store value
`endif
/********************************************************************************/
`ifdef RTL_MEMORY_IMPL
// top_test.sv : uncomment for IWAIT - IMEM cache miss wait model
// top_test.sv : uncomment for DWAIT - DMEM cache miss wait model
// `define IWAIT
// `define DWAIT
`endif
/********************************************************************************/
`ifdef RTL_TOP_TEST
`define L1_SIZE ((4*1024*1024))           // 4M/4 = 1M words ; which is 4M bytes = 4MB
`endif
/********************************************************************************/

/**************************** Cache parameters - I cache ************************/
`ifdef RTL_CACHE_IMPL
/* cache_params - modular param definition for each cache module in the design */

/* Parameters not meant to be modified */
`define NM_CACHE_PARAMS \
parameter INDEX_BIT_SIZE 	= ($clog2(SETS)), \
parameter BLOCK_BIT_SIZE  	= ($clog2(BLOCKS)), \
parameter TAG_BIT_SIZE		= 30 - INDEX_BIT_SIZE - BLOCK_BIT_SIZE, \
parameter LRU_BIT_SIZE      = ($clog2(ASSOC)), \
parameter CACHE_SIZE 		= SETS * ASSOC * (BLOCKS*4)

// Custom parametrized struct datatype - Block type should be common to all
// `parametrized_block_t(BLOCKS, LRU_BIT_SIZE, TAG_BIT_SIZE)
`define parametrized_block_t(BK, TBS, LBS)  \
typedef struct packed { \
    logic [(LBS-1):0] lru; \
    logic [TBS-1:0] tag;   \
    logic valid, dirty; \
    logic [BK-1:0] [31:0] block;    \
} block_t;

/*-------------------------------------------------*/
/* Modifiable parameters */
`define ICACHE \
parameter BLOCKS    = (16 / 4), \
parameter SETS      = 32, \
parameter ASSOC     = 2, \
parameter RAM_SIZE  = 65536, \
`NM_CACHE_PARAMS
/* Change this config if the L2 supports 2 ports for read and write at the same time. */
//`define dual_ported_L2
`define single_ported_L2

/* is the cache is fully associative, change the define to FA */
`define SA      // FA, SA are the possible options

/*-------------------------------------------------*/
/* Modifiable parameters */
`define DCACHE \
parameter BLOCKS    = (16 / 4), \
parameter SETS      = 32, \
parameter ASSOC     = 2, \
parameter RAM_SIZE  = 65536, \
`NM_CACHE_PARAMS
/* Change this config if the L2 supports 2 ports for read and write at the same time. */
//`define dual_ported_L2
`define single_ported_L2

/* is the cache is fully associative, change the define to FA */
`define SA      // FA, SA are the possible options

`endif
/********************************************************************************/
