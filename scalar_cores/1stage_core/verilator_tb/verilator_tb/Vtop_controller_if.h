// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_CONTROLLER_IF_H_
#define VERILATED_VTOP_CONTROLLER_IF_H_  // guard

#include "verilated.h"

class Vtop__Syms;
VL_MODULE(Vtop_controller_if) {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ br_taken;
    VL_IN(instr,31,0);

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_controller_if(Vtop__Syms* symsp, const char* name);
    ~Vtop_controller_if();
    VL_UNCOPYABLE(Vtop_controller_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
