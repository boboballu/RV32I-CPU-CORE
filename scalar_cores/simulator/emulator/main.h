#ifndef _MAIN_H
#define _MAIN_H
#include <stdint.h>
#include "emulator.h"

uint32_t pc;
uint32_t next_pc;
uint32_t insn;
uint32_t reg[32];
uint8_t ram[RAM_SIZE];

int load_mem (const char* filename);
int risc_cpu ();

#endif