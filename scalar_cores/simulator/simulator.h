// Author: Tarun Govind Kesavamurthi
// School: North Carolina State University
// mail  : tkesava@ncsu.edu
/********************************************************************************/
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <iostream>
#include <inttypes.h>
#include <bits/stdc++.h>
#include <deque>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>

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


// tried funct_sim and pipe_sim, where pipe_sim class is a derived class of funct_sim
// ran into hell a lot of issues in accessing maps. 
// all the out-of-boundary reads ran into seg faults
// this setup is fine since there is only one object created, which creates maps in heap
// multiple classes and objects will create seg fault after set fault

class funct_sim {
public:
    map<uint32_t, instn_info> Imem;
    map<uint32_t, uint32_t> Dmem;
    uint32_t Reg[32];
    map<uint32_t, ret_info> retire_instn;
    map<uint32_t, map<uint32_t, char>> instn_ppl;
    map<uint32_t, bool> branch_info;

    // for debugging puropses
    deque<uint32_t> debug_pc;

    // records total number of cycles taken to run till the end 
    uint32_t runtime;
    uint32_t PC;
    instn_info getInstnInfo(uint32_t instn);
    void sim_functional();
    void printImem();
    void printDmem();
    void printReg();

    // pipeline simulation
    void classic5pipeline();
    void printpipeline();
    void dumppipeline(char *filename);
    stringstream disassemble_instn(uint32_t pc);
    // constructor
    funct_sim() {
        for (int i=0; i < 32; i++) {
            Reg[i] = 0;
        } 
    }
};

#endif