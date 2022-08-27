// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->writedata = VL_RAND_RESET_I(32);
    vlSelf->dataadr = VL_RAND_RESET_I(32);
    vlSelf->readdata = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->instr = VL_RAND_RESET_I(32);
    vlSelf->memwrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__dmem_mask = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls = VL_RAND_RESET_I(9);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<1048576; ++__Vi0) {
        vlSelf->top__DOT__L1_cache__DOT__MEM[__Vi0] = 0;
    }
    vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = VL_RAND_RESET_I(4);
    vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
