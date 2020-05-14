#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <inttypes.h>
#include <bits/stdc++.h>
#include <deque>
#include <map>
#include <iterator>
#include <fstream>

using namespace std;

enum instn_type {nop, r_r, addi, lw, sw, beq, j} ;
enum stage_enum {F, D, E, M, W} ;
enum funct {add, sub, AND, OR, slt};
struct stage_info {
    uint32_t cycle;
    stage_enum stage;
};

struct pipe_info {
    stage_info IF;
    stage_info ID;
    stage_info EX;
    stage_info MEM;
    stage_info WB;
};

struct instn_info {
    uint32_t bin;
    instn_type type;
    int32_t rs;
    int32_t rt;
    int32_t rd;
    funct    f;
    uint32_t imm;
    uint32_t target;
};

struct ret_info {
    instn_info instn;
    pipe_info pipe;
};

class funct_sim {
public:
    ofstream pipeline; // output the pipeline diagram
    map<uint32_t, instn_info> Imem;
    map<uint32_t, uint32_t> Dmem;
    uint32_t Reg[32];
    map<uint32_t, ret_info> retire_instn;
    map<uint32_t, map<uint32_t, char>> instn_ppl;
    map<uint32_t, bool> branch_info;

    // for debugging puropses
    deque<uint32_t> debug_pc;

    uint32_t PC;
    instn_info getInstnInfo(uint32_t instn);
    void sim_functional();
    void printImem();
    void printDmem();
    void printReg();

    // pipeline simulation
    void classic5pipeline();
    void printpipeline();
    // constructor
    funct_sim(char *filename) {
        pipeline.open(filename);
        for (int i=0; i < 32; i++) {
            Reg[i] = 0;
        } 
    }
};

#endif