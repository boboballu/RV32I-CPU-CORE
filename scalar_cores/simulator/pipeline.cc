// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#include <iostream>
#include <inttypes.h>
#include <bits/stdc++.h>
#include <map>
#include <iterator>
#include <fstream>
#include "simulator.h"
using namespace std;

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
            runtime = cycle;
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
                // Wrong ---Ex stall--- - instn followed by lw with raw dependancy
                // lw stall is identified in decode stage, Hence its decode stall
                if ((stall_cycle < 1) &&
                    (Imem.find(last_pc)->second.type == lw) && 
                    (instn_ppl.find(exe_seq)->second.find(cycle-1)->second == 'D') &&
                    ((Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rs) || 
                    (Imem.find(last_pc)->second.rd == Imem.find(pc)->second.rt))
                    ) 
                {   
                    raw_hazzard = true;
                    stall_cycle++;
                    instn_ppl[exe_seq][cycle] = 'D';
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
    auto pc_iter = debug_pc.begin();
    for (auto iter1 = instn_ppl.begin(); iter1 != instn_ppl.end(); ++iter1) {
        printf("exe_seq: %d; %08x", iter1->first, *pc_iter);

        for (auto iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
            printf(" |%d: %c| ", iter2->first, iter2->second);
        }
        
        printf("\n");
        pc_iter++;
    }
}

void funct_sim::dumppipeline(char *filename) {
    ofstream pipeline;
    pipeline.open(filename);

    char instn_type_str[10][10] = {"nop", "r_r", "addi", "lw", "sw", "beq", "j"};
    char  instn_funct_str[10][10] = {"add", "sub", "AND", "OR", "slt"};
    
    // header for the csv pipeline diagram
    // pc | 1 | 2 | 3 | ...
    pipeline<<"PC"<<","<<"Instruction"<<",";
    for (int i=0; i < runtime; i++) {
        pipeline<<i<<",";
    }
    pipeline<<endl;

    //printing the pipeline 
    auto pc_iter = debug_pc.begin();
    for (auto iter1 = instn_ppl.begin(); iter1 != instn_ppl.end(); ++iter1) {
        // pc goes first in the row
        pipeline<<"0x"<<hex<<*pc_iter<<dec<<",";
        // recnstructed instn goes second in the row
        if (Imem[*pc_iter].type == r_r) {
            pipeline<<instn_funct_str[Imem[*pc_iter].f]<<" ";
        }
        else {
            pipeline<<instn_type_str[Imem[*pc_iter].type]<<" ";
        }

        if (Imem[*pc_iter].rd != -1)
            pipeline<<Imem[*pc_iter].rd<<" ";
        if (Imem[*pc_iter].rs != -1)
            pipeline<<Imem[*pc_iter].rs<<" ";
        if (Imem[*pc_iter].rt != -1)
            pipeline<<Imem[*pc_iter].rt<<" ";
        if ((signed)Imem[*pc_iter].imm != -1)
            pipeline<<(signed)Imem[*pc_iter].imm<<" ";
        if ((signed)Imem[*pc_iter].target != -1)
            pipeline<<Imem[*pc_iter].target<<" ";
        
        pipeline<<",";
        for (int i=0; i<iter1->second.begin()->first; i++) {
            pipeline<<",";
        }
        for (auto iter2 = iter1->second.begin(); iter2 != iter1->second.end(); ++iter2) {
            pipeline<<iter2->second<<",";
        }
        pipeline<<endl;
        pc_iter++;
    }
}