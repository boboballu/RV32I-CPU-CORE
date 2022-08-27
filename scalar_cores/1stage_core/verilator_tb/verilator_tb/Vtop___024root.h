// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;
class Vtop_controller_if;

VL_MODULE(Vtop___024root) {
  public:
    // CELLS
    Vtop_controller_if* __PVT__top__DOT__riscv_32i__DOT__c_bus;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(memwrite,0,0);
    CData/*3:0*/ top__DOT__dmem_mask;
    CData/*1:0*/ top__DOT__riscv_32i__DOT__controller__DOT__aluop;
    CData/*3:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    SData/*8:0*/ top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls;
    VL_OUT(writedata,31,0);
    VL_OUT(dataadr,31,0);
    VL_OUT(readdata,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__result;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf;
    VlUnpacked<IData/*31:0*/, 1048576> top__DOT__L1_cache__DOT__MEM;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    std::string top__DOT__L1_cache__DOT__EXEC;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
