// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdio.h>
#include <iostream>
#include "tb_functions.h"
using namespace std;

tb::tb() {
    // Create rtl instance
    uut = new Vtop;
    // initial begin states
    uut->clk      = 0;
    uut->reset    = 0;
    uut->eval();
}

tb::tb(uint32_t exeTime, uint32_t haltAddr, uint32_t consoleAddr) {
    uint32_t EXE_TIME = exeTime;
    uint32_t HALT_ADDR = haltAddr;
    uint32_t CONSOLE_ADDR = consoleAddr;
    // Create rtl instance
    uut = new Vtop;
    // initial begin states
    uut->clk      = 0;
    uut->reset    = 0;
    uut->eval();
}

uint64_t tb::simulate_rtl(bool gotFinish, VerilatedVcdC* tfp) {
    
    printf("==> Console [0x%08x] print - writes to the addr treated as a console print msg <==\n\n", CONSOLE_ADDR);
    
    while (!gotFinish & (main_time < EXE_TIME)) {
        // Drive reset signal
        if ((main_time > 10) && (main_time < 15))
            uut->reset = 0;
        else
            uut->reset = 1;

        uut->clk = uut->clk ? 0 : 1;
        uut->eval(); 

        // print the output
        if ((uut->memwrite) & (!uut->clk)) {
            if ((uut->dataadr == CONSOLE_ADDR)) {
                printf(CONSOLE_FORMAT, uut->writedata); fflush(stdout); // flush the io file buffer everytime
            }
            else if (uut->dataadr == HALT_ADDR) {
                printf("\n\n");
                return (main_time);            
                }
        }
        // for vcd
        if (tfp != NULL){
            tfp->dump (main_time);
        }
        // stop simulation
        if (uut->dataadr == HALT_ADDR) {
                printf("\n\n");
                return (main_time);
        }
        
        // time passes...
        if (uut->clk)
            main_time++;
    }
    // Done simulating
    printf("\n\n");
    uut->final();
    return main_time;
}

void tb::simulate_emu(bool gotFinish, const char* filename) {
    emu = new emulator_child (1, 65540, 65548, 0x40000);
    // read file and populate ram
    emu->load_mem (filename);

    // execute until exit
    emu->pc = 0; // initialize pc
    emu->risc_cpu();
}

uint64_t tb::compare_simulation(bool gotFinish, const char* filename, VerilatedVcdC* tfp) {
    emu = new emulator_child (0, 65540, 65548, 0x40000);
    emu->load_mem (filename);
    emu->pc = 0; // initialize pc

    while (!gotFinish & (main_time < EXE_TIME)) {
        // Drive clock and reset signal
        if ((main_time > 10) && (main_time < 15))
            uut->reset = 0;
        else
            uut->reset = 1;

        uut->clk = uut->clk ? 0 : 1;
        uut->eval(); 

        if (main_time > 14) {
            if (uut->clk) {
                emu->next_pc = emu->pc + 4;
                emu->insn = emu->get_insn32(emu->pc);
                emu->execute_instruction();
            }
            if (!uut->clk) {
                // rtl simulation dump
                printf("rtl pc: %08x | emu pc: %08x | instn: %08x\n", uut->pc, emu->pc, uut->instr);
                
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
        }

        // emu - update pc
        emu->pc = emu->next_pc;
        
        // for vcd
        if (tfp != NULL){
            tfp->dump (main_time);
        }
        // stop simulation
        if (uut->dataadr == HALT_ADDR) {
                printf("\n\n");
                printf("RTL & EMU comparison is successful\n");
                return (main_time);
        }
        
        // time passes...
        if (uut->clk)
            main_time++;
    }
    // done simulating
    printf("\n\n");
    uut->final();
    return main_time;
}
