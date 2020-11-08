
// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "emulator.h"
#include "emulator_child.h"

emulator_child::emulator_child (bool emuOutput, uint32_t consoleAddr, uint32_t haltAddr, uint32_t ramSize) : emulator(emuOutput, consoleAddr, haltAddr, ramSize) {}

int emulator_child::load_mem (const char* filename) {
    uint32_t ptr = 0;
    std::ifstream trace;
    uint32_t trace_instn = 0;
    std::string trace_instn_str;

    trace.open(filename);
    if (!trace.good()) {
        printf("Unable to read trace file : %s\n", filename);
        exit(0);
    }
    while (trace>>trace_instn_str) {
        std::stringstream ss;
        if (trace_instn_str.find("@") != std::string::npos) {
            if (enable_emu_output) { std::cout << "section: " << trace_instn_str <<std::endl; }
            trace_instn_str.erase (0, 1);
            ss << std::hex << trace_instn_str;
            ss >> ptr;
        }
        else {
            // convert hex in trace_instn_str to integer
            ss << std::hex << trace_instn_str;
            ss >> trace_instn;

            // printf("%08x\n", trace_instn);            
            if (ptr > RAM_SIZE) {
                if (enable_emu_output) { std::cout << "program exceeds RAM size" <<std::endl; }
                exit(0);
                return 0;
            }
            put_insn32(ptr, trace_instn);
            ptr = ptr + 4;
        }
    }

    trace.close();
}

int emulator_child::risc_cpu ()
{
    while (1) {
        next_pc = pc + 4;
        insn = get_insn32(pc);
        execute_instruction();
        // printf("PC: %08x | Instn %08x\n", pc, insn);
        pc = next_pc;
    }
    return 0;
}

int emulator_child::dump_mem (const char* filename) {
    std::ofstream mem_dump;
    mem_dump.open(filename, std::ofstream::out);
    for (int i=0; i<RAM_SIZE; i=i+4) {
        uint32_t ret_insn = get_insn32(i);
        mem_dump<<"ptr: "<<std::hex<<std::setw(8)<<std::setfill('0')<<i<<" ";
        mem_dump<<"instn: "<<std::hex<<std::setw(8)<<std::setfill('0')<<ret_insn<<std::endl;
    }
    mem_dump.close();
}