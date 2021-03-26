// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "emulator.h"
#include "emulator_child.h"

int main (int argc, char* argv[]) 
{   
    // argument checks - terminates if wrong args are passes //
    // terminate if the argv[1] -> trace file is not present
    std::string console_str;
    if (argc < 2) {
        printf("Error: Insufficient arguments; Eg: \'./executable trace_file_path console_output_dump_file\' is no argv[2] defaults to stdio\n");
        exit(0);
    }
    if (argc == 2)
        console_str = "stdout";
    else if (argc > 2)
        console_str = argv[2];

    std::ifstream file_exists(argv[1]);
    if (!file_exists.good()) {
        printf("Error: Unable to read trace file : %s\n", argv[1]);
        exit(0);
    }
    
    //emulator_child emu (argv[2], 65540, 65548, 0x40000);
    emulator_child emu (console_str, ((4*1024*1024)+4), ((4*1024*1024)+8), (4*1024*1024));
    
    // read file and populate ram
    emu.load_mem (argv[1]);
    // dump read memory
    // emu.dump_mem (argv[2]);

    // execute until exit
    emu.pc = 0; // initialize pc
    emu.risc_cpu();
}