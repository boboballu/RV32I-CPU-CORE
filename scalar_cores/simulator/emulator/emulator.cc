#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "emulator.h"
//#define CONSOLE_PRINT_AND_EXIT

uint32_t emulator::get_insn32(uint32_t pc)
{
    uint32_t ptr = pc;
    if (ptr > RAM_SIZE) return 1;
    uint8_t* p = ram + ptr;
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}

int emulator::put_insn32(uint32_t pc, uint32_t insn32)
{
    uint32_t ptr = pc;
    if ( (ptr > RAM_SIZE) | (ptr & 3) ) return 1;
    ram[ptr] =   (uint8_t) ( insn32 & (0x000000ff) );
    ram[ptr+1] = (uint8_t) ((insn32 & (0x0000ff00))>>8);
    ram[ptr+2] = (uint8_t) ((insn32 & (0x00ff0000))>>16);
    ram[ptr+3] = (uint8_t) ((insn32 & (0xff000000))>>24);
    return 0;
}

int emulator::target_read_u8(uint8_t *pval, uint32_t addr)
{
    if (addr > RAM_SIZE) {
        *pval = 0;
        printf("illegal read 8, PC: 0x%08x, address: 0x%08x\n", pc, addr);
        return 1;
    } else {
        uint8_t* p = ram + addr;
        *pval = p[0];
    }
    return 0;
}

int emulator::target_read_u16(uint16_t *pval, uint32_t addr)
{
    if (addr & 1) {
        raise_exception(CAUSE_MISALIGNED_LOAD, insn);
    }

    if (addr > RAM_SIZE)  {
        *pval = 0;
        printf("illegal read 16, PC: 0x%08x, address: 0x%08x\n", pc, addr);
        return 1;
    } else {
        uint8_t* p = ram + addr;
        *pval = p[0] | (p[1] << 8);
    }
    return 0;
}

int emulator::target_read_u32(uint32_t *pval, uint32_t addr)
{
    if (addr & 3) {
        raise_exception(CAUSE_MISALIGNED_LOAD, insn);
    }

    if (addr > RAM_SIZE) {
        *pval = 0;
        printf("illegal read 32, PC: 0x%08x, address: 0x%08x\n", pc, addr);
        return 1;
    } else {
        uint8_t* p = ram + addr;
        *pval = p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    }
    return 0;
}

int emulator::target_write_u8(uint32_t addr, uint8_t val)
{
    if (addr > RAM_SIZE - 1) {
        printf("illegal write 8, PC: 0x%08x, address: 0x%08x\n", pc, addr);
        return 1;
    } else {
        uint8_t* p = ram + addr;
        p[0] = val & 0xff;
    }
    return 0;
}

int emulator::target_write_u16(uint32_t addr, uint16_t val)
{
    if (addr & 1) {
        raise_exception(CAUSE_MISALIGNED_STORE, insn);
    }
    if (addr > RAM_SIZE - 2) {
        printf("illegal write 16, PC: 0x%08x, address: 0x%08x\n", pc, addr);
        return 1;
    } else {
        uint8_t* p = ram + addr;
        p[0] = val & 0xff;
        p[1] = (val >> 8) & 0xff;
    }
    return 0;
}


int emulator::target_write_u32(uint32_t addr, uint32_t val)
{
    #ifdef CONSOLE_PRINT_AND_EXIT
    if ((addr) == __CONSOLE_OUTPUT) {
        // test for UART output, compatible with QEMU
        printf("%c", (char) val);
        return 0;
    }
    else if (addr == __HALT_ADDR) {
        printf("\n");
        exit(0);
    }
    #endif
    if (addr > RAM_SIZE - 4)  {
        return 1;
    } else {
        uint8_t* p = ram + addr;
        p[0] = val & 0xff;
        p[1] = (val >> 8) & 0xff;
        p[2] = (val >> 16) & 0xff;
        p[3] = (val >> 24) & 0xff;
    }
    return 0;
}


int32_t div32(int32_t a, int32_t b)
{
    if (b == 0) {
        return -1;
    } else if (a == ((int32_t)1 << (XLEN - 1)) && b == -1) {
        return a;
    } else {
        return a / b;
    }
}

uint32_t divu32(uint32_t a, uint32_t b)
{
    if (b == 0) {
        return -1;
    } else {
        return a / b;
    }
}

int32_t rem32(int32_t a, int32_t b)
{
    if (b == 0) {
        return a;
    } else if (a == ((int32_t)1 << (XLEN - 1)) && b == -1) {
        return 0;
    } else {
        return a % b;
    }
}

uint32_t remu32(uint32_t a, uint32_t b)
{
    if (b == 0) {
        return a;
    } else {
        return a % b;
    }
}

static uint32_t mulh32(int32_t a, int32_t b)
{
    return ((int64_t)a * (int64_t)b) >> 32;
}

static uint32_t mulhsu32(int32_t a, uint32_t b)
{
    return ((int64_t)a * (int64_t)b) >> 32;
}

static uint32_t mulhu32(uint32_t a, uint32_t b)
{
    return ((int64_t)a * (int64_t)b) >> 32;
}


void emulator::raise_exception(uint32_t cause, uint32_t val) {
    printf("Exception : cause : %u | instn %08x\n", cause, val);
    exit(1);
}

void emulator::execute_instruction()
{
    uint32_t opcode, rd, rs1, rs2, funct3;
    int32_t imm, cond, err;
    uint32_t addr, val, val2;

    opcode = insn & 0x7f;
    rd = (insn >> 7) & 0x1f;
    rs1 = (insn >> 15) & 0x1f;
    rs2 = (insn >> 20) & 0x1f;

    switch(opcode) {
    case 0x37: /* lui */
        if (rd != 0)
            reg[rd] = (int32_t)(insn & 0xfffff000);
        break;
    case 0x17: /* auipc */
        if (rd != 0)
            reg[rd] = (int32_t)(pc + (int32_t)(insn & 0xfffff000));
        break;
    case 0x6f: /* jal */
        imm = ((insn >> (31 - 20)) & (1 << 20)) |
              ((insn >> (21 - 1)) & 0x7fe) |
              ((insn >> (20 - 11)) & (1 << 11)) |
              (insn & 0xff000);
        imm = (imm << 11) >> 11;
        if (rd != 0)
            reg[rd] = pc + 4;
        next_pc = (int32_t)(pc + imm);
        break;
    case 0x67: /* jalr */
        imm = (int32_t)insn >> 20;
        val = pc + 4;
        next_pc = (int32_t)(reg[rs1] + imm) & ~1;
        if (rd != 0)
            reg[rd] = val;
        break;
    case 0x63:
        funct3 = (insn >> 12) & 7;
        switch(funct3 >> 1) {
        case 0: /* beq/bne */
            cond = (reg[rs1] == reg[rs2]);
            break;
        case 2: /* blt/bge */
            cond = ((int32_t)reg[rs1] < (int32_t)reg[rs2]);
            break;
        case 3: /* bltu/bgeu */
            cond = (reg[rs1] < reg[rs2]);
            break;
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        cond ^= (funct3 & 1);
        if (cond) {
            imm = ((insn >> (31 - 12)) & (1 << 12)) |
                  ((insn >> (25 - 5)) & 0x7e0) |
                  ((insn >> (8 - 1)) & 0x1e) |
                  ((insn << (11 - 7)) & (1 << 11));
            imm = (imm << 19) >> 19;
            next_pc = (int32_t)(pc + imm);
            break;
        }
        break;
    case 0x03: /* load */
        funct3 = (insn >> 12) & 7;
        imm = (int32_t)insn >> 20;
        addr = reg[rs1] + imm;
        switch(funct3) {
        case 0: /* lb */
        {
            uint8_t rval;
            if (target_read_u8(&rval, addr)) {
                raise_exception(CAUSE_FAULT_LOAD, insn);
                return;
            }
            val = (int8_t)rval;
        }
        break;
        case 1: /* lh */
        {
            uint16_t rval;
            if (target_read_u16(&rval, addr)) {
                raise_exception(CAUSE_FAULT_LOAD, insn);
                return;
            }
            val = (int16_t)rval;
        }
        break;
        case 2: /* lw */
        {
            uint32_t rval;
            if (target_read_u32(&rval, addr)) {
                raise_exception(CAUSE_FAULT_LOAD, insn);
                return;
            }
            val = (int32_t)rval;
        }
        break;
        case 4: /* lbu */
        {
            uint8_t rval;
            if (target_read_u8(&rval, addr)) {
                raise_exception(CAUSE_FAULT_LOAD, insn);
                return;
            }
            val = rval;
        }
        break;
        case 5: /* lhu */
        {
            uint16_t rval;
            if (target_read_u16(&rval, addr)) {
                raise_exception(CAUSE_FAULT_LOAD, insn);
                return;
            }
            val = rval;
        }
        break;
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        if (rd != 0)
            reg[rd] = val;
        break;
    case 0x23: /* store */
        funct3 = (insn >> 12) & 7;
        imm = rd | ((insn >> (25 - 5)) & 0xfe0);
        imm = (imm << 20) >> 20;
        addr = reg[rs1] + imm;
        val = reg[rs2];
        switch(funct3) {
        case 0: /* sb */
            if (target_write_u8(addr, val)) {
                raise_exception(CAUSE_FAULT_STORE, insn);
                return;
            }
            break;
        case 1: /* sh */
            if (target_write_u16(addr, val)) {
                raise_exception(CAUSE_FAULT_STORE, insn);
                return;
            }
            break;
        case 2: /* sw */
            if (target_write_u32(addr, val)) {
                raise_exception(CAUSE_FAULT_STORE, insn);
                return;
            }
            break;
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        
        break;

    case 0x13:
        funct3 = (insn >> 12) & 7;
        imm = (int32_t)insn >> 20;
        switch(funct3) {
        case 0: /* addi */
            val = (int32_t)(reg[rs1] + imm);
            break;
        case 1: /* slli */
            if ((imm & ~(XLEN - 1)) != 0) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            val = (int32_t)(reg[rs1] << (imm & (XLEN - 1)));
            break;
        case 2: /* slti */
            val = (int32_t)reg[rs1] < (int32_t)imm;
            break;
        case 3: /* sltiu */
            val = reg[rs1] < (uint32_t)imm;
            break;
        case 4: /* xori */
            val = reg[rs1] ^ imm;
            break;
        case 5: /* srli/srai */
            if ((imm & ~((XLEN - 1) | 0x400)) != 0) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            if (imm & 0x400)
                val = (int32_t)reg[rs1] >> (imm & (XLEN - 1));
            else
                val = (int32_t)((uint32_t)reg[rs1] >> (imm & (XLEN - 1)));
            break;
        case 6: /* ori */
            val = reg[rs1] | imm;
            break;
        default:
        case 7: /* andi */
            val = reg[rs1] & imm;
            break;
        }
        if (rd != 0)
            reg[rd] = val;
        break;

    case 0x33:
        imm = insn >> 25;
        val = reg[rs1];
        val2 = reg[rs2];
        
        // M - type instns | Multiply and Divide
        #ifdef M_TYPE_ISA
        if (imm == 1) {
            funct3 = (insn >> 12) & 7;
            switch(funct3) {
        
            case 0: /* mul */
                val = (int32_t)((int32_t)val * (int32_t)val2);
                break;
            case 1: /* mulh */
                val = (int32_t)mulh32(val, val2);
                break;
            case 2:/* mulhsu */
                val = (int32_t)mulhsu32(val, val2);
                break;
            case 3:/* mulhu */
                val = (int32_t)mulhu32(val, val2);
                break;
            case 4:/* div */
                val = div32(val, val2);
                break;
            case 5:/* divu */
                val = (int32_t)divu32(val, val2);
                break;
            case 6:/* rem */
                val = rem32(val, val2);
                break;
            case 7:/* remu */
                val = (int32_t)remu32(val, val2);
                break;
            default:
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
        } else
        #endif 
        {
            if (imm & ~0x20) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            funct3 = ((insn >> 12) & 7) | ((insn >> (30 - 3)) & (1 << 3));
            switch(funct3) {
            case 0: /* add */
                val = (int32_t)(val + val2);
                break;
            case 0 | 8: /* sub */
                val = (int32_t)(val - val2);
                break;
            case 1: /* sll */
                val = (int32_t)(val << (val2 & (XLEN - 1)));
                break;
            case 2: /* slt */
                val = (int32_t)val < (int32_t)val2;
                break;
            case 3: /* sltu */
                val = val < val2;
                break;
            case 4: /* xor */
                val = val ^ val2;
                break;
            case 5: /* srl */
                val = (int32_t)((uint32_t)val >> (val2 & (XLEN - 1)));
                break;
            case 5 | 8: /* sra */
                val = (int32_t)val >> (val2 & (XLEN - 1));
                break;
            case 6: /* or */
                val = val | val2;
                break;
            case 7: /* and */
                val = val & val2;
                break;
            default:
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
        }
        if (rd != 0)
            reg[rd] = val;
        break;

    // csr instructions
    #ifdef CSR_ISA
    {
    case 0x73:
        funct3 = (insn >> 12) & 7;
        imm = insn >> 20;
        if (funct3 & 4)
            val = rs1;
        else
            val = reg[rs1];
        funct3 &= 3;
        switch(funct3) {
        case 1: /* csrrw */
            if (csr_read(&val2, imm, true)) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            val2 = (int32_t)val2;
            err = csr_write(imm, val);
            if (err < 0) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            if (rd != 0)
                reg[rd] = val2;
            if (err > 0) {
                //pc = pc + 4;
            }
            break;
        case 2: /* csrrs */
        case 3: /* csrrc */
            if (csr_read(&val2, imm, (rs1 != 0))) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            val2 = (int32_t)val2;
            if (rs1 != 0) {
                if (funct3 == 2)
                    val = val2 | val;
                else
                    val = val2 & ~val;
                err = csr_write(imm, val);
                if (err < 0) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
            } else {
                err = 0;
            }
            if (rd != 0)
                reg[rd] = val2;
            break;
        case 0:
            switch(imm) {
            case 0x000: /* ecall */
                if (insn & 0x000fff80) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                // compliance test specific: if bit 0 of gp (x3) is 0, it is a syscall,
                // otherwise it is the program end, with the exit code in the bits 31:1
                if (begin_signature) {
                    if (reg[3] & 1) {
#ifdef DEBUG_OUTPUT
                        printf("program end, result: %04x\n", reg[3] >> 1);
#endif
                        machine_running = false;
                        return;
                    } else {
#ifdef DEBUG_OUTPUT
                        printf("syscall: %04x\n", reg[3]);
#endif
                        raise_exception(CAUSE_USER_ECALL + priv, 0);
                    }
                } else {
                    // on real hardware, an exception is raised, the I-ECALL-01 compliance test tests this as well
                    raise_exception(CAUSE_USER_ECALL + priv, 0);
                    return;
                }
                break;

            case 0x001: /* ebreak */
                if (insn & 0x000fff80) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                raise_exception(CAUSE_BREAKPOINT, 0);
                return;
            case 0x102: /* sret */
            {
                if ((insn & 0x000fff80) || (priv < PRV_S)) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                handle_sret();
                return;
            }
            break;
            case 0x105: /* wfi */
                // wait for interrupt: it is allowed to execute it as nop
                break;
            case 0x302: /* mret */
            {
                if ((insn & 0x000fff80) || (priv < PRV_M)) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                handle_mret();
                return;
            }
            break;
            default:
                if ((imm >> 5) == 0x09) {
                    /* sfence.vma */
                    if ((insn & 0x00007f80) || (priv == PRV_U)) {
                        raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                        return;
                    }
                } else {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                break;
            }
            break;
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        break;
    }
    #endif

    // fence instns
    #ifdef FENCE_ISA
    case 0x0f: /* misc-mem */
        funct3 = (insn >> 12) & 7;
        switch(funct3) {
        case 0: /* fence */
            if (insn & 0xf00fff80) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            break;
        case 1: /* fence.i */
            if (insn != 0x0000100f) {
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
            break;
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        break;
    #endif
    // atomic instructions
    #ifdef ATOMIC_ISA
    {
    case 0x2f:
        funct3 = (insn >> 12) & 7;
        switch(funct3) {
        case 2:
        {
            uint32_t rval;

            addr = reg[rs1];
            funct3 = insn >> 27;
            switch(funct3) {
            case 2: /* lr.w */
                if (rs2 != 0) {
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                if (target_read_u32(&rval, addr)) {
                    raise_exception(pending_exception, pending_tval);
                    return;
                }
                val = (int32_t)rval;
                load_res = addr;
                break;
            case 3: /* sc.w */
                if (load_res == addr) {
                    if (target_write_u32(addr, reg[rs2])) {
                        raise_exception(pending_exception, pending_tval);
                        return;
                    }
                    val = 0;
                } else {
                    val = 1;
                }
                break;
            case 1: /* amiswap.w */
            case 0: /* amoadd.w */
            case 4: /* amoxor.w */
            case 0xc: /* amoand.w */
            case 0x8: /* amoor.w */
            case 0x10: /* amomin.w */
            case 0x14: /* amomax.w */
            case 0x18: /* amominu.w */
            case 0x1c: /* amomaxu.w */
                if (target_read_u32(&rval, addr)) {
                    raise_exception(pending_exception, pending_tval);
                    return;
                }
                val = (int32_t)rval;
                val2 = reg[rs2];
                switch(funct3) {
                case 1: /* amiswap.w */
                    break;
                case 0: /* amoadd.w */
                    val2 = (int32_t)(val + val2);
                    break;
                case 4: /* amoxor.w */
                    val2 = (int32_t)(val ^ val2);
                    break;
                case 0xc: /* amoand.w */
                    val2 = (int32_t)(val & val2);
                    break;
                case 0x8: /* amoor.w */
                    val2 = (int32_t)(val | val2);
                    break;
                case 0x10: /* amomin.w */
                    if ((int32_t)val < (int32_t)val2)
                        val2 = (int32_t)val;
                    break;
                case 0x14: /* amomax.w */
                    if ((int32_t)val > (int32_t)val2)
                        val2 = (int32_t)val;
                    break;
                case 0x18: /* amominu.w */
                    if ((uint32_t)val < (uint32_t)val2)
                        val2 = (int32_t)val;
                    break;
                case 0x1c: /* amomaxu.w */
                    if ((uint32_t)val > (uint32_t)val2)
                        val2 = (int32_t)val;
                    break;
                default:
                    raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                    return;
                }
                if (target_write_u32(addr, val2)) {
                    raise_exception(pending_exception, pending_tval);
                    return;
                }
                break;
            default:
                raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
                return;
            }
        }
        break;
    
    
        default:
            raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
            return;
        }
        if (rd != 0)
            reg[rd] = val;
        break;
    }
    #endif
    
    default:
        raise_exception(CAUSE_ILLEGAL_INSTRUCTION, insn);
        return;
    }
}
