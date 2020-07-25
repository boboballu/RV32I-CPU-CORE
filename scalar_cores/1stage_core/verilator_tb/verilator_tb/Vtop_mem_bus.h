// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _Vtop_mem_bus_H_
#define _Vtop_mem_bus_H_

#include "verilated.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop_mem_bus) {
  public:
    
    // PORTS
    
    // LOCAL SIGNALS
    VL_SIG(Iinstn,31,0);
    VL_SIG(Dreaddata,31,0);
    VL_SIG(__PVT__MEM[131072],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    Vtop_mem_bus& operator= (const Vtop_mem_bus&);  ///< Copying not allowed
    Vtop_mem_bus(const Vtop_mem_bus&);  ///< Copying not allowed
  public:
    Vtop_mem_bus(const char* name="TOP");
    ~Vtop_mem_bus();
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void _initial__TOP__top__DOT__Bus__1(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__top__DOT__Bus__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__top__DOT__Bus__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__top__DOT__Bus__4(Vtop__Syms* __restrict vlSymsp);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
