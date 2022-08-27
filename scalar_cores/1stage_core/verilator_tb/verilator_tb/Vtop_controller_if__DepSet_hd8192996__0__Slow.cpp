// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop_controller_if.h"

VL_ATTR_COLD void Vtop_controller_if___ctor_var_reset(Vtop_controller_if* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+              Vtop_controller_if___ctor_var_reset\n"); );
    // Body
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->br_taken = VL_RAND_RESET_I(1);
}
