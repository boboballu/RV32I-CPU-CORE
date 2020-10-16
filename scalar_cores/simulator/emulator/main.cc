#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "emulator.h"

uint32_t pc;
uint32_t next_pc;
uint32_t insn;
uint32_t reg[32];
uint8_t ram[RAM_SIZE];

int load_mem (const char* filename);
int risc_cpu ();

int main (int argc, char* argv[]) 
{
    // read file and populate ram
    load_mem (argv[1]);

    // execute until exit
    pc = 0; // initialize pc
    risc_cpu();

} 

int load_mem (const char* filename) {
    uint32_t ptr = 0;
    std::ifstream trace;
    uint32_t trace_instn = 0;

    trace.open(filename);
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

int risc_cpu ()
{
    while (1) {
        next_pc = pc + 4;
        insn = get_insn32(pc);
        execute_instruction();
        pc = next_pc;
    }
    return 0;
}