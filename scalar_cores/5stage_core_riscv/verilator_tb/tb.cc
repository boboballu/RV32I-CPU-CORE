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

    main_time = tb1.simulate_rtl(Verilated::gotFinish(), tfp);
    // Comparitive testbench is not complete for 5stagecore
    // main_time = tb1.compare_simulation(Verilated::gotFinish(), argv[2], tfp);

    if (tfp != NULL) {
        tfp->close();
        delete tfp;
    }
    return 0;
}
