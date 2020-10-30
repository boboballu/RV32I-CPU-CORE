#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "emulator.h"
#include "emulator_child.h"

emulator_child::emulator_child (bool emuOutput, uint32_t consoleAddr, uint32_t haltAddr) : emulator(emuOutput, consoleAddr, haltAddr) {}

int emulator_child::load_mem (const char* filename) {
    uint32_t ptr = 0;
    std::ifstream trace;
    uint32_t trace_instn = 0;

    trace.open(filename);
    if (!trace.good()) {
        printf("Unable to read trace file : %s\n", filename);
        exit(0);
    }
    while (trace>>std::hex>>trace_instn) {
        if (ptr > RAM_SIZE) {
            return 0;
            break;
        }
        put_insn32(ptr, trace_instn);
        ptr = ptr + 4;
    }

    trace.close();
}

int emulator_child::risc_cpu ()
{
    while (1) {
        next_pc = pc + 4;
        insn = get_insn32(pc);
        execute_instruction();
        pc = next_pc;
    }
    return 0;
}