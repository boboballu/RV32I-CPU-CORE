// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop__Syms.h"
#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1;
    IData/*31:0*/ __Vtemp_hed0fa7e1__0;
    // Body
    __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 0U;
    __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1 = 0U;
    if (vlSelf->reset) {
        if ((0x100U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))) {
            __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
                = vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__result;
            __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 1U;
            __Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
                = (0x1fU & (vlSelf->instr >> 7U));
        }
        __Vtemp_hed0fa7e1__0 = ((((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))
                                 ? ((8U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                     ? vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                     : ((4U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                         ? vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                         : (vlSelf->pc 
                                            + (((- (IData)(
                                                           (vlSelf->instr 
                                                            >> 0x1fU))) 
                                                << 0xdU) 
                                               | ((0x1000U 
                                                   & (vlSelf->instr 
                                                      >> 0x13U)) 
                                                  | ((0x800U 
                                                      & (vlSelf->instr 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelf->instr 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelf->instr 
                                                              >> 7U)))))))))
                                 : ((8U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                     ? ((4U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                         ? vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                         : (vlSelf->pc 
                                            + (((- (IData)(
                                                           (vlSelf->instr 
                                                            >> 0x1fU))) 
                                                << 0x15U) 
                                               | ((0x100000U 
                                                   & (vlSelf->instr 
                                                      >> 0xbU)) 
                                                  | ((0xff000U 
                                                      & vlSelf->instr) 
                                                     | ((0x800U 
                                                         & (vlSelf->instr 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelf->instr 
                                                              >> 0x14U))))))))
                                     : ((4U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                         ? (0xfffffffeU 
                                            & (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
                                               + vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca))
                                         : vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4)));
    } else {
        __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1 = 1U;
        __Vtemp_hed0fa7e1__0 = 0U;
    }
    vlSelf->pc = __Vtemp_hed0fa7e1__0;
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0) {
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[__Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1) {
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1fU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1eU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1dU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1cU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1bU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1aU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x19U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x18U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x17U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x16U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x15U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x14U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x13U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x12U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x11U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x10U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xfU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xeU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xdU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xcU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xbU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xaU] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1U] = 0U;
        vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0U] = 0U;
    }
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 
        = ((IData)(4U) + vlSelf->pc);
}

extern const VlUnpacked<SData/*8:0*/, 128> Vtop__ConstPool__TABLE_hcbf7a19d_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_hf73678f6_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Init
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout;
    CData/*2:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
    CData/*2:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch;
    CData/*2:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken;
    CData/*6:0*/ __Vtableidx1;
    // Body
    vlSelf->instr = vlSelf->top__DOT__L1_cache__DOT__MEM
        [(0xfffffU & (vlSelf->pc >> 2U))];
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
        = ((0U != (0x1fU & (vlSelf->instr >> 0xfU)))
            ? vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
           [(0x1fU & (vlSelf->instr >> 0xfU))] : 0U);
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
        = (((- (IData)((vlSelf->instr >> 0x1fU))) << 0xcU) 
           | (vlSelf->instr >> 0x14U));
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0 
        = ((0U != (0x1fU & (vlSelf->instr >> 0x14U)))
            ? vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
           [(0x1fU & (vlSelf->instr >> 0x14U))] : 0U);
    __Vtableidx1 = (0x7fU & vlSelf->instr);
    vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls 
        = Vtop__ConstPool__TABLE_hcbf7a19d_0[__Vtableidx1];
    vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop 
        = Vtop__ConstPool__TABLE_hf73678f6_0[__Vtableidx1];
    vlSelf->memwrite = (1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                              >> 5U));
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb 
        = ((0x80U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
            ? ((0x20U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                ? (((- (IData)((vlSelf->instr >> 0x1fU))) 
                    << 0xcU) | ((0xfe0U & (vlSelf->instr 
                                           >> 0x14U)) 
                                | (0x1fU & (vlSelf->instr 
                                            >> 7U))))
                : vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)
            : vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb 
        = vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
        = vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3 
        = (7U & (vlSelf->instr >> 0xcU));
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch 
        = (1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                 >> 6U));
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken 
        = ((IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch) 
           & ((4U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
               ? ((2U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                   ? ((1U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                       ? (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                          >= __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                       : (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                          < __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb))
                   : ((1U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                       ? VL_GTES_III(32, __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca, __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                       : VL_LTS_III(32, __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca, __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)))
               : ((~ ((IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3) 
                      >> 1U)) & ((1U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                                  ? (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                                     != __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                                  : (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                                     == __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)))));
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout 
        = __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken;
    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken 
        = __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    vlSelf->dataadr = ((1U & ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                               ? ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                   ? (IData)((0x40005000U 
                                              == (0x40007000U 
                                                  & vlSelf->instr)))
                                   : (vlSelf->instr 
                                      >> 0x1eU)) : (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop)))
                        ? ((0U == ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                    ? (7U & ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                              ? (vlSelf->instr 
                                                 >> 0xcU)
                                              : (vlSelf->instr 
                                                 >> 0xcU)))
                                    : 0U)) ? (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                              - vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                            : ((5U == ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                        ? (7U & ((1U 
                                                  & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                  ? 
                                                 (vlSelf->instr 
                                                  >> 0xcU)
                                                  : 
                                                 (vlSelf->instr 
                                                  >> 0xcU)))
                                        : 0U)) ? VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca, 
                                                                (0x1fU 
                                                                 & vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                : 0U)) : (((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                            ? (4U & 
                                               ((1U 
                                                 & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                 ? 
                                                (vlSelf->instr 
                                                 >> 0xcU)
                                                 : 
                                                (vlSelf->instr 
                                                 >> 0xcU)))
                                            : 0U) ? 
                                          (((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                             ? (2U 
                                                & ((1U 
                                                    & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (vlSelf->instr 
                                                    >> 0xcU)
                                                    : 
                                                   (vlSelf->instr 
                                                    >> 0xcU)))
                                             : 0U) ? 
                                           (((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                              ? (1U 
                                                 & ((1U 
                                                     & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                     ? 
                                                    (vlSelf->instr 
                                                     >> 0xcU)
                                                     : 
                                                    (vlSelf->instr 
                                                     >> 0xcU)))
                                              : 0U)
                                             ? (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                & vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                             : (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                | vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                            : (((2U 
                                                 & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                 ? 
                                                (1U 
                                                 & ((1U 
                                                     & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                     ? 
                                                    (vlSelf->instr 
                                                     >> 0xcU)
                                                     : 
                                                    (vlSelf->instr 
                                                     >> 0xcU)))
                                                 : 0U)
                                                ? (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   >> 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                                : (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   ^ vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))
                                           : (((2U 
                                                & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                ? (2U 
                                                   & ((1U 
                                                       & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                       ? 
                                                      (vlSelf->instr 
                                                       >> 0xcU)
                                                       : 
                                                      (vlSelf->instr 
                                                       >> 0xcU)))
                                                : 0U)
                                               ? ((
                                                   (2U 
                                                    & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (1U 
                                                    & ((1U 
                                                        & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                        ? 
                                                       (vlSelf->instr 
                                                        >> 0xcU)
                                                        : 
                                                       (vlSelf->instr 
                                                        >> 0xcU)))
                                                    : 0U)
                                                   ? 
                                                  ((vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                    < vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  (VL_LTS_III(32, vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca, vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                                    ? 1U
                                                    : 0U))
                                               : ((
                                                   (2U 
                                                    & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (1U 
                                                    & ((1U 
                                                        & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                        ? 
                                                       (vlSelf->instr 
                                                        >> 0xcU)
                                                        : 
                                                       (vlSelf->instr 
                                                        >> 0xcU)))
                                                    : 0U)
                                                   ? 
                                                  (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   << 
                                                   (0x1fU 
                                                    & vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                                   : 
                                                  (vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   + vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))));
    __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
        = vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout 
        = vlSelf->dataadr;
    __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3 
        = (7U & (vlSelf->instr >> 0xcU));
    if ((0U == (IData)(__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))) {
        if ((2U & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
            if ((1U & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                       << 0x18U);
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 8U;
            } else {
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xff0000U & (__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                                    << 0x10U));
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 4U;
            }
        } else if ((1U & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                = (0xff00U & (__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                              << 8U));
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 2U;
        } else {
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                = (0xffU & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0);
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 1U;
        }
    } else if ((1U == (IData)(__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))) {
        if ((2U & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
            if ((2U & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                       << 0x10U);
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0xcU;
            } else {
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata = 0U;
                vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0U;
            }
        } else {
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                = (0xffffU & __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0);
            vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 3U;
        }
    } else {
        vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
            = __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0;
        vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0xfU;
    }
    vlSelf->top__DOT__dmem_mask = vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask;
    vlSelf->writedata = vlSelf->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
    vlSelf->readdata = ((IData)((0U != (0x30U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))
                         ? vlSelf->top__DOT__L1_cache__DOT__MEM
                        [(0xfffffU & (vlSelf->dataadr 
                                      >> 2U))] : 0U);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
        = vlSelf->readdata;
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout 
        = vlSelf->dataadr;
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3 
        = (7U & (vlSelf->instr >> 0xcU));
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result 
        = ((4U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
            ? ((2U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                ? __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
                : ((1U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                    ? ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                               >> 0x10U) : 0U) : (0xffffU 
                                                  & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata))
                    : ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((1U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                               >> 0x18U) : (0xffU & 
                                            (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                             >> 0x10U)))
                        : ((1U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (0xffU & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                        >> 8U)) : (0xffU 
                                                   & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))
            : ((2U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                ? __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
                : ((1U & (IData)(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                    ? ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (((- (IData)((__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                            >> 0x1fU))) 
                                << 0x10U) | (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                             >> 0x10U))
                            : 0U) : (((- (IData)((1U 
                                                  & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                     >> 0xfU)))) 
                                      << 0x10U) | (0xffffU 
                                                   & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))
                    : ((2U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((1U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (((- (IData)((__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                            >> 0x1fU))) 
                                << 8U) | (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                          >> 0x18U))
                            : (((- (IData)((1U & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                  >> 0x17U)))) 
                                << 8U) | (0xffU & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                   >> 0x10U))))
                        : ((1U & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (((- (IData)((1U & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                  >> 0xfU)))) 
                                << 8U) | (0xffU & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                   >> 8U)))
                            : (((- (IData)((1U & (__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                  >> 7U)))) 
                                << 8U) | (0xffU & __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))));
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout 
        = __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
    vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__result 
        = ((IData)((0U != (0xcU & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))
            ? ((IData)(4U) + vlSelf->pc) : ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                             ? (vlSelf->pc 
                                                + (0xfffff000U 
                                                   & vlSelf->instr))
                                             : ((1U 
                                                 & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                                 ? 
                                                (0xfffff000U 
                                                 & vlSelf->instr)
                                                 : 
                                                ((0x10U 
                                                  & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                                  ? __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout
                                                  : vlSelf->dataadr))));
}
