// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <iostream>
#include <inttypes.h>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "simulator.h"
using namespace std;

instn_info funct_sim::getInstnInfo(uint32_t pc, uint32_t instn) {
    instn_info ret;
    ret.pc      =   pc;
    ret.bin     =   instn;
    ret.op      =   instn & (0b00000000000000000000000001111111);
    ret.rd      =   (instn & (0b00000000000000000000111110000000)) >> 7;
    ret.funct3  =   (instn & (0b00000000000000000111000000000000)) >> 12;
    ret.rs      =   (instn & (0b00000000000011111000000000000000)) >> 15;
    ret.rt      =   (instn & (0b00000001111100000000000000000000)) >> 20;
    ret.funct7  =   (instn & (0b11111110000000000000000000000000)) >> 25;
    
    bitset <32> temp1(instn);

    ret.jumpimm[0]  = 0        ;       ret.branchimm[0]  = 0        ;        ret.utypeimm[0]  = 0        ;         ret.stypeimm[0]  = temp1[7] ;         ret.itypeimm[0]  = temp1[20];
    ret.jumpimm[1]  = temp1[21];       ret.branchimm[1]  = temp1[8] ;        ret.utypeimm[1]  = 0        ;         ret.stypeimm[1]  = temp1[8] ;         ret.itypeimm[1]  = temp1[21];
    ret.jumpimm[2]  = temp1[22];       ret.branchimm[2]  = temp1[9] ;        ret.utypeimm[2]  = 0        ;         ret.stypeimm[2]  = temp1[9] ;         ret.itypeimm[2]  = temp1[22];
    ret.jumpimm[3]  = temp1[23];       ret.branchimm[3]  = temp1[10];        ret.utypeimm[3]  = 0        ;         ret.stypeimm[3]  = temp1[10];         ret.itypeimm[3]  = temp1[23];
    ret.jumpimm[4]  = temp1[24];       ret.branchimm[4]  = temp1[11];        ret.utypeimm[4]  = 0        ;         ret.stypeimm[4]  = temp1[11];         ret.itypeimm[4]  = temp1[24];
    ret.jumpimm[5]  = temp1[25];       ret.branchimm[5]  = temp1[25];        ret.utypeimm[5]  = 0        ;         ret.stypeimm[5]  = temp1[25];         ret.itypeimm[5]  = temp1[25];
    ret.jumpimm[6]  = temp1[26];       ret.branchimm[6]  = temp1[26];        ret.utypeimm[6]  = 0        ;         ret.stypeimm[6]  = temp1[26];         ret.itypeimm[6]  = temp1[26];
    ret.jumpimm[7]  = temp1[27];       ret.branchimm[7]  = temp1[27];        ret.utypeimm[7]  = 0        ;         ret.stypeimm[7]  = temp1[27];         ret.itypeimm[7]  = temp1[27];
    ret.jumpimm[8]  = temp1[28];       ret.branchimm[8]  = temp1[28];        ret.utypeimm[8]  = 0        ;         ret.stypeimm[8]  = temp1[28];         ret.itypeimm[8]  = temp1[28];
    ret.jumpimm[9]  = temp1[29];       ret.branchimm[9]  = temp1[29];        ret.utypeimm[9]  = 0        ;         ret.stypeimm[9]  = temp1[29];         ret.itypeimm[9]  = temp1[29];
    ret.jumpimm[10] = temp1[30];       ret.branchimm[10] = temp1[30];        ret.utypeimm[10] = 0        ;         ret.stypeimm[10] = temp1[30];         ret.itypeimm[10] = temp1[30];
    ret.jumpimm[11] = temp1[20];       ret.branchimm[11] = temp1[7] ;        ret.utypeimm[11] = 0        ;         ret.stypeimm[11] = temp1[31];         ret.itypeimm[11] = temp1[31];
    ret.jumpimm[12] = temp1[12];       ret.branchimm[12] = temp1[31];        ret.utypeimm[12] = temp1[12];         ret.stypeimm[12] = temp1[31];         ret.itypeimm[12] = temp1[31];
    ret.jumpimm[13] = temp1[13];       ret.branchimm[13] = temp1[31];        ret.utypeimm[13] = temp1[13];         ret.stypeimm[13] = temp1[31];         ret.itypeimm[13] = temp1[31];
    ret.jumpimm[14] = temp1[14];       ret.branchimm[14] = temp1[31];        ret.utypeimm[14] = temp1[14];         ret.stypeimm[14] = temp1[31];         ret.itypeimm[14] = temp1[31];
    ret.jumpimm[15] = temp1[15];       ret.branchimm[15] = temp1[31];        ret.utypeimm[15] = temp1[15];         ret.stypeimm[15] = temp1[31];         ret.itypeimm[15] = temp1[31];
    ret.jumpimm[16] = temp1[16];       ret.branchimm[16] = temp1[31];        ret.utypeimm[16] = temp1[16];         ret.stypeimm[16] = temp1[31];         ret.itypeimm[16] = temp1[31];
    ret.jumpimm[17] = temp1[17];       ret.branchimm[17] = temp1[31];        ret.utypeimm[17] = temp1[17];         ret.stypeimm[17] = temp1[31];         ret.itypeimm[17] = temp1[31];
    ret.jumpimm[18] = temp1[18];       ret.branchimm[18] = temp1[31];        ret.utypeimm[18] = temp1[18];         ret.stypeimm[18] = temp1[31];         ret.itypeimm[18] = temp1[31];
    ret.jumpimm[19] = temp1[19];       ret.branchimm[19] = temp1[31];        ret.utypeimm[19] = temp1[19];         ret.stypeimm[19] = temp1[31];         ret.itypeimm[19] = temp1[31];
    ret.jumpimm[20] = temp1[31];       ret.branchimm[20] = temp1[31];        ret.utypeimm[20] = temp1[20];         ret.stypeimm[20] = temp1[31];         ret.itypeimm[20] = temp1[31];
    ret.jumpimm[21] = temp1[31];       ret.branchimm[21] = temp1[31];        ret.utypeimm[21] = temp1[21];         ret.stypeimm[21] = temp1[31];         ret.itypeimm[21] = temp1[31];
    ret.jumpimm[22] = temp1[31];       ret.branchimm[22] = temp1[31];        ret.utypeimm[22] = temp1[22];         ret.stypeimm[22] = temp1[31];         ret.itypeimm[22] = temp1[31];
    ret.jumpimm[23] = temp1[31];       ret.branchimm[23] = temp1[31];        ret.utypeimm[23] = temp1[23];         ret.stypeimm[23] = temp1[31];         ret.itypeimm[23] = temp1[31];
    ret.jumpimm[24] = temp1[31];       ret.branchimm[24] = temp1[31];        ret.utypeimm[24] = temp1[24];         ret.stypeimm[24] = temp1[31];         ret.itypeimm[24] = temp1[31];
    ret.jumpimm[25] = temp1[31];       ret.branchimm[25] = temp1[31];        ret.utypeimm[25] = temp1[25];         ret.stypeimm[25] = temp1[31];         ret.itypeimm[25] = temp1[31];
    ret.jumpimm[26] = temp1[31];       ret.branchimm[26] = temp1[31];        ret.utypeimm[26] = temp1[26];         ret.stypeimm[26] = temp1[31];         ret.itypeimm[26] = temp1[31];
    ret.jumpimm[27] = temp1[31];       ret.branchimm[27] = temp1[31];        ret.utypeimm[27] = temp1[27];         ret.stypeimm[27] = temp1[31];         ret.itypeimm[27] = temp1[31];
    ret.jumpimm[28] = temp1[31];       ret.branchimm[28] = temp1[31];        ret.utypeimm[28] = temp1[28];         ret.stypeimm[28] = temp1[31];         ret.itypeimm[28] = temp1[31];
    ret.jumpimm[29] = temp1[31];       ret.branchimm[29] = temp1[31];        ret.utypeimm[29] = temp1[29];         ret.stypeimm[29] = temp1[31];         ret.itypeimm[29] = temp1[31];
    ret.jumpimm[30] = temp1[31];       ret.branchimm[30] = temp1[31];        ret.utypeimm[30] = temp1[30];         ret.stypeimm[30] = temp1[31];         ret.itypeimm[30] = temp1[31];
    ret.jumpimm[31] = temp1[31];       ret.branchimm[31] = temp1[31];        ret.utypeimm[31] = temp1[31];         ret.stypeimm[31] = temp1[31];         ret.itypeimm[31] = temp1[31];

    switch (ret.op) {
        case 0b0110111: ret.type = LUI;         break;
        case 0b0010111: ret.type = AUIPC;       break;
        case 0b1101111: ret.type = JAL;         break;
        case 0b1100111: ret.type = JALR;        break;
        case 0b1100011: 
            switch (ret.funct3) {
                case 0b000: ret.type = BEQ;     break;
                case 0b001: ret.type = BNE;     break;
                case 0b100: ret.type = BLT;     break;
                case 0b101: ret.type = BGE;     break;
                case 0b110: ret.type = BLTU;    break;
                case 0b111: ret.type = BGEU;    break; 
            }                                   break;
        case 0b0000011:
            switch (ret.funct3) {
                case 0b000: ret.type = LB;      break;
                case 0b001: ret.type = LH;      break;
                case 0b010: ret.type = LW;      break;
                case 0b100: ret.type = LBU;     break;
                case 0b101: ret.type = LHU;     break;
            }                                   break;
        case 0b0100011:
            switch (ret.funct3) {
                case 0b000: ret.type = SB;      break;
                case 0b001: ret.type = SH;      break;
                case 0b010: ret.type = SW;      break;
            }                                   break;
        case 0b0010011:
            switch (ret.funct3) {
                case 0b000: ret.type = ADDI;    break;
                case 0b010: ret.type = SLTI;    break;   
                case 0b011: ret.type = SLTIU;   break;   
                case 0b100: ret.type = XORI;    break;   
                case 0b110: ret.type = ORI;     break;
                case 0b111: ret.type = ANDI;    break;   
                case 0b001: ret.type = SLLI;    break;   
                case 0b101: 
                    if (ret.funct7 == 0) 
                        ret.type = SRLI; 
                    else 
                        ret.type = SRAI;
                                                break;
            }                                   break;
        case 0b0110011:
            switch (ret.funct3) {
                case 0b000: 
                    if (ret.funct7 == 0)
                        ret.type = ADD;
                    else 
                        ret.type = SUB;
                                                break;
                case 0b001: ret.type = SLL;     break;
                case 0b010: ret.type = SLT;     break;
                case 0b011: ret.type = SLTU;    break;
                case 0b100: ret.type = XOR;     break;
                case 0b101: 
                    if (ret.funct7 == 0)
                        ret.type = SRL;
                    else
                        ret.type = SRA;
                                                break;
                case 0b110: ret.type = OR;      break;
                case 0b111: ret.type = AND;     break;
            }
    }
    return ret;
}

// void funct_sim::sim_functional() {
//     int pc=0;
//     bool inc_pc = true;
//     while(1) {
//         inc_pc = true;
//         if (Imem.find(pc) == Imem.end()) {
//             break;
//         }
//         // exicute the instructions
//         // r_r type
//         if (Imem[pc].type == r_r) {
//             // there sould be source and dest regs for r_r instn type
//             assert(Imem[pc].rd != -1);
//             assert(Imem[pc].rs != -1);
//             assert(Imem[pc].rt != -1);
//             // getting the S and T values from the Arch Reg
//             uint32_t srca = Reg[Imem[pc].rs];
//             uint32_t srcb = Reg[Imem[pc].rt];
//             switch (Imem[pc].f) {
//                 case add:
//                     Reg[Imem[pc].rd] = srca + srcb;
//                     break;
//                 case sub:
//                     Reg[Imem[pc].rd] = srca - srcb;
//                     break;
//                 case AND:
//                     Reg[Imem[pc].rd] = srca & srcb;
//                     break;
//                 case OR:
//                     Reg[Imem[pc].rd] = srca | srcb;
//                     break;
//                 case slt:
//                     Reg[Imem[pc].rd] = (srca < srcb) ? 1 : 0;
//                     break;
//                 default:
//                     assert(0);
//                     break;
//             }
//         }

//         else if (Imem[pc].type == lw) {
//             // leaving here 2/10/2020 - 12:00 AM
//             // load instn has a dest reg
//             assert(Imem[pc].rd != -1);
//             Reg[Imem[pc].rd] = Dmem[Imem[pc].imm + Reg[Imem[pc].rs]];
//         }

//         else if (Imem[pc].type == sw) {
//             assert(Imem[pc].rt == -1);
//             Dmem[Reg[Imem[pc].rs] + Imem[pc].imm] = Reg[Imem[pc].rd];
//         }

//         else if (Imem[pc].type == addi) {
//             if (((Imem[pc].imm >> 15) & 0x01) == 1) {
//                 Imem[pc].imm = 0xffff0000 | Imem[pc].imm;
//             }
//             Reg[Imem[pc].rd] = Reg[Imem[pc].rs] + Imem[pc].imm;
//         }

//         // JUMP INSTRUCTION
//         else if (Imem[pc].type == j) {
//             pc = (Imem[pc].target<<2);
//             inc_pc = false;
//         }       

//         // BRANCH INSTRUCTION
//         else if (Imem[pc].type == beq) {
//             if (Reg[Imem[pc].rs] == Reg[Imem[pc].rt]) {
//                 branch_info[pc] = true;
//                 pc = pc + (Imem[pc].target<<2);
                
//             }
//             else {
//                 branch_info[pc] = false;
//             }
//             // else pc = pc + 4
//         }

//         if (inc_pc == true)
//             pc = pc+4;
//     }
// }

stringstream funct_sim::disassemble_instn (uint32_t instn) {
    stringstream ret;
    instn_info decode_instn = getInstnInfo(0, instn);
    switch (decode_instn.type) {
        case 0 ... 1:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.utypeimm.to_ulong(); break;
        case 2:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<decode_instn.jumpimm.to_ulong(); break;
        case 3:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<decode_instn.rt<<" "<<decode_instn.itypeimm.to_ulong(); break;
        case 4 ... 9:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<decode_instn.rt<<" "<<decode_instn.branchimm.to_ulong(); break;
        case 10 ... 14:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<decode_instn.itypeimm.to_ulong(); break;     
        case 15 ... 17:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rs<<" "<<decode_instn.rt<<" "<<decode_instn.stypeimm.to_ulong(); break;
        case 18 ... 26:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<(int32_t)decode_instn.itypeimm.to_ulong(); break;
        case 27 ... 36:
            ret<<instn_type_str[decode_instn.type]<<" "<<decode_instn.rd<<" "<<decode_instn.rs<<" "<<decode_instn.rd; break;
    }
    return ret;
}


// void funct_sim::printImem() {
//     map<uint32_t, instn_info>::iterator itr;
//     char instn_type_str[10][10] = {"nop", "r_r", "addi", "lw", "sw", "beq", "j"};
//     char  instn_funct_str[10][10] = {"add", "sub", "AND", "OR", "slt"};
//     for (itr = Imem.begin(); itr != Imem.end(); ++itr) { 
//         if (itr->second.type == r_r) {
//         printf("PC : 0x%08x | Bin: 0x%08x | Type: %s | alu_funct: %s\n", 
//             itr->first, (itr->second).bin, instn_type_str[(itr->second).type], 
//             instn_funct_str[(itr->second).f]);            
//         }
//         else {
//             printf("PC : 0x%08x | Bin: 0x%08x | Type: %s\n", 
//                 itr->first, (itr->second).bin, instn_type_str[(itr->second).type]);
//         }
//     }
// }

void funct_sim::printDmem() {
    map<uint32_t, uint32_t>::iterator itr;
    for (itr = Dmem.begin(); itr != Dmem.end(); ++itr) { 
        printf(" Addr: 0x%08x | Data: %d\n", 
            itr->first, (itr->second));
    }
}

void funct_sim::printReg() {
    for (int i=0; i < 32; i++) {
        printf("| R%d : %d |", i, Reg[i]);
        if (((i+1)%4 == 0) && (i != 0))
            printf("\n");
    }
}