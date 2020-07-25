#include <verilated.h>          // Defines common routines
#include "Vtop.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

Vtop *uut;            // Instantiation of module
vluint64_t main_time = 0;       // Current simulation time // uint64_t type

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

int main(int argc, char** argv) {
    // turn on trace or not?
    bool vcdTrace = true;
    VerilatedVcdC* tfp = NULL;
    
    Verilated::commandArgs(argc, argv);   // Remember args
    uut = new Vtop;   // Create instance

    uut->eval();
    uut->eval();

    if (vcdTrace) {
        Verilated::traceEverOn(true);
        
        tfp = new VerilatedVcdC;
        uut->trace(tfp, 99);

        std::string vcdname = argv[0]; // executable name
        vcdname += ".vcd";
        std::cout << vcdname << std::endl;
        tfp->open(vcdname.c_str());
    }

    // initial begin states
    uut->clk      = 0;
    uut->reset    = 1;
    uut->eval();
    // end

    // input signal to drive count_in - run-time input!
    vluint64_t inputx=0;

    while (!Verilated::gotFinish()) {
        // Drive reset signal
        if ((main_time > 10) && (main_time < 15)) {
            uut->reset = 0;
        }
        else {
            uut->reset = 1;
        }

        // toggle clock and evaluate
        uut->clk = 1;       // Toggle clock
        uut->eval();        // Evaluate model
        uut->clk = 0;
        uut->eval(); 

        if (tfp != NULL){ // for vcd
            tfp->dump (main_time);
        }
 
        // print the output
        if ((uut->memwrite)) {
            printf("Memwrite!  : addr: %d \n", uut->dataadr);
            if ((uut->dataadr == 65532)) {
                printf("%c", uut->writedata);
            }
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
    uut->final();               // Done simulating

    if (tfp != NULL){
        tfp->close();
        delete tfp;
    }
    delete uut;
    return 0;
}
