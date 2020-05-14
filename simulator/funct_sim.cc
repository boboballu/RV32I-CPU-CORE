#include <iostream>
#include <inttypes.h>
#include <bits/stdc++.h>
#include <map>
#include <iterator>
#include <fstream>
#include "simulator.h"
using namespace std;

instn_info funct_sim::getInstnInfo(uint32_t instn) {
    instn_info ret;
    // uint32_t funct;
    ret.bin = instn;
    switch (instn >> 26) { // instn[31:26]
        case 0b000000:
            ret.type = r_r;
            ret.rs   = ((0b00000011111000000000000000000000) & instn) >> 21;
            ret.rt   = ((0b00000000000111110000000000000000) & instn) >> 16;
            ret.rd   = ((0b00000000000000001111100000000000) & instn) >> 11;
            // funct = ((0b00000000000000000000000000011111) & instn);
            switch((0b00000000000000000000000000111111) & instn) {
                case 0b100000:
                    ret.f = add;
                    break;
                case 0b100010:
                    ret.f = sub;
                    break;
                case 0b100100:
                    ret.f = AND;
                    break;
                case 0b100101:
                    ret.f = OR;
                    break;
                case 0b101010:
                    ret.f = slt;
                    break;
                default:
                    //ret.f = add;
                    if (instn == 0) {// nop
                        ret.type = nop;
                    }
                    else {
                        assert(0);
                    }
                    break;
            }
            break;

        case 0b100011:
            ret.type = lw;
            ret.rs      = ((0b00000011111000000000000000000000) & instn) >> 21;
            ret.rd      = ((0b00000000000111110000000000000000) & instn) >> 16;
            ret.imm     = ((0b00000000000000001111111111111111) & instn);
            ret.rt      = -1; // no register
            break;
        
        case 0b101011:
            ret.type = sw;
            ret.rs      = ((0b00000011111000000000000000000000) & instn) >> 21;
            ret.rd      = ((0b00000000000111110000000000000000) & instn) >> 16;
            ret.imm     = ((0b00000000000000001111111111111111) & instn);
            ret.rt      = -1; // no register
            break;

        case 0b000100:
            ret.type = beq;
            ret.rs      = ((0b00000011111000000000000000000000) & instn) >> 21;
            ret.rt      = ((0b00000000000111110000000000000000) & instn) >> 16;
            ret.target  = ((0b00000000000000001111111111111111) & instn);
            ret.rd      = -1; // no register
            break;

        case 0b001000:
            ret.type = addi;
            ret.rs      = ((0b00000011111000000000000000000000) & instn) >> 21;
            ret.rd      = ((0b00000000000111110000000000000000) & instn) >> 16;
            ret.imm     = ((0b00000000000000001111111111111111) & instn);
            ret.rt      = -1; // no register
            break;

        case 0b000010:
            ret.type = j;
            ret.rs      = -1;
            ret.rd      = -1;
            ret.target  = ((0b00000011111111111111111111111111) & instn);
            ret.rt      = -1; // no register
            break;       
    }
    return ret;
}

void funct_sim::sim_functional() {
    int pc=0;
    bool inc_pc = true;
    while(1) {
        inc_pc = true;
        if (Imem.find(pc) == Imem.end()) {
            break;
        }
        // exicute the instructions
        // r_r type
        if (Imem[pc].type == r_r) {
            // there sould be source and dest regs for r_r instn type
            assert(Imem[pc].rd != -1);
            assert(Imem[pc].rs != -1);
            assert(Imem[pc].rt != -1);
            // getting the S and T values from the Arch Reg
            uint32_t srca = Reg[Imem[pc].rs];
            uint32_t srcb = Reg[Imem[pc].rt];
            switch (Imem[pc].f) {
                case add:
                    Reg[Imem[pc].rd] = srca + srcb;
                    break;
                case sub:
                    Reg[Imem[pc].rd] = srca - srcb;
                    break;
                case AND:
                    Reg[Imem[pc].rd] = srca & srcb;
                    break;
                case OR:
                    Reg[Imem[pc].rd] = srca | srcb;
                    break;
                case slt:
                    Reg[Imem[pc].rd] = (srca < srcb) ? 1 : 0;
                    break;
                default:
                    assert(0);
                    break;
            }
        }

        else if (Imem[pc].type == lw) {
            // leaving here 2/10/2020 - 12:00 AM
            // load instn has a dest reg
            assert(Imem[pc].rd != -1);
            Reg[Imem[pc].rd] = Dmem[Imem[pc].imm + Reg[Imem[pc].rs]];
        }

        else if (Imem[pc].type == sw) {
            assert(Imem[pc].rt == -1);
            Dmem[Reg[Imem[pc].rs] + Imem[pc].imm] = Reg[Imem[pc].rd];
        }

        else if (Imem[pc].type == addi) {
            if (((Imem[pc].imm >> 15) & 0x01) == 1) {
                Imem[pc].imm = 0xffff0000 | Imem[pc].imm;
            }
            Reg[Imem[pc].rd] = Reg[Imem[pc].rs] + Imem[pc].imm;
        }

        // JUMP INSTRUCTION
        else if (Imem[pc].type == j) {
            pc = (Imem[pc].target<<2);
            inc_pc = false;
        }       

        // BRANCH INSTRUCTION
        else if (Imem[pc].type == beq) {
            if (Reg[Imem[pc].rs] == Reg[Imem[pc].rt]) {
                branch_info[pc] = true;
                pc = pc + (Imem[pc].target<<2);
                
            }
            else {
                branch_info[pc] = false;
            }
            // else pc = pc + 4
        }

        if (inc_pc == true)
            pc = pc+4;
    }
}

void funct_sim::classic5pipeline() {
    bool taken_branch = false;
    bool raw_hazzard = false;
    int stall_cycle = 0;
    uint32_t exe_seq = 0;
    uint32_t cycle = 0;
    uint32_t pc=0;
    bool inc_pc = true;
    bool stage_match = false;
    uint32_t last_pc = 0, last_last_pc = 0;
    char stages[5] = {'F', 'D', 'E', 'M', 'W'};

    while(1) {
        taken_branch = false;
        stall_cycle = 0;
        inc_pc = true;
        
        if (Imem.find(pc) == Imem.end()) {
            break;
        }

        // debug pc
        debug_pc.push_back(pc);

        // start every instn fetch from the prev instn decode cycle
        for (auto iter = instn_ppl.find(exe_seq-1)->second.rbegin(); 
                iter != instn_ppl.find(exe_seq-1)->second.rend();
                iter++)
        {
            if (iter->second == 'D') {
                cycle = iter->first;
            }
        }

        // fetch stall for the instn following a jump instn
        if ((Imem.find(last_pc)->second.type == j)) {
            for (auto iter = instn_ppl.find(exe_seq-1)->second.rbegin(); 
                iter != instn_ppl.find(exe_seq-1)->second.rend();
                iter++)
            {
                if (iter->second == 'D') {
                    printf("::%d\n", iter->first);
                    cycle = iter->first+1;
                    break;
                }
            }
        }

        // instn followed by beq instn
        if ((Imem.find(last_pc)->second.type == beq) && 
            (branch_info.find(last_pc)->second == true))
        {
            for (auto iter = instn_ppl.find(exe_seq-1)->second.rbegin(); 
                iter != instn_ppl.find(exe_seq-1)->second.rend();
                iter++)
            {
                if (iter->second == 'D') {
                    printf("::%d\n", iter->first);
                    cycle = iter->first+1;
                    break;
                }
            }
        }

        for (int i=0; i < strlen(stages); )   {
            // search the map to see if there is an instn conflicting with the stage
            raw_hazzard = false;
            stage_match = false;
            for (auto iter = instn_ppl.begin(); iter != instn_ppl.end(); ++iter) {
                if (iter->second.find(cycle)->second == stages[i]) {
                    stage_match = true;
                    break;
                }
            }
            if (stage_match == false) {
                // Ex stall - instn followed by lw with raw dependancy
                if ((stall_cycle < 1) &&
                    (Imem.find(last_pc)->second.type == lw) && 
                    (instn_ppl.find(exe_seq)->second.find(cycle-1)->second == 'E') &&
                    ((Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rs) || 
                    (Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rt))
                    ) 
                {   
                    raw_hazzard = true;
                    stall_cycle++;
                    instn_ppl[exe_seq][cycle] = 'E';
                }
                // Decode Stall - beq followed by r_r or addi
                if ((stall_cycle < 1) && 
                    ((Imem.find(last_pc)->second.type == r_r) || (Imem.find(last_pc)->second.type == addi)) &&
                    (Imem.find(pc)->second.type == beq) &&
                    (instn_ppl.find(exe_seq)->second.find(cycle-1)->second == 'D') &&
                    ((Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rs) || 
                    (Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rt))
                    )
                {
                    raw_hazzard = true;
                    stall_cycle++;
                    instn_ppl[exe_seq][cycle] = 'D';
                }
            
                // Decode Stall - beq followed by lw
                if ((stall_cycle < 2) &&
                    (Imem.find(last_pc)->second.type == lw) &&
                    (Imem.find(pc)->second.type == beq) &&
                    (instn_ppl.find(exe_seq)->second.find(cycle-1)->second == 'D') &&
                    ((Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rs) || 
                    (Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rt))
                    )
                {
                    raw_hazzard = true;
                    stall_cycle++;
                    instn_ppl[exe_seq][cycle] = 'D';
                }

                // Decode Stall - lw followed by an instn followed by Beq
                if ((stall_cycle < 1) &&
                    (Imem.find(last_last_pc)->second.type == lw) &&
                    (Imem.find(pc)->second.type == beq) &&
                    (instn_ppl.find(exe_seq)->second.find(cycle-1)->second == 'D') &&
                    ((Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rs) || 
                    (Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rt))
                    )
                {
                    raw_hazzard = true;
                    stall_cycle++;
                    instn_ppl[exe_seq][cycle] = 'D';
                }

                if (raw_hazzard == false) {
                        instn_ppl[exe_seq][cycle] = stages[i];
                        i++;
                }
                cycle++;
            }
            else {
                //assert (i-1 > 0);
                if (i-1 < 0) {
                    instn_ppl[exe_seq][cycle] = '_'; // fetch bubble                    
                }
                else {
                    instn_ppl[exe_seq][cycle] = stages[i-1]; // bubble
                }
                cycle++;
            }
        }
        exe_seq++;

        // last_pc and last_last_pc
        last_last_pc = last_pc;
        last_pc = pc;

         // JUMP INSTRUCTION
        if (Imem[pc].type == j) {
            taken_branch = true;
            pc = (Imem[pc].target<<2);
            inc_pc = false;
        }       

        // BRANCH INSTRUCTION
        else if (Imem[pc].type == beq) {
            if (branch_info.find(pc)->second == true) {
                taken_branch = true;
                pc = pc + (Imem[pc].target<<2);
            }
            // else pc = pc + 4
        }

        if (inc_pc == true)
            pc = pc+4;
    }
    
}

void funct_sim::printpipeline() {
    auto iter2 = debug_pc.begin();
    for (auto iter1 = instn_ppl.begin(); iter1 != instn_ppl.end(); ++iter1) {
        printf("exe_seq: %d; %08x", iter1->first, *iter2);
        iter2++;
        for (auto iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
            printf(" |%d: %c| ", iter2->first, iter2->second);
        }
        printf("\n");
    }
}

void funct_sim::printImem() {
    map<uint32_t, instn_info>::iterator itr;
    char instn_type_str[10][10] = {"nop", "r_r", "addi", "lw", "sw", "beq", "j"};
    char  instn_funct_str[10][10] = {"add", "sub", "AND", "OR", "slt"};
    for (itr = Imem.begin(); itr != Imem.end(); ++itr) { 
        if (itr->second.type == r_r) {
        printf("PC : 0x%08x | Bin: 0x%08x | Type: %s | funct: %s\n", 
            itr->first, (itr->second).bin, instn_type_str[(itr->second).type], 
            instn_funct_str[(itr->second).f]);            
        }
        else {
            printf("PC : 0x%08x | Bin: 0x%08x | Type: %s\n", 
                itr->first, (itr->second).bin, instn_type_str[(itr->second).type]);
        }
    }
}

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