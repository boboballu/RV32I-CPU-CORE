// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
`define DATAPATH_HEADERFILE
/********************************all defines*************************************/
// testbench.sv : modelsum VCD dump
//`define DUMP_VCD

// datapath.sv, testbench.sv, core_top.sv : debug_headerfile is instanced in all the files
//`define MEM_DEBUG

// top_test.sv : uncomment this def for bin mem file read
//`define MEM_BINARY

// top_test.sv : uncomment for IWAIT - IMEM cache miss wait model
// top_test.sv : uncomment for DWAIT - DMEM cache miss wait model
// `define IWAIT
// `define DWAIT

/********************************************************************************/
`ifdef TESTBENCH
// testbench.sv : console print format specifier
string CONSOLE_FORMAT = "%c"; // %c
// testbench.sv : variables
int CONSOLE_ADDR = 65532;   // console output address
int EXE_TIME	 = 50000;   // execution time in ps / clock period is 10ps

int D_cache_address = 84;   // Unit mem_debug test; mem store address
int D_cache_data    = 7;    // Unit mem_debug test; mem store value
`endif
/********************************************************************************/
