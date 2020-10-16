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

enum instn_type {
    LUI, AUIPC,
    JAL, JALR,
    BEQ, BNE, BLT, BGE, BLTU, BGEU,
    LB, LH, LW, LBU, LHU,
    SB, SH, SW,
    ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI,
    ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
};

struct instn_info {
    uint32_t pc;
    uint32_t bin;
    uint32_t op, funct3, funct7;
    instn_type  type;
    int32_t     rs;
    int32_t     rt;
    int32_t     rd;
    int32_t     imm;
    uint32_t    target;
    bitset <32> jumpimm, branchimm, utypeimm, stypeimm, itypeimm;
};

// tried funct_sim and pipe_sim, where pipe_sim class is a derived class of funct_sim
// ran into hell a lot of issues in accessing maps. 
// all the out-of-boundary reads ran into seg faults
// this setup is fine since there is only one object created, which creates maps in heap
// multiple classes and objects will create seg fault after set fault

class funct_sim {
public:
    char instn_type_str[37][10] {
        "LUI", "AUIPC",
        "JAL", "JALR",
        "BEQ", "BNE", "BLT", "BGE", "BLTU", "BGEU",
        "LB", "LH", "LW", "LBU", "LHU",
        "SB", "SH", "SW",
        "ADDI", "SLTI", "SLTIU", "XORI", "ORI", "ANDI", "SLLI", "SRLI", "SRAI",
        "ADD", "SUB", "SLL", "SLT", "SLTU", "XOR", "SRL", "SRA", "OR", "AND"
    };

    map<uint32_t, instn_info> Imem;
    map<uint32_t, uint32_t> Dmem;
    uint32_t Reg[32];

    // records total number of cycles taken to run till the end 
    uint32_t cycle;
    uint32_t runtime;
    uint32_t pc;
    instn_info getInstnInfo(uint32_t pc, uint32_t instn);
    uint32_t sim_functional(uint32_t pc, instn_info instn); // returns next pc
    void printImem();
    void printDmem();
    void printReg();
    stringstream disassemble_instn(uint32_t instn);
    // constructor
    funct_sim() {
        for (int i=0; i < 32; i++) {
            Reg[i] = 0;
        } 
    }
};

#endif