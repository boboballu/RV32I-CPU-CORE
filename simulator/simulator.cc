#include <iostream>
#include <inttypes.h>
#include <bits/stdc++.h>
#include <map>
#include <iterator>
#include <fstream>
#include "simulator.h"
using namespace std;

ifstream trace;
funct_sim sim1;

int main(int argc, char* argv[]){
    uint32_t trace_intsn = 0;
    uint32_t trace_pc    = 0;
    instn_info trace_instn_info;

    trace.open(argv[1]);
    
    printf("Imem - Populating Imem\n");
    while (trace>>hex>>trace_intsn) {
        trace_instn_info = sim1.getInstnInfo(trace_intsn);
        sim1.Imem.insert({trace_pc,trace_instn_info});
        trace_pc = trace_pc + 4;
    }
    printf("Imem - %lu instns populated\n", sim1.Imem.size());
    sim1.printImem();
    sim1.sim_functional();
    printf("Dmem - %lu addresses used\n", sim1.Dmem.size());
    printf("###Dmem State#############\n");
    sim1.printDmem();
    printf("##########################\n");
    printf("###Register State#########\n");    
    sim1.printReg();
    printf("#####Check Pipeline#######\n");
    sim1.classic5pipeline();
    sim1.printpipeline();
}
