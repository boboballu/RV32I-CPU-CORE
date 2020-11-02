// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#ifndef _EMULATOR_H_
#define _EMULATOR_H_
#include <stdint.h>

#define DEBUG_OUTPUT
#define XLEN 32
#define RAM_SIZE 0x40000

// ISA EXTENSIONS
// #define M_TYPE_ISA
// #define CSR_ISA
// #define FENCE_ISA
// #define ATOMIC_ISA

// // CPU state
// extern uint32_t pc;
// extern uint32_t next_pc;
// extern uint32_t insn;
// extern uint32_t reg[32];
// // emulator RAM
// extern uint8_t ram[RAM_SIZE];


// exception causes
#define CAUSE_MISALIGNED_FETCH    0x0
#define CAUSE_FAULT_FETCH         0x1
#define CAUSE_ILLEGAL_INSTRUCTION 0x2
#define CAUSE_BREAKPOINT          0x3
#define CAUSE_MISALIGNED_LOAD     0x4
#define CAUSE_FAULT_LOAD          0x5
#define CAUSE_MISALIGNED_STORE    0x6
#define CAUSE_FAULT_STORE         0x7
#define CAUSE_USER_ECALL          0x8
#define CAUSE_SUPERVISOR_ECALL    0x9
#define CAUSE_HYPERVISOR_ECALL    0xa
#define CAUSE_MACHINE_ECALL       0xb
#define CAUSE_FETCH_PAGE_FAULT    0xc
#define CAUSE_LOAD_PAGE_FAULT     0xd
#define CAUSE_STORE_PAGE_FAULT    0xf
#define CAUSE_INTERRUPT  ((uint32_t)1 << 31)

class emulator {
private:
    bool enable_emu_output;
    uint32_t CONSOLE_ADDR;
    uint32_t HALT_ADDR;
    
public:
    // CPU state
    uint32_t pc;
    uint32_t next_pc;
    uint32_t insn;
    uint32_t reg[32];
    // emulator RAM
    uint8_t ram[RAM_SIZE];

    // constructor to define to configs
    emulator(bool emuOutput, uint32_t consoleAddr, uint32_t haltAddr);

    uint32_t get_insn32(uint32_t pc);
    int put_insn32(uint32_t pc, uint32_t insn32);

    int target_read_u8(uint8_t *pval, uint32_t addr);
    int target_read_u16(uint16_t *pval, uint32_t addr);
    int target_read_u32(uint32_t *pval, uint32_t addr);

    int target_write_u8(uint32_t addr, uint8_t val);
    int target_write_u16(uint32_t addr, uint16_t val);
    int target_write_u32(uint32_t addr, uint32_t val);

    void raise_exception(uint32_t cause, uint32_t val);
    void execute_instruction();
};

#endif