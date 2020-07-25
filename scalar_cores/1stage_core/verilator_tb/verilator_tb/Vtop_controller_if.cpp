// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop_controller_if.h" // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop_controller_if) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_controller_if::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_controller_if::~Vtop_controller_if() {
}

//--------------------
// Internal Methods

void Vtop_controller_if::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_controller_if::_ctor_var_reset\n"); );
    // Body
    instr = VL_RAND_RESET_I(32);
    br_taken = VL_RAND_RESET_I(1);
    alucontrol = VL_RAND_RESET_I(3);
    alu_sub = VL_RAND_RESET_I(1);
}
