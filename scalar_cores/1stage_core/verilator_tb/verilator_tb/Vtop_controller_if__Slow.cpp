// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop_controller_if.h"

void Vtop_controller_if___ctor_var_reset(Vtop_controller_if* vlSelf);

Vtop_controller_if::Vtop_controller_if(Vtop__Syms* symsp, const char* name)
    : VerilatedModule{name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtop_controller_if___ctor_var_reset(this);
}

void Vtop_controller_if::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vtop_controller_if::~Vtop_controller_if() {
}
