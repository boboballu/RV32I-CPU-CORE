// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdio.h>
#include <iostream>
#include "tb_functions.h"
using namespace std;

// turn on trace or not?
bool vcdTrace = false;
VerilatedVcdC* tfp = NULL;

uint64_t main_time = 0;       // Current simulation time // uint64_t type

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

int main(int argc, char** argv) {
    // Remember args
    Verilated::commandArgs(argc, argv);

    tb tb1(10000000, 65548, 65540); // (exeTime, haltAddr, consoleAddr)

    if (vcdTrace) {
        Verilated::traceEverOn(true);
        
        tfp = new VerilatedVcdC;
        tb1.uut->trace(tfp, 99);

        string vcdname = argv[0]; // executable name
        vcdname += ".vcd";
        cout << vcdname << endl;
        tfp->open(vcdname.c_str());
    }

    switch (atoi(argv[3])) {
        case 1: main_time = tb1.simulate_rtl(Verilated::gotFinish(), tfp); break;               // RTL simulation
        case 2: tb1.simulate_emu(Verilated::gotFinish(), argv[2]); break;                       // EMU simulation
        case 3: main_time = tb1.compare_simulation(Verilated::gotFinish(), argv[2], tfp); break;// RTL EMU compare
        default: printf("wrong case: %s\n", argv[3]); 
    }
    //main_time = tb1.simulate_rtl(Verilated::gotFinish(), tfp);
    main_time = tb1.compare_simulation(Verilated::gotFinish(), argv[2], tfp);

    if (tfp != NULL) {
        tfp->close();
        delete tfp;
    }
    return 0;
}
