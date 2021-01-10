// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
/*********************** Verilator Testbench ************************************/

#include <verilated.h>          // Defines common routines
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "./emulator/emulator.h"
#include "./emulator/emulator_child.h"

// turn on trace or not?
bool vcdTrace = false;
VerilatedVcdC* tfp = NULL;

using namespace std;

Vtop *uut;                      // Instantiation of module
vluint64_t main_time = 0;       // Current simulation time // uint64_t type

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

// testbench.cc : variables
uint32_t EXE_TIME = 10000000;

int main(int argc, char** argv) {

    Verilated::commandArgs(argc, argv);   // Remember args
    uut = new Vtop;   // Create instance

    if (vcdTrace) {
        Verilated::traceEverOn(true);
        
        tfp = new VerilatedVcdC;
        uut->trace(tfp, 99);

        string vcdname = argv[0]; // executable name
        vcdname += ".vcd";
        cout << vcdname << endl;
        tfp->open(vcdname.c_str());
    }

    // initial begin states
    uut->clock    = 0;
    uut->reset    = 0;

    uut->eval();
    // end

    printf("==> tb_cache.sv -> Cache perfomance simulation - RTL <==\n\n");
    
    while (!Verilated::gotFinish() & (main_time < EXE_TIME)) {
        // Drive reset signal
        if ((main_time > 10) && (main_time < 15)) {
            uut->reset = 0;
        }
        else {
            uut->reset = 1;
        }

        uut->clock = uut->clock ? 0 : 1;
        uut->eval(); 
 
        main_time++;            // Time passes...
    }
    printf("\n\n");
    uut->final();               // Done simulating

    if (tfp != NULL){
        tfp->close();
        delete tfp;
    }
    delete uut;
    return 0;
}
