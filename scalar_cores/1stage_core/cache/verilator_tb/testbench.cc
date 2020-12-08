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

// memory class model
#define BLOCKS 4
class memory {
public: 
    uint32_t rd=0, rd_miss=0;
    uint32_t wr=0, wr_miss=0;

    uint32_t wb, mem_tr;
    uint32_t cache_read (bool req, uint32_t addr, bool byte_mask[4]) {
        rd++;
        if ((!uut->clock) & (main_time > 14)) {
            uut->addr = addr;
            uut->req = req;
            uut->byte_mask = byte_mask;
        }
        if ((uut->clock) & (main_time > 14)) {
            if (uut->req & uut->miss & (!uut->mem_miss)) {
                rd_miss++;
            }
        }
    }
    uint32_t* mem_trans (bool mem_req,  bool mem_we, uint32_t mem_read_addr) {
        if (mem_req) {
            mem_tr++;
            if (mem_we) {
                wb++;
            }
        }
        static uint32_t ret [BLOCKS];
        // set the seed
        srand( (unsigned)time( NULL ) );
        if (mem_req) {
            for (int i=0; i<BLOCKS; i++) {
                ret[i] = rand();
            }
        }
        return ret;
    }
};

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

    uut->req = 0; uut->we = 0; uut->addr = 0; uut->byte_mask = 0; 
    uut->write_word = 0;

    uut->eval();
    // end


    printf("==> Cache perfomance simulation - RTL <==\n\n");
    
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
 
        // emulator
        if ((uut->clock) & (main_time > 14)) {

        }
        if ((!uut->clock) & (main_time > 14)) {
        }
        
        // stop simulation
        if (uut->dataadr == HALT_ADDR) {
                printf("\n\n");
                exit(0);
        }

        if (tfp != NULL){ // for vcd
            tfp->dump (main_time);
        }

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
