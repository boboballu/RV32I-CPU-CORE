// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef _Vtop_controller_if_H_
#define _Vtop_controller_if_H_

#include "verilated.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop_controller_if) {
  public:
    
    // PORTS
    VL_IN(instr,31,0);
    
    // LOCAL SIGNALS
    VL_SIG8(br_taken,0,0);
    VL_SIG8(alucontrol,2,0);
    VL_SIG8(alu_sub,0,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    Vtop__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    Vtop_controller_if& operator= (const Vtop_controller_if&);  ///< Copying not allowed
    Vtop_controller_if(const Vtop_controller_if&);  ///< Copying not allowed
  public:
    Vtop_controller_if(const char* name="TOP");
    ~Vtop_controller_if();
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    void _ctor_var_reset();
  public:
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
