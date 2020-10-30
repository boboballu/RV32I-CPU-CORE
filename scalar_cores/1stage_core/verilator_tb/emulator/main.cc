#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "emulator.h"
#include "emulator_child.h"

int main (int argc, char* argv[]) 
{   
    emulator_child emu (1, 65540, 65548);
    // read file and populate ram
    emu.load_mem (argv[1]);

    // execute until exit
    emu.pc = 0; // initialize pc
    emu.risc_cpu();

}