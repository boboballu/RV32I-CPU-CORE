// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/********************************all defines*************************************/
//debug_headerfile is instanced in all the files

// comment the definition below to disable debugging io at mem stage (mem_debug) : testbench.sv
`define wb_debug

// uncomment this def for bin mem file read : top_test.sv
// `define MEM_BINARY

// uncomment for DWAIT - DMEM cache miss wait model : top_test.sv
//`define DWAIT
/********************************************************************************/
// testbench.sv variables
int CONSOLE_ADDR = 65532;   // console output address
int EXE_TIME	 = 2000;   // execution time in ps / clock period is 10ps

int D_cache_address = 84;   // Unit mem_debug test; mem store address 
int D_cache_data    = 7;    // Unit mem_debug test; mem store value

/********************************************************************************/

