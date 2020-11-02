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

// turn on trace or not?
bool vcdTrace = false;
VerilatedVcdC* tfp = NULL;

#define CONSOLE_FORMAT "%c" // %c
// testbench.cc : variables
uint32_t EXE_TIME = 10000000;
uint32_t HALT_ADDR = 65548;
uint32_t CONSOLE_ADDR = 65540;

using namespace std;

Vtop *uut;                      // Instantiation of module
vluint64_t main_time = 0;       // Current simulation time // uint64_t type

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

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
    uut->clk      = 0;
    uut->reset    = 0;
    uut->eval();
    
    // end
    // input signal to drive count_in - run-time input!
    vluint64_t inputx=0;
    printf("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==\n\n", CONSOLE_ADDR);
    while (!Verilated::gotFinish() & (main_time < EXE_TIME)) {
        // Drive reset signal
        if ((main_time > 10) && (main_time < 15)) {
            uut->reset = 0;
        }
        else {
            uut->reset = 1;
        }

        uut->clk = uut->clk ? 0 : 1;
        uut->eval(); 
        // // // toggle clock and evaluate
        // uut->clk = 1;       // Toggle clock
        // uut->eval();        // Evaluate model
        // uut->clk = 0;
        // uut->eval(); 
 
        // print the output
        if ((uut->memwrite) & (!uut->clk)) {
            // printf("%d\n", main_time);
            // printf("%d : Memwrite!  : addr: %d\n", main_time, uut->dataadr);
            if ((uut->dataadr == CONSOLE_ADDR)) {
                // printf("%d : => %d\n",main_time, uut->writedata);
                printf(CONSOLE_FORMAT, uut->writedata); fflush(stdout); // flush the io file buffer everytime
            }
            else if (uut->dataadr == HALT_ADDR) {
                printf("\n\n");
                exit(0);
            }
        }

        if (tfp != NULL){ // for vcd
            tfp->dump (main_time);
        }

        // // sending realtime input
        // if (uut->count_out == 100) {
        //     scanf("%lu", &inputx);
        //     uut->count_in = inputx;
        //     uut->in_load  = 1;
        // }
        // else {
        //     uut->in_load = 0;
        // }

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
