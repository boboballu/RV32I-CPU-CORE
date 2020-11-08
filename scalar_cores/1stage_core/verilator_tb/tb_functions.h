// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#ifndef _TB_FINCTIONS_H_
#define _TB_FINCTIONS_H_
#define CONSOLE_FORMAT "%c" // %d

// Defines common routines
#include <verilated.h>
#include "Vtop.h"
#include "verilated_vcd_c.h"

#include "./emulator/emulator.h"
#include "./emulator/emulator_child.h"


class tb {
private:
    uint32_t EXE_TIME= 10000000;
    uint32_t HALT_ADDR= 65548;
    uint32_t CONSOLE_ADDR= 65540;

public:
    vluint64_t main_time = 0;       // Current simulation time

    emulator_child* emu;            // emulator class
    Vtop *uut;                      // RTL top module

    tb();
    tb(uint32_t exeTime, uint32_t haltAddr, uint32_t consoleAddr);
    void simulate_emu(bool gotFinish, const char* filename);
    uint64_t simulate_rtl(bool gotFinish, VerilatedVcdC* tfp);
    uint64_t compare_simulation(bool gotFinish, const char* filename, VerilatedVcdC* tfp);
    //~tb();
};
#endif