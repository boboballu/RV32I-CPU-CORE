// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DEFS_PARAMS_COMMON
/********************************all defines*************************************/
// testbench.sv : modelsum VCD dump
//`define DUMP_VCD

// datapath.sv, testbench.sv, core_top.sv : debug_headerfile is instanced in all the files
//`define MEM_DEBUG
//`define WB_DEBUG

// top_test.sv : uncomment this def for bin mem file read
//`define MEM_BINARY

/********************************************************************************/
`ifdef TB_TESTBENCH
// testbench.sv : console print format specifier
string CONSOLE_FORMAT = "%c";   // %d
// testbench.sv : variables
int HALT_ADDR    = ((4*1024*1024)+8);       // mem[400008] = 1 indicates execution is done
int CONSOLE_ADDR = ((4*1024*1024)+4);       // console output address
int EXE_TIME	 = 20000000;    // execution time in ps / clock period is 10ps

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
`ifdef RTL_CORE_TOP
// BTB parameters
// enable Branch predictor and branch target buffer (BTB)
`define RTL_BPRED

`define BTB_INDEX_SIZE      10
`define BTB_TAG_SIZE        20

// BPRED parameters
`define BPRED_INDEX_SIZE    10
`endif
/********************************************************************************/
