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

ifstream trace;

int main(int argc, char* argv[]){
    uint32_t trace_intsn = 0;
    uint32_t trace_pc    = 0;
    funct_sim sim1;
    stringstream str1;
    //instn_info trace_instn_info;
    //trace_instn_info = sim1.getInstnInfo(0, atoi(argv[1]));
    str1 = sim1.disassemble_instn ((uint32_t)atoi(argv[1]));
    cout<<str1.str()<<endl;    
    // trace.open(argv[1]);

    // printf("Imem - Populating Imem\n");
    // while (trace>>hex>>trace_intsn) {
    //     trace_instn_info = sim1.getInstnInfo(trace_intsn);
    //     sim1.Imem.insert({trace_pc,trace_instn_info});
    //     trace_pc = trace_pc + 4;
    // }
    // printf("Imem - %lu instns populated\n", sim1.Imem.size());
    // //sim1.printImem();
    // sim1.sim_functional();
    // printf("Dmem - %lu addresses used\n", sim1.Dmem.size());
    // printf("###Dmem State#############\n");
    // sim1.printDmem();
    // printf("##########################\n");
    // printf("###Register State#########\n");    
    // sim1.printReg();
    // printf("#####Check Pipeline#######\n");
    // sim1.classic5pipeline();
    // sim1.printpipeline();
    // sim1.dumppipeline(argv[2]);
}
