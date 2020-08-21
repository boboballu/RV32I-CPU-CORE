// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/********************************all defines*************************************/
//debug_headerfile is instanced in all the files

// comment the definition below to disable debugging io at mem stage (mem_debug) : testbench.sv
//`define mem_debug

// uncomment this def for bin mem file read : top_test.sv
// `define MEM_BINARY

// uncomment for DWAIT - DMEM cache miss wait model : top_test.sv
`define DWAIT
/********************************************************************************/
// testbench.sv variables
int CONSOLE_ADDR = 65532;
int EXE_TIME	 = 10000;
/********************************************************************************/

