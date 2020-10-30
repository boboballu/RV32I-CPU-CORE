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

#define CONSOLE_FORMAT "%c" // %d
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

    
    // c++ emulator
    emulator_child* emu = new emulator_child(0, 65540, 65548);
    emu->load_mem(argv[2]);
    

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
 
        // print the output
        // if ((uut->memwrite) & (!uut->clk)) {
        //     if ((uut->dataadr == CONSOLE_ADDR)) {
        //         printf(CONSOLE_FORMAT, uut->writedata); fflush(stdout); // flush the io file buffer everytime
        //     }
        //     else if (uut->dataadr == HALT_ADDR) {
        //         printf("\n\n");
        //         exit(0);
        //     }
        // }

        // emulator
        if ((uut->clk) & (main_time > 14)) {
            emu->next_pc = emu->pc + 4;
            emu->insn = emu->get_insn32(emu->pc);
            emu->execute_instruction();
        }
        if ((!uut->clk) & (main_time > 14)) {
            // rtl simulation dump
            printf("rtl pc: %08x emu pc %08x instn: %08x\n", uut->pc, emu->pc, uut->instr);

            //emulation dump
            // printf("pc: %08x instn: %08x\n", emu.pc, emu.insn);

            // compare reg file, pc, instns
            int rf_index;
            for (rf_index=1; rf_index<32; rf_index++) {
                if( uut->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[rf_index] != emu->reg[rf_index]) {
                    break;
                }
            }
            if (rf_index != 32) {
                printf("Reg file mismatch: R%d | pc: %08x |\n", rf_index, uut->pc);
                printf("RTL regfile content\n");
                for (int i=1; i<32; i++) {
                    printf("R%d  %d\n", i, uut->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[i]);
                }
                printf("Emu regfile content\n");
                for (int i=1; i<32; i++) {
                    printf("R%d  %d\n", i, emu->reg[i]);
                }
                cin.get();
            }

        }
        
        emu->pc = emu->next_pc;

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
