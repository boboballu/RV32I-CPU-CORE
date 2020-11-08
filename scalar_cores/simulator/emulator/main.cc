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
    //emulator_child emu (1, 65540, 65548, 0x40000);
    emulator_child emu (1, ((4*1024*1024)+4), ((4*1024*1024)+8), (4*1024*1024));
    
    // read file and populate ram
    emu.load_mem (argv[1]);
    // dump read memory
    // emu.dump_mem (argv[2]);
    printf("memory loading done - Start execution\n\n");

    // execute until exit
    emu.pc = 0; // initialize pc
    emu.risc_cpu();
}