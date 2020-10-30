// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1904,"clk", false,-1);
        tracep->declBit(c+1905,"reset", false,-1);
        tracep->declBus(c+1906,"writedata", false,-1, 31,0);
        tracep->declBus(c+1907,"dataadr", false,-1, 31,0);
        tracep->declBus(c+1908,"readdata", false,-1, 31,0);
        tracep->declBus(c+1909,"pc", false,-1, 31,0);
        tracep->declBus(c+1910,"instr", false,-1, 31,0);
        tracep->declBit(c+1911,"memwrite", false,-1);
        tracep->declBit(c+1904,"top clk", false,-1);
        tracep->declBit(c+1905,"top reset", false,-1);
        tracep->declBus(c+1906,"top writedata", false,-1, 31,0);
        tracep->declBus(c+1907,"top dataadr", false,-1, 31,0);
        tracep->declBus(c+1908,"top readdata", false,-1, 31,0);
        tracep->declBus(c+1909,"top pc", false,-1, 31,0);
        tracep->declBus(c+1910,"top instr", false,-1, 31,0);
        tracep->declBit(c+1911,"top memwrite", false,-1);
        tracep->declBit(c+1919,"top Iwait", false,-1);
        tracep->declBit(c+1919,"top Dwait", false,-1);
        tracep->declBit(c+1887,"top dmem_req", false,-1);
        tracep->declBit(c+1888,"top imem_req", false,-1);
        tracep->declBus(c+1846,"top dmem_mask", false,-1, 3,0);
        tracep->declBit(c+1904,"top riscv_32i clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i reset", false,-1);
        tracep->declBus(c+1909,"top riscv_32i imem_pc_addr", false,-1, 31,0);
        tracep->declBit(c+1888,"top riscv_32i imem_req", false,-1);
        tracep->declBus(c+1910,"top riscv_32i imem_instn", false,-1, 31,0);
        tracep->declBit(c+1919,"top riscv_32i imem_wait", false,-1);
        tracep->declBit(c+1911,"top riscv_32i dmem_we", false,-1);
        tracep->declBus(c+1907,"top riscv_32i dmem_addr", false,-1, 31,0);
        tracep->declBus(c+1906,"top riscv_32i dmem_wd", false,-1, 31,0);
        tracep->declBus(c+1846,"top riscv_32i dmem_mask", false,-1, 3,0);
        tracep->declBit(c+1887,"top riscv_32i dmem_req", false,-1);
        tracep->declBus(c+1908,"top riscv_32i dmem_rd", false,-1, 31,0);
        tracep->declBit(c+1919,"top riscv_32i dmem_wait", false,-1);
        tracep->declBus(c+1889,"top riscv_32i pc_genF_in", false,-1, 31,0);
        tracep->declBus(c+1,"top riscv_32i pc_genF_out", false,-1, 31,0);
        tracep->declBus(c+2,"top riscv_32i pcD", false,-1, 31,0);
        tracep->declBus(c+3,"top riscv_32i pcE", false,-1, 31,0);
        tracep->declBus(c+4,"top riscv_32i pcM", false,-1, 31,0);
        tracep->declBus(c+5,"top riscv_32i pcW", false,-1, 31,0);
        tracep->declBus(c+1910,"top riscv_32i instnF", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i pcplus4F", false,-1, 31,0);
        tracep->declBus(c+1847,"top riscv_32i instnD", false,-1, 31,0);
        tracep->declBus(c+7,"top riscv_32i pcplus4D", false,-1, 31,0);
        tracep->declBus(c+1848,"top riscv_32i jumpimmD", false,-1, 31,0);
        tracep->declBus(c+1849,"top riscv_32i branchimmD", false,-1, 31,0);
        tracep->declBus(c+1850,"top riscv_32i utypeimmD", false,-1, 31,0);
        tracep->declBus(c+1851,"top riscv_32i itypeimmD", false,-1, 31,0);
        tracep->declBus(c+1852,"top riscv_32i stypeimmD", false,-1, 31,0);
        tracep->declBus(c+1890,"top riscv_32i aD", false,-1, 31,0);
        tracep->declBus(c+1891,"top riscv_32i bD", false,-1, 31,0);
        tracep->declBus(c+1853,"top riscv_32i signimmD", false,-1, 31,0);
        tracep->declBus(c+8,"top riscv_32i pcplus4E", false,-1, 31,0);
        tracep->declBus(c+9,"top riscv_32i aE", false,-1, 31,0);
        tracep->declBus(c+10,"top riscv_32i bE", false,-1, 31,0);
        tracep->declBus(c+11,"top riscv_32i signimmE", false,-1, 31,0);
        tracep->declBus(c+12,"top riscv_32i utypeimmE", false,-1, 31,0);
        tracep->declBus(c+13,"top riscv_32i branchimmE", false,-1, 31,0);
        tracep->declBus(c+1912,"top riscv_32i aluoutE", false,-1, 31,0);
        tracep->declBus(c+1854,"top riscv_32i writedataE", false,-1, 31,0);
        tracep->declBus(c+14,"top riscv_32i aluoutM", false,-1, 31,0);
        tracep->declBus(c+15,"top riscv_32i writedataM", false,-1, 31,0);
        tracep->declBus(c+16,"top riscv_32i branchimmM", false,-1, 31,0);
        tracep->declBus(c+1892,"top riscv_32i readdataM", false,-1, 31,0);
        tracep->declBus(c+14,"top riscv_32i aluoutM_out", false,-1, 31,0);
        tracep->declBus(c+17,"top riscv_32i readdataW", false,-1, 31,0);
        tracep->declBus(c+18,"top riscv_32i aluoutW", false,-1, 31,0);
        tracep->declBus(c+19,"top riscv_32i branchimmW", false,-1, 31,0);
        tracep->declBus(c+1855,"top riscv_32i resultW", false,-1, 31,0);
        tracep->declBus(c+1856,"top riscv_32i opD", false,-1, 6,0);
        tracep->declBus(c+1857,"top riscv_32i funct3D", false,-1, 2,0);
        tracep->declBus(c+20,"top riscv_32i funct3E", false,-1, 2,0);
        tracep->declBus(c+21,"top riscv_32i funct3M", false,-1, 2,0);
        tracep->declBus(c+22,"top riscv_32i funct3W", false,-1, 2,0);
        tracep->declBus(c+1858,"top riscv_32i funct7D", false,-1, 6,0);
        tracep->declBit(c+1859,"top riscv_32i jalrD", false,-1);
        tracep->declBit(c+1860,"top riscv_32i auipcD", false,-1);
        tracep->declBit(c+1861,"top riscv_32i luiD", false,-1);
        tracep->declBit(c+1862,"top riscv_32i branchD", false,-1);
        tracep->declBit(c+1893,"top riscv_32i br_takenD", false,-1);
        tracep->declBit(c+1863,"top riscv_32i jumpD", false,-1);
        tracep->declBit(c+1864,"top riscv_32i regwriteD", false,-1);
        tracep->declBit(c+1865,"top riscv_32i memtoregD", false,-1);
        tracep->declBit(c+1866,"top riscv_32i memwriteD", false,-1);
        tracep->declBit(c+1867,"top riscv_32i alusrcD", false,-1);
        tracep->declBit(c+1868,"top riscv_32i alu_subD", false,-1);
        tracep->declBus(c+1869,"top riscv_32i alucontrolD", false,-1, 2,0);
        tracep->declBit(c+23,"top riscv_32i branchE", false,-1);
        tracep->declBit(c+24,"top riscv_32i br_takenE", false,-1);
        tracep->declBit(c+25,"top riscv_32i jumpE", false,-1);
        tracep->declBit(c+26,"top riscv_32i jalrE", false,-1);
        tracep->declBit(c+27,"top riscv_32i auipcE", false,-1);
        tracep->declBit(c+28,"top riscv_32i luiE", false,-1);
        tracep->declBit(c+1870,"top riscv_32i regwriteE", false,-1);
        tracep->declBit(c+29,"top riscv_32i memtoregE", false,-1);
        tracep->declBit(c+30,"top riscv_32i memwriteE", false,-1);
        tracep->declBit(c+31,"top riscv_32i alusrcE", false,-1);
        tracep->declBit(c+32,"top riscv_32i alu_subE", false,-1);
        tracep->declBus(c+33,"top riscv_32i alucontrolE", false,-1, 2,0);
        tracep->declBit(c+34,"top riscv_32i branchM", false,-1);
        tracep->declBit(c+35,"top riscv_32i br_takenM", false,-1);
        tracep->declBit(c+1871,"top riscv_32i regwriteM", false,-1);
        tracep->declBit(c+36,"top riscv_32i memtoregM", false,-1);
        tracep->declBit(c+37,"top riscv_32i memwriteM", false,-1);
        tracep->declBit(c+38,"top riscv_32i branchW", false,-1);
        tracep->declBit(c+39,"top riscv_32i br_takenW", false,-1);
        tracep->declBit(c+1872,"top riscv_32i regwriteW", false,-1);
        tracep->declBit(c+40,"top riscv_32i memtoregW", false,-1);
        tracep->declBit(c+1920,"top riscv_32i br_actual", false,-1);
        tracep->declBus(c+1873,"top riscv_32i rsD", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i rtD", false,-1, 4,0);
        tracep->declBus(c+1875,"top riscv_32i rdD", false,-1, 4,0);
        tracep->declBus(c+41,"top riscv_32i rsE", false,-1, 4,0);
        tracep->declBus(c+42,"top riscv_32i rtE", false,-1, 4,0);
        tracep->declBus(c+1876,"top riscv_32i rdE", false,-1, 4,0);
        tracep->declBus(c+1876,"top riscv_32i writeregE", false,-1, 4,0);
        tracep->declBus(c+1877,"top riscv_32i writeregM", false,-1, 4,0);
        tracep->declBus(c+1878,"top riscv_32i writeregW", false,-1, 4,0);
        tracep->declBit(c+1879,"top riscv_32i forwardAD", false,-1);
        tracep->declBit(c+1880,"top riscv_32i forwardBD", false,-1);
        tracep->declBus(c+1881,"top riscv_32i forwardAE", false,-1, 1,0);
        tracep->declBus(c+1882,"top riscv_32i forwardBE", false,-1, 1,0);
        tracep->declBit(c+1894,"top riscv_32i stallF", false,-1);
        tracep->declBit(c+1895,"top riscv_32i stallD", false,-1);
        tracep->declBit(c+1896,"top riscv_32i stallE", false,-1);
        tracep->declBit(c+1897,"top riscv_32i stallM", false,-1);
        tracep->declBit(c+1898,"top riscv_32i stallW", false,-1);
        tracep->declBit(c+1919,"top riscv_32i flushF", false,-1);
        tracep->declBit(c+1899,"top riscv_32i flushD", false,-1);
        tracep->declBit(c+1900,"top riscv_32i flushE", false,-1);
        tracep->declBit(c+1919,"top riscv_32i flushM", false,-1);
        tracep->declBit(c+1919,"top riscv_32i flushW", false,-1);
        tracep->declBus(c+43,"top riscv_32i branchimmF", false,-1, 31,0);
        tracep->declBit(c+44,"top riscv_32i BTBHitF", false,-1);
        tracep->declBit(c+45,"top riscv_32i BpredF", false,-1);
        tracep->declBit(c+46,"top riscv_32i BTBHitD", false,-1);
        tracep->declBit(c+47,"top riscv_32i BpredD", false,-1);
        tracep->declBit(c+1862,"top riscv_32i pc_gen_comb branchD", false,-1);
        tracep->declBit(c+1893,"top riscv_32i pc_gen_comb br_takenD", false,-1);
        tracep->declBit(c+1863,"top riscv_32i pc_gen_comb jumpD", false,-1);
        tracep->declBit(c+1859,"top riscv_32i pc_gen_comb jalrD", false,-1);
        tracep->declBit(c+44,"top riscv_32i pc_gen_comb BTBHitF", false,-1);
        tracep->declBit(c+45,"top riscv_32i pc_gen_comb BpredF", false,-1);
        tracep->declBit(c+46,"top riscv_32i pc_gen_comb BTBHitD", false,-1);
        tracep->declBit(c+47,"top riscv_32i pc_gen_comb BpredD", false,-1);
        tracep->declBus(c+43,"top riscv_32i pc_gen_comb branchimmF", false,-1, 31,0);
        tracep->declBus(c+1849,"top riscv_32i pc_gen_comb branchimmD", false,-1, 31,0);
        tracep->declBus(c+1848,"top riscv_32i pc_gen_comb jumpimmD", false,-1, 31,0);
        tracep->declBus(c+1851,"top riscv_32i pc_gen_comb itypeimmD", false,-1, 31,0);
        tracep->declBus(c+1,"top riscv_32i pc_gen_comb pcF", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i pc_gen_comb pcplus4F", false,-1, 31,0);
        tracep->declBus(c+2,"top riscv_32i pc_gen_comb pcD", false,-1, 31,0);
        tracep->declBus(c+7,"top riscv_32i pc_gen_comb pcplus4D", false,-1, 31,0);
        tracep->declBus(c+1890,"top riscv_32i pc_gen_comb srcaD", false,-1, 31,0);
        tracep->declBus(c+1889,"top riscv_32i pc_gen_comb pc", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i pc_if_ff clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i pc_if_ff reset", false,-1);
        tracep->declBit(c+1894,"top riscv_32i pc_if_ff en", false,-1);
        tracep->declBit(c+1919,"top riscv_32i pc_if_ff clear", false,-1);
        tracep->declBus(c+1889,"top riscv_32i pc_if_ff pc", false,-1, 31,0);
        tracep->declBus(c+1,"top riscv_32i pc_if_ff pcF", false,-1, 31,0);
        tracep->declBus(c+1,"top riscv_32i If_comb pc", false,-1, 31,0);
        tracep->declBus(c+1910,"top riscv_32i If_comb imem_instn", false,-1, 31,0);
        tracep->declBus(c+1909,"top riscv_32i If_comb imem_pc_addr", false,-1, 31,0);
        tracep->declBus(c+1910,"top riscv_32i If_comb instnF", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i If_comb pcplus4F", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i if_id_ff clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i if_id_ff reset", false,-1);
        tracep->declBit(c+1895,"top riscv_32i if_id_ff en", false,-1);
        tracep->declBit(c+1899,"top riscv_32i if_id_ff clear", false,-1);
        tracep->declBus(c+1910,"top riscv_32i if_id_ff rd", false,-1, 31,0);
        tracep->declBus(c+1,"top riscv_32i if_id_ff pcF", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i if_id_ff pcplus4F", false,-1, 31,0);
        tracep->declBit(c+44,"top riscv_32i if_id_ff BTBHitF", false,-1);
        tracep->declBit(c+45,"top riscv_32i if_id_ff BpredF", false,-1);
        tracep->declBus(c+1847,"top riscv_32i if_id_ff instnD", false,-1, 31,0);
        tracep->declBus(c+2,"top riscv_32i if_id_ff pcD", false,-1, 31,0);
        tracep->declBus(c+7,"top riscv_32i if_id_ff pcplus4D", false,-1, 31,0);
        tracep->declBit(c+46,"top riscv_32i if_id_ff BTBHitD", false,-1);
        tracep->declBit(c+47,"top riscv_32i if_id_ff BpredD", false,-1);
        tracep->declBus(c+1847,"top riscv_32i id_D instnD", false,-1, 31,0);
        tracep->declBus(c+1856,"top riscv_32i id_D opD", false,-1, 6,0);
        tracep->declBus(c+1857,"top riscv_32i id_D funct3D", false,-1, 2,0);
        tracep->declBus(c+1858,"top riscv_32i id_D funct7D", false,-1, 6,0);
        tracep->declBus(c+1848,"top riscv_32i id_D jumpimmD", false,-1, 31,0);
        tracep->declBus(c+1849,"top riscv_32i id_D branchimmD", false,-1, 31,0);
        tracep->declBus(c+1850,"top riscv_32i id_D utypeimmD", false,-1, 31,0);
        tracep->declBus(c+1852,"top riscv_32i id_D stypeimmD", false,-1, 31,0);
        tracep->declBus(c+1851,"top riscv_32i id_D itypeimmD", false,-1, 31,0);
        tracep->declBus(c+1873,"top riscv_32i id_D rsD", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i id_D rtD", false,-1, 4,0);
        tracep->declBus(c+1875,"top riscv_32i id_D rdD", false,-1, 4,0);
        tracep->declBit(c+1904,"top riscv_32i id_comb clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i id_comb reset", false,-1);
        tracep->declBus(c+2,"top riscv_32i id_comb pc", false,-1, 31,0);
        tracep->declBit(c+1872,"top riscv_32i id_comb regwriteW", false,-1);
        tracep->declBus(c+1873,"top riscv_32i id_comb rsD", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i id_comb rtD", false,-1, 4,0);
        tracep->declBus(c+1848,"top riscv_32i id_comb jumpimmD", false,-1, 31,0);
        tracep->declBus(c+1849,"top riscv_32i id_comb branchimmD", false,-1, 31,0);
        tracep->declBus(c+1851,"top riscv_32i id_comb itypeimmD", false,-1, 31,0);
        tracep->declBus(c+1852,"top riscv_32i id_comb stypeimmD", false,-1, 31,0);
        tracep->declBit(c+1879,"top riscv_32i id_comb forwardAD", false,-1);
        tracep->declBit(c+1880,"top riscv_32i id_comb forwardBD", false,-1);
        tracep->declBit(c+1866,"top riscv_32i id_comb memwriteD", false,-1);
        tracep->declBus(c+1878,"top riscv_32i id_comb writeregW", false,-1, 4,0);
        tracep->declBus(c+1855,"top riscv_32i id_comb resultW", false,-1, 31,0);
        tracep->declBus(c+14,"top riscv_32i id_comb aluoutM", false,-1, 31,0);
        tracep->declBus(c+1890,"top riscv_32i id_comb a", false,-1, 31,0);
        tracep->declBus(c+1891,"top riscv_32i id_comb b", false,-1, 31,0);
        tracep->declBus(c+1853,"top riscv_32i id_comb signimmD", false,-1, 31,0);
        tracep->declBus(c+1913,"top riscv_32i id_comb A_reg", false,-1, 31,0);
        tracep->declBus(c+1914,"top riscv_32i id_comb B_reg", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i id_comb rf clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i id_comb rf reset", false,-1);
        tracep->declBit(c+1872,"top riscv_32i id_comb rf we3", false,-1);
        tracep->declBus(c+1873,"top riscv_32i id_comb rf ra1", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i id_comb rf ra2", false,-1, 4,0);
        tracep->declBus(c+1878,"top riscv_32i id_comb rf wa3", false,-1, 4,0);
        tracep->declBus(c+1855,"top riscv_32i id_comb rf wd3", false,-1, 31,0);
        tracep->declBus(c+1913,"top riscv_32i id_comb rf rd1", false,-1, 31,0);
        tracep->declBus(c+1914,"top riscv_32i id_comb rf rd2", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+1814+i*1,"top riscv_32i id_comb rf rf", true,(i+0), 31,0);}}
        tracep->declBit(c+1904,"top riscv_32i id_ex_ff clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i id_ex_ff reset", false,-1);
        tracep->declBit(c+1896,"top riscv_32i id_ex_ff en", false,-1);
        tracep->declBit(c+1900,"top riscv_32i id_ex_ff clear", false,-1);
        tracep->declBit(c+1863,"top riscv_32i id_ex_ff jumpD", false,-1);
        tracep->declBit(c+1859,"top riscv_32i id_ex_ff jalrD", false,-1);
        tracep->declBus(c+2,"top riscv_32i id_ex_ff pcD", false,-1, 31,0);
        tracep->declBus(c+7,"top riscv_32i id_ex_ff pcplus4D", false,-1, 31,0);
        tracep->declBit(c+1864,"top riscv_32i id_ex_ff regwriteD", false,-1);
        tracep->declBit(c+1865,"top riscv_32i id_ex_ff memtoregD", false,-1);
        tracep->declBit(c+1866,"top riscv_32i id_ex_ff memwriteD", false,-1);
        tracep->declBit(c+1867,"top riscv_32i id_ex_ff alusrcD", false,-1);
        tracep->declBus(c+1869,"top riscv_32i id_ex_ff alucontrolD", false,-1, 2,0);
        tracep->declBit(c+1868,"top riscv_32i id_ex_ff alu_subD", false,-1);
        tracep->declBus(c+1857,"top riscv_32i id_ex_ff funct3D", false,-1, 2,0);
        tracep->declBit(c+1860,"top riscv_32i id_ex_ff auipcD", false,-1);
        tracep->declBit(c+1861,"top riscv_32i id_ex_ff luiD", false,-1);
        tracep->declBus(c+1890,"top riscv_32i id_ex_ff a", false,-1, 31,0);
        tracep->declBus(c+1891,"top riscv_32i id_ex_ff b", false,-1, 31,0);
        tracep->declBus(c+1853,"top riscv_32i id_ex_ff signimmD", false,-1, 31,0);
        tracep->declBus(c+1873,"top riscv_32i id_ex_ff rsD", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i id_ex_ff rtD", false,-1, 4,0);
        tracep->declBus(c+1875,"top riscv_32i id_ex_ff rdD", false,-1, 4,0);
        tracep->declBus(c+1850,"top riscv_32i id_ex_ff utypeimmD", false,-1, 31,0);
        tracep->declBit(c+1862,"top riscv_32i id_ex_ff branchD", false,-1);
        tracep->declBit(c+1893,"top riscv_32i id_ex_ff br_takenD", false,-1);
        tracep->declBus(c+1849,"top riscv_32i id_ex_ff branchimmD", false,-1, 31,0);
        tracep->declBit(c+25,"top riscv_32i id_ex_ff jumpE", false,-1);
        tracep->declBit(c+26,"top riscv_32i id_ex_ff jalrE", false,-1);
        tracep->declBus(c+3,"top riscv_32i id_ex_ff pcE", false,-1, 31,0);
        tracep->declBus(c+8,"top riscv_32i id_ex_ff pcplus4E", false,-1, 31,0);
        tracep->declBit(c+1870,"top riscv_32i id_ex_ff regwriteE", false,-1);
        tracep->declBit(c+29,"top riscv_32i id_ex_ff memtoregE", false,-1);
        tracep->declBit(c+30,"top riscv_32i id_ex_ff memwriteE", false,-1);
        tracep->declBit(c+31,"top riscv_32i id_ex_ff alusrcE", false,-1);
        tracep->declBus(c+33,"top riscv_32i id_ex_ff alucontrolE", false,-1, 2,0);
        tracep->declBit(c+32,"top riscv_32i id_ex_ff alu_subE", false,-1);
        tracep->declBus(c+20,"top riscv_32i id_ex_ff funct3E", false,-1, 2,0);
        tracep->declBit(c+27,"top riscv_32i id_ex_ff auipcE", false,-1);
        tracep->declBit(c+28,"top riscv_32i id_ex_ff luiE", false,-1);
        tracep->declBus(c+9,"top riscv_32i id_ex_ff aE", false,-1, 31,0);
        tracep->declBus(c+10,"top riscv_32i id_ex_ff bE", false,-1, 31,0);
        tracep->declBus(c+11,"top riscv_32i id_ex_ff signimmE", false,-1, 31,0);
        tracep->declBus(c+41,"top riscv_32i id_ex_ff rsE", false,-1, 4,0);
        tracep->declBus(c+42,"top riscv_32i id_ex_ff rtE", false,-1, 4,0);
        tracep->declBus(c+1876,"top riscv_32i id_ex_ff rdE", false,-1, 4,0);
        tracep->declBus(c+12,"top riscv_32i id_ex_ff utypeimmE", false,-1, 31,0);
        tracep->declBit(c+23,"top riscv_32i id_ex_ff branchE", false,-1);
        tracep->declBit(c+24,"top riscv_32i id_ex_ff br_takenE", false,-1);
        tracep->declBus(c+13,"top riscv_32i id_ex_ff branchimmE", false,-1, 31,0);
        tracep->declBit(c+25,"top riscv_32i ex_comb jumpE", false,-1);
        tracep->declBit(c+26,"top riscv_32i ex_comb jalrE", false,-1);
        tracep->declBit(c+27,"top riscv_32i ex_comb auipcE", false,-1);
        tracep->declBit(c+28,"top riscv_32i ex_comb luiE", false,-1);
        tracep->declBus(c+3,"top riscv_32i ex_comb pcE", false,-1, 31,0);
        tracep->declBus(c+8,"top riscv_32i ex_comb pcplus4E", false,-1, 31,0);
        tracep->declBit(c+31,"top riscv_32i ex_comb alusrcE", false,-1);
        tracep->declBus(c+33,"top riscv_32i ex_comb alucontrolE", false,-1, 2,0);
        tracep->declBit(c+32,"top riscv_32i ex_comb alu_subE", false,-1);
        tracep->declBus(c+1881,"top riscv_32i ex_comb forwardAE", false,-1, 1,0);
        tracep->declBus(c+1882,"top riscv_32i ex_comb forwardBE", false,-1, 1,0);
        tracep->declBus(c+9,"top riscv_32i ex_comb a", false,-1, 31,0);
        tracep->declBus(c+10,"top riscv_32i ex_comb b", false,-1, 31,0);
        tracep->declBus(c+11,"top riscv_32i ex_comb signimmE", false,-1, 31,0);
        tracep->declBus(c+12,"top riscv_32i ex_comb utypeimmE", false,-1, 31,0);
        tracep->declBus(c+1855,"top riscv_32i ex_comb resultW", false,-1, 31,0);
        tracep->declBus(c+14,"top riscv_32i ex_comb aluoutM", false,-1, 31,0);
        tracep->declBus(c+1912,"top riscv_32i ex_comb aluoutE", false,-1, 31,0);
        tracep->declBus(c+1854,"top riscv_32i ex_comb writedataE", false,-1, 31,0);
        tracep->declBus(c+1883,"top riscv_32i ex_comb srcAE", false,-1, 31,0);
        tracep->declBus(c+1884,"top riscv_32i ex_comb srcBE", false,-1, 31,0);
        tracep->declBus(c+1854,"top riscv_32i ex_comb srcBE_net0", false,-1, 31,0);
        tracep->declBus(c+1915,"top riscv_32i ex_comb aluout_net0", false,-1, 31,0);
        tracep->declBus(c+1883,"top riscv_32i ex_comb alu0 srca", false,-1, 31,0);
        tracep->declBus(c+1884,"top riscv_32i ex_comb alu0 srcb", false,-1, 31,0);
        tracep->declBus(c+33,"top riscv_32i ex_comb alu0 alucontrol", false,-1, 2,0);
        tracep->declBit(c+32,"top riscv_32i ex_comb alu0 alu_sub", false,-1);
        tracep->declBus(c+1915,"top riscv_32i ex_comb alu0 aluout", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i ex_mem_ff clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i ex_mem_ff reset", false,-1);
        tracep->declBit(c+1897,"top riscv_32i ex_mem_ff en", false,-1);
        tracep->declBit(c+1919,"top riscv_32i ex_mem_ff clear", false,-1);
        tracep->declBus(c+20,"top riscv_32i ex_mem_ff funct3E", false,-1, 2,0);
        tracep->declBus(c+3,"top riscv_32i ex_mem_ff pcE", false,-1, 31,0);
        tracep->declBit(c+1870,"top riscv_32i ex_mem_ff regwriteE", false,-1);
        tracep->declBit(c+29,"top riscv_32i ex_mem_ff memtoregE", false,-1);
        tracep->declBit(c+30,"top riscv_32i ex_mem_ff memwriteE", false,-1);
        tracep->declBus(c+1912,"top riscv_32i ex_mem_ff aluoutE", false,-1, 31,0);
        tracep->declBus(c+1854,"top riscv_32i ex_mem_ff writedataE", false,-1, 31,0);
        tracep->declBus(c+1876,"top riscv_32i ex_mem_ff writeregE", false,-1, 4,0);
        tracep->declBit(c+23,"top riscv_32i ex_mem_ff branchE", false,-1);
        tracep->declBit(c+24,"top riscv_32i ex_mem_ff br_takenE", false,-1);
        tracep->declBus(c+13,"top riscv_32i ex_mem_ff branchimmE", false,-1, 31,0);
        tracep->declBus(c+21,"top riscv_32i ex_mem_ff funct3M", false,-1, 2,0);
        tracep->declBus(c+4,"top riscv_32i ex_mem_ff pcM", false,-1, 31,0);
        tracep->declBit(c+1871,"top riscv_32i ex_mem_ff regwriteM", false,-1);
        tracep->declBit(c+36,"top riscv_32i ex_mem_ff memtoregM", false,-1);
        tracep->declBit(c+37,"top riscv_32i ex_mem_ff memwriteM", false,-1);
        tracep->declBus(c+14,"top riscv_32i ex_mem_ff aluoutM", false,-1, 31,0);
        tracep->declBus(c+15,"top riscv_32i ex_mem_ff writedataM", false,-1, 31,0);
        tracep->declBus(c+1877,"top riscv_32i ex_mem_ff writeregM", false,-1, 4,0);
        tracep->declBit(c+34,"top riscv_32i ex_mem_ff branchM", false,-1);
        tracep->declBit(c+35,"top riscv_32i ex_mem_ff br_takenM", false,-1);
        tracep->declBus(c+16,"top riscv_32i ex_mem_ff branchimmM", false,-1, 31,0);
        tracep->declBus(c+21,"top riscv_32i mem_comb funct3M", false,-1, 2,0);
        tracep->declBit(c+37,"top riscv_32i mem_comb memwriteM", false,-1);
        tracep->declBus(c+14,"top riscv_32i mem_comb aluoutM_in", false,-1, 31,0);
        tracep->declBus(c+15,"top riscv_32i mem_comb writedataM", false,-1, 31,0);
        tracep->declBus(c+1908,"top riscv_32i mem_comb dmem_rd", false,-1, 31,0);
        tracep->declBus(c+1907,"top riscv_32i mem_comb dmem_addr", false,-1, 31,0);
        tracep->declBus(c+1906,"top riscv_32i mem_comb dmem_wd", false,-1, 31,0);
        tracep->declBus(c+1846,"top riscv_32i mem_comb dmem_mask", false,-1, 3,0);
        tracep->declBit(c+1911,"top riscv_32i mem_comb dmem_we", false,-1);
        tracep->declBus(c+1892,"top riscv_32i mem_comb readdataM", false,-1, 31,0);
        tracep->declBus(c+14,"top riscv_32i mem_comb aluoutM_out", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i mem_wb_ff clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i mem_wb_ff reset", false,-1);
        tracep->declBit(c+1898,"top riscv_32i mem_wb_ff en", false,-1);
        tracep->declBit(c+1919,"top riscv_32i mem_wb_ff clear", false,-1);
        tracep->declBus(c+21,"top riscv_32i mem_wb_ff funct3M", false,-1, 2,0);
        tracep->declBus(c+4,"top riscv_32i mem_wb_ff pcM", false,-1, 31,0);
        tracep->declBit(c+1871,"top riscv_32i mem_wb_ff regwriteM", false,-1);
        tracep->declBit(c+36,"top riscv_32i mem_wb_ff memtoregM", false,-1);
        tracep->declBus(c+14,"top riscv_32i mem_wb_ff aluoutM", false,-1, 31,0);
        tracep->declBus(c+1892,"top riscv_32i mem_wb_ff readdataM", false,-1, 31,0);
        tracep->declBus(c+1877,"top riscv_32i mem_wb_ff writeregM", false,-1, 4,0);
        tracep->declBit(c+34,"top riscv_32i mem_wb_ff branchM", false,-1);
        tracep->declBit(c+35,"top riscv_32i mem_wb_ff br_takenM", false,-1);
        tracep->declBus(c+16,"top riscv_32i mem_wb_ff branchimmM", false,-1, 31,0);
        tracep->declBus(c+22,"top riscv_32i mem_wb_ff funct3W", false,-1, 2,0);
        tracep->declBus(c+5,"top riscv_32i mem_wb_ff pcW", false,-1, 31,0);
        tracep->declBit(c+1872,"top riscv_32i mem_wb_ff regwriteW", false,-1);
        tracep->declBit(c+40,"top riscv_32i mem_wb_ff memtoregW", false,-1);
        tracep->declBus(c+18,"top riscv_32i mem_wb_ff aluoutW", false,-1, 31,0);
        tracep->declBus(c+17,"top riscv_32i mem_wb_ff readdataW", false,-1, 31,0);
        tracep->declBus(c+1878,"top riscv_32i mem_wb_ff writeregW", false,-1, 4,0);
        tracep->declBit(c+38,"top riscv_32i mem_wb_ff branchW", false,-1);
        tracep->declBit(c+39,"top riscv_32i mem_wb_ff br_takenW", false,-1);
        tracep->declBus(c+19,"top riscv_32i mem_wb_ff branchimmW", false,-1, 31,0);
        tracep->declBit(c+40,"top riscv_32i wb_comb memtoregW", false,-1);
        tracep->declBus(c+17,"top riscv_32i wb_comb readdataW", false,-1, 31,0);
        tracep->declBus(c+18,"top riscv_32i wb_comb aluoutW", false,-1, 31,0);
        tracep->declBus(c+1855,"top riscv_32i wb_comb resultW", false,-1, 31,0);
        tracep->declBus(c+1856,"top riscv_32i ctrl opD", false,-1, 6,0);
        tracep->declBus(c+1857,"top riscv_32i ctrl funct3D", false,-1, 2,0);
        tracep->declBus(c+1858,"top riscv_32i ctrl funct7D", false,-1, 6,0);
        tracep->declBit(c+1862,"top riscv_32i ctrl branchD", false,-1);
        tracep->declBit(c+1863,"top riscv_32i ctrl jumpD", false,-1);
        tracep->declBit(c+1859,"top riscv_32i ctrl jalrD", false,-1);
        tracep->declBit(c+1865,"top riscv_32i ctrl memtoregD", false,-1);
        tracep->declBit(c+1866,"top riscv_32i ctrl memwriteD", false,-1);
        tracep->declBit(c+1867,"top riscv_32i ctrl alusrcD", false,-1);
        tracep->declBit(c+1864,"top riscv_32i ctrl regwriteD", false,-1);
        tracep->declBus(c+1869,"top riscv_32i ctrl alucontrolD", false,-1, 2,0);
        tracep->declBit(c+1868,"top riscv_32i ctrl alu_subD", false,-1);
        tracep->declBit(c+1860,"top riscv_32i ctrl auipcD", false,-1);
        tracep->declBit(c+1861,"top riscv_32i ctrl luiD", false,-1);
        tracep->declBus(c+1885,"top riscv_32i ctrl aluop", false,-1, 1,0);
        tracep->declBus(c+1856,"top riscv_32i ctrl maindec opD", false,-1, 6,0);
        tracep->declBit(c+1864,"top riscv_32i ctrl maindec regwriteD", false,-1);
        tracep->declBit(c+1867,"top riscv_32i ctrl maindec alusrcD", false,-1);
        tracep->declBit(c+1862,"top riscv_32i ctrl maindec branchD", false,-1);
        tracep->declBit(c+1866,"top riscv_32i ctrl maindec memwriteD", false,-1);
        tracep->declBit(c+1865,"top riscv_32i ctrl maindec memtoregD", false,-1);
        tracep->declBit(c+1863,"top riscv_32i ctrl maindec jumpD", false,-1);
        tracep->declBit(c+1859,"top riscv_32i ctrl maindec jalrD", false,-1);
        tracep->declBit(c+1860,"top riscv_32i ctrl maindec auipcD", false,-1);
        tracep->declBit(c+1861,"top riscv_32i ctrl maindec luiD", false,-1);
        tracep->declBus(c+1885,"top riscv_32i ctrl maindec aluop", false,-1, 1,0);
        tracep->declBus(c+1886,"top riscv_32i ctrl maindec controls", false,-1, 8,0);
        tracep->declBus(c+1885,"top riscv_32i ctrl ad aluop", false,-1, 1,0);
        tracep->declBus(c+1857,"top riscv_32i ctrl ad funct3D", false,-1, 2,0);
        tracep->declBus(c+1858,"top riscv_32i ctrl ad funct7D", false,-1, 6,0);
        tracep->declBus(c+1869,"top riscv_32i ctrl ad alucontrolD", false,-1, 2,0);
        tracep->declBit(c+1868,"top riscv_32i ctrl ad alu_subD", false,-1);
        tracep->declBit(c+1862,"top riscv_32i branch_compute branchD", false,-1);
        tracep->declBus(c+1857,"top riscv_32i branch_compute funct3D", false,-1, 2,0);
        tracep->declBus(c+1890,"top riscv_32i branch_compute srca", false,-1, 31,0);
        tracep->declBus(c+1891,"top riscv_32i branch_compute srcb", false,-1, 31,0);
        tracep->declBit(c+1893,"top riscv_32i branch_compute br_takenD", false,-1);
        tracep->declBit(c+1919,"top riscv_32i hazard_unit1 imem_wait", false,-1);
        tracep->declBit(c+1919,"top riscv_32i hazard_unit1 dmem_wait", false,-1);
        tracep->declBit(c+1862,"top riscv_32i hazard_unit1 branchD", false,-1);
        tracep->declBit(c+46,"top riscv_32i hazard_unit1 BTBHitD", false,-1);
        tracep->declBit(c+47,"top riscv_32i hazard_unit1 BpredD", false,-1);
        tracep->declBit(c+1893,"top riscv_32i hazard_unit1 br_takenD", false,-1);
        tracep->declBit(c+1863,"top riscv_32i hazard_unit1 jumpD", false,-1);
        tracep->declBit(c+1859,"top riscv_32i hazard_unit1 jalrD", false,-1);
        tracep->declBit(c+29,"top riscv_32i hazard_unit1 memtoregE", false,-1);
        tracep->declBit(c+1870,"top riscv_32i hazard_unit1 regwriteE", false,-1);
        tracep->declBit(c+36,"top riscv_32i hazard_unit1 memtoregM", false,-1);
        tracep->declBit(c+1871,"top riscv_32i hazard_unit1 regwriteM", false,-1);
        tracep->declBit(c+1872,"top riscv_32i hazard_unit1 regwriteW", false,-1);
        tracep->declBus(c+1873,"top riscv_32i hazard_unit1 rsD", false,-1, 4,0);
        tracep->declBus(c+1874,"top riscv_32i hazard_unit1 rtD", false,-1, 4,0);
        tracep->declBus(c+41,"top riscv_32i hazard_unit1 rsE", false,-1, 4,0);
        tracep->declBus(c+42,"top riscv_32i hazard_unit1 rtE", false,-1, 4,0);
        tracep->declBus(c+1876,"top riscv_32i hazard_unit1 writeregE", false,-1, 4,0);
        tracep->declBus(c+1877,"top riscv_32i hazard_unit1 writeregM", false,-1, 4,0);
        tracep->declBus(c+1878,"top riscv_32i hazard_unit1 writeregW", false,-1, 4,0);
        tracep->declBit(c+37,"top riscv_32i hazard_unit1 memwriteM", false,-1);
        tracep->declBit(c+1879,"top riscv_32i hazard_unit1 forwardAD", false,-1);
        tracep->declBit(c+1880,"top riscv_32i hazard_unit1 forwardBD", false,-1);
        tracep->declBus(c+1881,"top riscv_32i hazard_unit1 forwardAE", false,-1, 1,0);
        tracep->declBus(c+1882,"top riscv_32i hazard_unit1 forwardBE", false,-1, 1,0);
        tracep->declBit(c+1894,"top riscv_32i hazard_unit1 stallF", false,-1);
        tracep->declBit(c+1895,"top riscv_32i hazard_unit1 stallD", false,-1);
        tracep->declBit(c+1896,"top riscv_32i hazard_unit1 stallE", false,-1);
        tracep->declBit(c+1897,"top riscv_32i hazard_unit1 stallM", false,-1);
        tracep->declBit(c+1898,"top riscv_32i hazard_unit1 stallW", false,-1);
        tracep->declBit(c+1919,"top riscv_32i hazard_unit1 flushF", false,-1);
        tracep->declBit(c+1899,"top riscv_32i hazard_unit1 flushD", false,-1);
        tracep->declBit(c+1900,"top riscv_32i hazard_unit1 flushE", false,-1);
        tracep->declBit(c+1919,"top riscv_32i hazard_unit1 flushM", false,-1);
        tracep->declBit(c+1919,"top riscv_32i hazard_unit1 flushW", false,-1);
        tracep->declBit(c+1888,"top riscv_32i hazard_unit1 imem_req", false,-1);
        tracep->declBit(c+1887,"top riscv_32i hazard_unit1 dmem_req", false,-1);
        tracep->declBit(c+1901,"top riscv_32i hazard_unit1 lwstall", false,-1);
        tracep->declBit(c+1902,"top riscv_32i hazard_unit1 branchstall", false,-1);
        tracep->declBit(c+1903,"top riscv_32i hazard_unit1 memstall", false,-1);
        tracep->declBus(c+1921,"top riscv_32i BTB TAG_SIZE", false,-1, 31,0);
        tracep->declBus(c+1922,"top riscv_32i BTB INDEX_SIZE", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i BTB clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i BTB reset", false,-1);
        tracep->declBus(c+1,"top riscv_32i BTB pcF", false,-1, 31,0);
        tracep->declBus(c+2,"top riscv_32i BTB pcD", false,-1, 31,0);
        tracep->declBit(c+1916,"top riscv_32i BTB BTBWriteD", false,-1);
        tracep->declBus(c+1849,"top riscv_32i BTB branchimmD", false,-1, 31,0);
        tracep->declBus(c+1857,"top riscv_32i BTB funct3D", false,-1, 2,0);
        tracep->declBit(c+44,"top riscv_32i BTB BTBHit", false,-1);
        tracep->declBus(c+43,"top riscv_32i BTB branchimmF", false,-1, 31,0);
        tracep->declArray(c+48,"top riscv_32i BTB BTB", false,-1, 56319,0);
        tracep->declBus(c+1808,"top riscv_32i BTB tag", false,-1, 19,0);
        tracep->declBus(c+1809,"top riscv_32i BTB index", false,-1, 9,0);
        tracep->declBus(c+1810,"top riscv_32i BTB tag_W", false,-1, 19,0);
        tracep->declBus(c+1811,"top riscv_32i BTB index_W", false,-1, 9,0);
        tracep->declBus(c+1922,"top riscv_32i Bpred INDEX_SIZE", false,-1, 31,0);
        tracep->declBit(c+1904,"top riscv_32i Bpred clk", false,-1);
        tracep->declBit(c+1905,"top riscv_32i Bpred reset", false,-1);
        tracep->declBus(c+1,"top riscv_32i Bpred pcF", false,-1, 31,0);
        tracep->declBus(c+2,"top riscv_32i Bpred pcD", false,-1, 31,0);
        tracep->declBit(c+1893,"top riscv_32i Bpred br_takenD", false,-1);
        tracep->declBit(c+1862,"top riscv_32i Bpred BpredWriteD", false,-1);
        tracep->declBit(c+45,"top riscv_32i Bpred BpredF", false,-1);
        tracep->declBus(c+1812,"top riscv_32i Bpred index", false,-1, 9,0);
        tracep->declBus(c+1813,"top riscv_32i Bpred index_W", false,-1, 9,0);
        tracep->declBus(c+1923,"top L1_cache RAM_SIZE", false,-1, 31,0);
        tracep->declBus(c+1909,"top imem imem_addr", false,-1, 31,0);
        tracep->declBit(c+1888,"top imem imem_req", false,-1);
        tracep->declBus(c+1910,"top imem imem_instn", false,-1, 31,0);
        tracep->declBit(c+1919,"top imem imem_wait", false,-1);
        tracep->declBit(c+1904,"top dmem clk", false,-1);
        tracep->declBit(c+1911,"top dmem dmem_we", false,-1);
        tracep->declBus(c+1907,"top dmem dmem_addr", false,-1, 31,0);
        tracep->declBus(c+1906,"top dmem dmem_wd", false,-1, 31,0);
        tracep->declBus(c+1846,"top dmem dmem_mask", false,-1, 3,0);
        tracep->declBit(c+1887,"top dmem dmem_req", false,-1);
        tracep->declBus(c+1908,"top dmem dmem_rd", false,-1, 31,0);
        tracep->declBit(c+1919,"top dmem dmem_wait", false,-1);
        vlTOPp->traceInitSub1(userp, tracep, "top Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top L1_cache Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top imem Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top dmem Bus");
    }
}

void Vtop::traceInitSub1(void* userp, VerilatedVcd* tracep, const char* scopep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1904,Verilated::catName(scopep,"clk"," "), false,-1);
        tracep->declBus(c+1909,Verilated::catName(scopep,"imem_addr"," "), false,-1, 31,0);
        tracep->declBus(c+1917,Verilated::catName(scopep,"imem_instn"," "), false,-1, 31,0);
        tracep->declBit(c+1919,Verilated::catName(scopep,"imem_wait"," "), false,-1);
        tracep->declBit(c+1888,Verilated::catName(scopep,"imem_req"," "), false,-1);
        tracep->declBus(c+1907,Verilated::catName(scopep,"dmem_addr"," "), false,-1, 31,0);
        tracep->declBus(c+1918,Verilated::catName(scopep,"dmem_rd"," "), false,-1, 31,0);
        tracep->declBus(c+1906,Verilated::catName(scopep,"dmem_wd"," "), false,-1, 31,0);
        tracep->declBit(c+1911,Verilated::catName(scopep,"dmem_we"," "), false,-1);
        tracep->declBit(c+1919,Verilated::catName(scopep,"dmem_wait"," "), false,-1);
        tracep->declBit(c+1887,Verilated::catName(scopep,"dmem_req"," "), false,-1);
        tracep->declBus(c+1846,Verilated::catName(scopep,"dmem_mask"," "), false,-1, 3,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out),32);
        tracep->fullIData(oldp+2,(vlTOPp->top__DOT__riscv_32i__DOT__pcD),32);
        tracep->fullIData(oldp+3,(vlTOPp->top__DOT__riscv_32i__DOT__pcE),32);
        tracep->fullIData(oldp+4,(vlTOPp->top__DOT__riscv_32i__DOT__pcM),32);
        tracep->fullIData(oldp+5,(vlTOPp->top__DOT__riscv_32i__DOT__pcW),32);
        tracep->fullIData(oldp+6,(((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)),32);
        tracep->fullIData(oldp+7,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D),32);
        tracep->fullIData(oldp+8,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E),32);
        tracep->fullIData(oldp+9,(vlTOPp->top__DOT__riscv_32i__DOT__aE),32);
        tracep->fullIData(oldp+10,(vlTOPp->top__DOT__riscv_32i__DOT__bE),32);
        tracep->fullIData(oldp+11,(vlTOPp->top__DOT__riscv_32i__DOT__signimmE),32);
        tracep->fullIData(oldp+12,(vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE),32);
        tracep->fullIData(oldp+13,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmE),32);
        tracep->fullIData(oldp+14,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutM),32);
        tracep->fullIData(oldp+15,(vlTOPp->top__DOT__riscv_32i__DOT__writedataM),32);
        tracep->fullIData(oldp+16,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmM),32);
        tracep->fullIData(oldp+17,(vlTOPp->top__DOT__riscv_32i__DOT__readdataW),32);
        tracep->fullIData(oldp+18,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutW),32);
        tracep->fullIData(oldp+19,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmW),32);
        tracep->fullCData(oldp+20,(vlTOPp->top__DOT__riscv_32i__DOT__funct3E),3);
        tracep->fullCData(oldp+21,(vlTOPp->top__DOT__riscv_32i__DOT__funct3M),3);
        tracep->fullCData(oldp+22,(vlTOPp->top__DOT__riscv_32i__DOT__funct3W),3);
        tracep->fullBit(oldp+23,(vlTOPp->top__DOT__riscv_32i__DOT__branchE));
        tracep->fullBit(oldp+24,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenE));
        tracep->fullBit(oldp+25,(vlTOPp->top__DOT__riscv_32i__DOT__jumpE));
        tracep->fullBit(oldp+26,(vlTOPp->top__DOT__riscv_32i__DOT__jalrE));
        tracep->fullBit(oldp+27,(vlTOPp->top__DOT__riscv_32i__DOT__auipcE));
        tracep->fullBit(oldp+28,(vlTOPp->top__DOT__riscv_32i__DOT__luiE));
        tracep->fullBit(oldp+29,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregE));
        tracep->fullBit(oldp+30,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteE));
        tracep->fullBit(oldp+31,(vlTOPp->top__DOT__riscv_32i__DOT__alusrcE));
        tracep->fullBit(oldp+32,(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE));
        tracep->fullCData(oldp+33,(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE),3);
        tracep->fullBit(oldp+34,(vlTOPp->top__DOT__riscv_32i__DOT__branchM));
        tracep->fullBit(oldp+35,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenM));
        tracep->fullBit(oldp+36,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregM));
        tracep->fullBit(oldp+37,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteM));
        tracep->fullBit(oldp+38,(vlTOPp->top__DOT__riscv_32i__DOT__branchW));
        tracep->fullBit(oldp+39,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenW));
        tracep->fullBit(oldp+40,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregW));
        tracep->fullCData(oldp+41,(vlTOPp->top__DOT__riscv_32i__DOT__rsE),5);
        tracep->fullCData(oldp+42,(vlTOPp->top__DOT__riscv_32i__DOT__rtE),5);
        tracep->fullIData(oldp+43,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmF),32);
        tracep->fullBit(oldp+44,(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF));
        tracep->fullBit(oldp+45,(vlTOPp->top__DOT__riscv_32i__DOT__BpredF));
        tracep->fullBit(oldp+46,(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD));
        tracep->fullBit(oldp+47,(vlTOPp->top__DOT__riscv_32i__DOT__BpredD));
        tracep->fullWData(oldp+48,(vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB),56320);
        tracep->fullIData(oldp+1808,((0xfffffU & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                  >> 0xcU))),20);
        tracep->fullSData(oldp+1809,((0x3ffU & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                >> 2U))),10);
        tracep->fullIData(oldp+1810,((0xfffffU & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                  >> 0xcU))),20);
        tracep->fullSData(oldp+1811,((0x3ffU & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                >> 2U))),10);
        tracep->fullSData(oldp+1812,((0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)),10);
        tracep->fullSData(oldp+1813,((0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)),10);
        tracep->fullIData(oldp+1814,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0]),32);
        tracep->fullIData(oldp+1815,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[1]),32);
        tracep->fullIData(oldp+1816,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[2]),32);
        tracep->fullIData(oldp+1817,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[3]),32);
        tracep->fullIData(oldp+1818,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[4]),32);
        tracep->fullIData(oldp+1819,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[5]),32);
        tracep->fullIData(oldp+1820,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[6]),32);
        tracep->fullIData(oldp+1821,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[7]),32);
        tracep->fullIData(oldp+1822,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[8]),32);
        tracep->fullIData(oldp+1823,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[9]),32);
        tracep->fullIData(oldp+1824,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[10]),32);
        tracep->fullIData(oldp+1825,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[11]),32);
        tracep->fullIData(oldp+1826,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[12]),32);
        tracep->fullIData(oldp+1827,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[13]),32);
        tracep->fullIData(oldp+1828,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[14]),32);
        tracep->fullIData(oldp+1829,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[15]),32);
        tracep->fullIData(oldp+1830,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[16]),32);
        tracep->fullIData(oldp+1831,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[17]),32);
        tracep->fullIData(oldp+1832,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[18]),32);
        tracep->fullIData(oldp+1833,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[19]),32);
        tracep->fullIData(oldp+1834,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[20]),32);
        tracep->fullIData(oldp+1835,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[21]),32);
        tracep->fullIData(oldp+1836,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[22]),32);
        tracep->fullIData(oldp+1837,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[23]),32);
        tracep->fullIData(oldp+1838,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[24]),32);
        tracep->fullIData(oldp+1839,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[25]),32);
        tracep->fullIData(oldp+1840,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[26]),32);
        tracep->fullIData(oldp+1841,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[27]),32);
        tracep->fullIData(oldp+1842,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[28]),32);
        tracep->fullIData(oldp+1843,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[29]),32);
        tracep->fullIData(oldp+1844,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[30]),32);
        tracep->fullIData(oldp+1845,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[31]),32);
        tracep->fullCData(oldp+1846,(vlTOPp->top__DOT__dmem_mask),4);
        tracep->fullIData(oldp+1847,(vlTOPp->top__DOT__riscv_32i__DOT__instnD),32);
        tracep->fullIData(oldp+1848,(((0xffe00000U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                         >> 0x1fU)))) 
                                          << 0x15U)) 
                                      | ((0x100000U 
                                          & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0xbU)) 
                                         | ((0xff000U 
                                             & vlTOPp->top__DOT__riscv_32i__DOT__instnD) 
                                            | ((0x800U 
                                                & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                   >> 9U)) 
                                               | (0x7feU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0x14U))))))),32);
        tracep->fullIData(oldp+1849,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmD),32);
        tracep->fullIData(oldp+1850,((0xfffff000U & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),32);
        tracep->fullIData(oldp+1851,(vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD),32);
        tracep->fullIData(oldp+1852,(((0xfffff000U 
                                       & ((- (IData)(
                                                     (1U 
                                                      & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                         >> 0x1fU)))) 
                                          << 0xcU)) 
                                      | ((0xfe0U & 
                                          (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                           >> 0x14U)) 
                                         | (0x1fU & 
                                            (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 7U))))),32);
        tracep->fullIData(oldp+1853,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                                       ? ((0xfffff000U 
                                           & ((- (IData)(
                                                         (1U 
                                                          & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                             >> 0x1fU)))) 
                                              << 0xcU)) 
                                          | ((0xfe0U 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0x14U)) 
                                             | (0x1fU 
                                                & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                   >> 7U))))
                                       : vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD)),32);
        tracep->fullIData(oldp+1854,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0),32);
        tracep->fullIData(oldp+1855,(vlTOPp->top__DOT__riscv_32i__DOT__resultW),32);
        tracep->fullCData(oldp+1856,((0x7fU & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),7);
        tracep->fullCData(oldp+1857,((7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                            >> 0xcU))),3);
        tracep->fullCData(oldp+1858,((0x7fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0x19U))),7);
        tracep->fullBit(oldp+1859,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 2U))));
        tracep->fullBit(oldp+1860,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 1U))));
        tracep->fullBit(oldp+1861,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))));
        tracep->fullBit(oldp+1862,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 6U))));
        tracep->fullBit(oldp+1863,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 3U))));
        tracep->fullBit(oldp+1864,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 8U))));
        tracep->fullBit(oldp+1865,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 4U))));
        tracep->fullBit(oldp+1866,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 5U))));
        tracep->fullBit(oldp+1867,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                          >> 7U))));
        tracep->fullBit(oldp+1868,((1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                           ? ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                               ? ((5U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                       >> 0xcU))) 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0x1eU))
                                               : (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x1eU))
                                           : (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop)))));
        tracep->fullCData(oldp+1869,(((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                       ? (7U & ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                                 ? 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0xcU)
                                                 : 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0xcU)))
                                       : 0U)),3);
        tracep->fullBit(oldp+1870,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteE));
        tracep->fullBit(oldp+1871,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM));
        tracep->fullBit(oldp+1872,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteW));
        tracep->fullCData(oldp+1873,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0xfU))),5);
        tracep->fullCData(oldp+1874,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0x14U))),5);
        tracep->fullCData(oldp+1875,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 7U))),5);
        tracep->fullCData(oldp+1876,(vlTOPp->top__DOT__riscv_32i__DOT__rdE),5);
        tracep->fullCData(oldp+1877,(vlTOPp->top__DOT__riscv_32i__DOT__writeregM),5);
        tracep->fullCData(oldp+1878,(vlTOPp->top__DOT__riscv_32i__DOT__writeregW),5);
        tracep->fullBit(oldp+1879,((((0U != (0x1fU 
                                             & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                >> 0xfU))) 
                                     & ((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0xfU)) 
                                        == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
        tracep->fullBit(oldp+1880,((((0U != (0x1fU 
                                             & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                >> 0x14U))) 
                                     & ((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x14U)) 
                                        == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
        tracep->fullCData(oldp+1881,(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE),2);
        tracep->fullCData(oldp+1882,(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE),2);
        tracep->fullIData(oldp+1883,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE),32);
        tracep->fullIData(oldp+1884,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE),32);
        tracep->fullCData(oldp+1885,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop),2);
        tracep->fullSData(oldp+1886,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls),9);
        tracep->fullBit(oldp+1887,(vlTOPp->top__DOT__dmem_req));
        tracep->fullBit(oldp+1888,(vlTOPp->top__DOT__imem_req));
        tracep->fullIData(oldp+1889,(vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_in),32);
        tracep->fullIData(oldp+1890,(vlTOPp->top__DOT__riscv_32i__DOT__aD),32);
        tracep->fullIData(oldp+1891,(vlTOPp->top__DOT__riscv_32i__DOT__bD),32);
        tracep->fullIData(oldp+1892,(vlTOPp->top__DOT__riscv_32i__DOT__readdataM),32);
        tracep->fullBit(oldp+1893,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD));
        tracep->fullBit(oldp+1894,(vlTOPp->top__DOT__riscv_32i__DOT__stallF));
        tracep->fullBit(oldp+1895,(vlTOPp->top__DOT__riscv_32i__DOT__stallD));
        tracep->fullBit(oldp+1896,(vlTOPp->top__DOT__riscv_32i__DOT__stallE));
        tracep->fullBit(oldp+1897,(vlTOPp->top__DOT__riscv_32i__DOT__stallM));
        tracep->fullBit(oldp+1898,(vlTOPp->top__DOT__riscv_32i__DOT__stallW));
        tracep->fullBit(oldp+1899,(vlTOPp->top__DOT__riscv_32i__DOT__flushD));
        tracep->fullBit(oldp+1900,(vlTOPp->top__DOT__riscv_32i__DOT__flushE));
        tracep->fullBit(oldp+1901,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall));
        tracep->fullBit(oldp+1902,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
        tracep->fullBit(oldp+1903,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall));
        tracep->fullBit(oldp+1904,(vlTOPp->clk));
        tracep->fullBit(oldp+1905,(vlTOPp->reset));
        tracep->fullIData(oldp+1906,(vlTOPp->writedata),32);
        tracep->fullIData(oldp+1907,(vlTOPp->dataadr),32);
        tracep->fullIData(oldp+1908,(vlTOPp->readdata),32);
        tracep->fullIData(oldp+1909,(vlTOPp->pc),32);
        tracep->fullIData(oldp+1910,(vlTOPp->instr),32);
        tracep->fullBit(oldp+1911,(vlTOPp->memwrite));
        tracep->fullIData(oldp+1912,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__jumpE) 
                                       | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__jalrE))
                                       ? vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E
                                       : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__auipcE)
                                           ? (vlTOPp->top__DOT__riscv_32i__DOT__pcE 
                                              + vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE)
                                           : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__luiE)
                                               ? vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE
                                               : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
                                                   ? 
                                                  ((0U 
                                                    == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                    ? 
                                                   (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                    - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                    : 
                                                   ((5U 
                                                     == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, 
                                                                   (0x1fU 
                                                                    & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                     : 0U))
                                                   : 
                                                  ((4U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                    ? 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                      ? 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                      : 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      | vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                      ? 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      >> 
                                                      (0x1fU 
                                                       & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                      : 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      ^ vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
                                                    : 
                                                   ((2U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                      ? 
                                                     ((vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                       < vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                       ? 1U
                                                       : 0U)
                                                      : 
                                                     VL_LTS_III(32,32,32, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                      ? 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      << 
                                                      (0x1fU 
                                                       & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                      : 
                                                     (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))))))))),32);
        tracep->fullIData(oldp+1913,(((0U != (0x1fU 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0xfU)))
                                       ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                      [(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0xfU))]
                                       : 0U)),32);
        tracep->fullIData(oldp+1914,(((0U != (0x1fU 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0x14U)))
                                       ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                      [(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0x14U))]
                                       : 0U)),32);
        tracep->fullIData(oldp+1915,(((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
                                       ? ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                           ? (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                              - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                           : ((5U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                               ? VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, 
                                                                (0x1fU 
                                                                 & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                               : 0U))
                                       : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                           ? ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                   : 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   | vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                               : ((1U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   >> 
                                                   (0x1fU 
                                                    & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                   : 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   ^ vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
                                           : ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                               ? ((1U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  ((vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                    < vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  VL_LTS_III(32,32,32, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                               : ((1U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   << 
                                                   (0x1fU 
                                                    & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                   : 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                   + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))))),32);
        tracep->fullBit(oldp+1916,((1U & ((~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)) 
                                          & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                             >> 6U)))));
        tracep->fullIData(oldp+1917,(((IData)(vlTOPp->top__DOT__imem_req)
                                       ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                      [(0x3fffU & (vlTOPp->pc 
                                                   >> 2U))]
                                       : 0U)),32);
        tracep->fullIData(oldp+1918,(((IData)(vlTOPp->top__DOT__dmem_req)
                                       ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                      [(0x3fffU & (vlTOPp->dataadr 
                                                   >> 2U))]
                                       : 0U)),32);
        tracep->fullBit(oldp+1919,(0U));
        tracep->fullBit(oldp+1920,(vlTOPp->top__DOT__riscv_32i__DOT__br_actual));
        tracep->fullIData(oldp+1921,(0x14U),32);
        tracep->fullIData(oldp+1922,(0xaU),32);
        tracep->fullIData(oldp+1923,(0x10000U),32);
    }
}
