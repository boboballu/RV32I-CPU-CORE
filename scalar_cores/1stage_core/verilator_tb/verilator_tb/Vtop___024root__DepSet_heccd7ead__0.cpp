// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Init
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3;
    // Body
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3 = 0U;
    if (vlSelf->memwrite) {
        if ((1U & (IData)(vlSelf->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0 
                = (0xffU & vlSelf->writedata);
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0 = 0U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0 
                = (0xfffffU & (vlSelf->dataadr >> 2U));
        }
        if ((2U & (IData)(vlSelf->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1 
                = (0xffU & (vlSelf->writedata >> 8U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1 = 8U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1 
                = (0xfffffU & (vlSelf->dataadr >> 2U));
        }
        if ((4U & (IData)(vlSelf->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2 
                = (0xffU & (vlSelf->writedata >> 0x10U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2 = 0x10U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2 
                = (0xfffffU & (vlSelf->dataadr >> 2U));
        }
        if ((8U & (IData)(vlSelf->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3 
                = (vlSelf->writedata >> 0x18U);
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3 = 0x18U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3 
                = (0xfffffU & (vlSelf->dataadr >> 2U));
        }
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0) {
        vlSelf->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0))) 
                & vlSelf->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0) 
                                   << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0))));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1) {
        vlSelf->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1))) 
                & vlSelf->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1) 
                                   << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1))));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2) {
        vlSelf->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2))) 
                & vlSelf->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2) 
                                   << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2))));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3) {
        vlSelf->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3))) 
                & vlSelf->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3]) 
               | (0xffffffffULL & ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3) 
                                   << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3))));
    }
}

void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf);

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->__Vclklast__TOP__reset)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->__Vclklast__TOP__reset)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__reset = vlSelf->reset;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
