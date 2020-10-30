// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../top_test.sv", 10, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../top_test.sv", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0;
    CData/*1:0*/ __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v2;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0;
    SData/*9:0*/ __Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1;
    IData/*31:0*/ __Vilp;
    // Body
    __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0 = 0U;
    __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1 = 0U;
    __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v2 = 0U;
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__writedataM 
                = vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__writedataM = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__readdataW 
                = vlTOPp->top__DOT__riscv_32i__DOT__readdataM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__readdataW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchimmW 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchimmM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__branchimmW = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushD) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__BpredD = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallD)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__BpredD 
                = vlTOPp->top__DOT__riscv_32i__DOT__BpredF;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__br_takenM 
                = vlTOPp->top__DOT__riscv_32i__DOT__br_takenE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__br_takenM = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__aE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__aE = vlTOPp->top__DOT__riscv_32i__DOT__aD;
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__bE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__bE = vlTOPp->top__DOT__riscv_32i__DOT__bD;
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__alusrcE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__alusrcE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 7U));
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__br_takenW 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__br_takenW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchW 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__branchW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcW = vlTOPp->top__DOT__riscv_32i__DOT__pcM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__pcW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__memwriteM 
                = vlTOPp->top__DOT__riscv_32i__DOT__memwriteE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__memwriteM = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__memtoregW 
                = vlTOPp->top__DOT__riscv_32i__DOT__memtoregM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__memtoregW = 0U;
    }
    if (vlTOPp->reset) {
        if ((0x40U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))) {
            if (vlTOPp->top__DOT__riscv_32i__DOT__br_takenD) {
                if ((3U != vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE
                     [(0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)])) {
                    __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0 
                        = (3U & ((IData)(1U) + vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE
                                 [(0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)]));
                    __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0 = 1U;
                    __Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0 
                        = (0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD);
                }
            } else {
                if ((0U != vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE
                     [(0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)])) {
                    __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1 
                        = (3U & (vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE
                                 [(0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)] 
                                 - (IData)(1U)));
                    __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1 = 1U;
                    __Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1 
                        = (0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD);
                }
            }
        }
    } else {
        __Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v2 = 1U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__rsE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__rsE = 
                (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                          >> 0xfU));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__rtE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__rtE = 
                (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                          >> 0x14U));
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__funct3W 
                = vlTOPp->top__DOT__riscv_32i__DOT__funct3M;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__funct3W = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__signimmE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__signimmE 
                = ((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                    ? ((0xfffff000U & ((- (IData)((1U 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                       ((0xfe0U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                   >> 0x14U)) | (0x1fU 
                                                 & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                    >> 7U))))
                    : vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD);
        }
    }
    if (vlTOPp->reset) {
        if ((1U & ((~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)) 
                   & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                      >> 6U)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound1 
                = (0xfffffU & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                               >> 0xcU));
            if ((0xdbffU >= (0xffffU & ((IData)(0x23U) 
                                        + ((IData)(0x37U) 
                                           * (0x3ffU 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                 >> 2U))))))) {
                VL_ASSIGNSEL_WIII(20,(0xffffU & ((IData)(0x23U) 
                                                 + 
                                                 ((IData)(0x37U) 
                                                  * 
                                                  (0x3ffU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                      >> 2U))))), vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB, vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound1);
            }
            vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound2 
                = (7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                         >> 0xcU));
            if ((0xdbffU >= (0xffffU & ((IData)(0x20U) 
                                        + ((IData)(0x37U) 
                                           * (0x3ffU 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                 >> 2U))))))) {
                VL_ASSIGNSEL_WIII(3,(0xffffU & ((IData)(0x20U) 
                                                + ((IData)(0x37U) 
                                                   * 
                                                   (0x3ffU 
                                                    & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                       >> 2U))))), vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB, vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound2);
            }
            vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound3 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchimmD;
            if ((0xdbffU >= (0xffffU & ((IData)(0x37U) 
                                        * (0x3ffU & 
                                           (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                            >> 2U)))))) {
                VL_ASSIGNSEL_WIII(32,(0xffffU & ((IData)(0x37U) 
                                                 * 
                                                 (0x3ffU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                                                     >> 2U)))), vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB, vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound3);
            }
        }
    } else {
        __Vilp = 0U;
        while ((__Vilp <= 0x6dfU)) {
            vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB[__Vilp] = 0xffffffffU;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__aluoutW 
                = vlTOPp->top__DOT__riscv_32i__DOT__aluoutM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__aluoutW = 0U;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0) {
        vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[__Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0] 
            = __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v0;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1) {
        vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[__Vdlyvdim0__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1] 
            = __Vdlyvval__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v1;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE__v2) {
        __Vilp = 0U;
        while ((__Vilp <= 0x3ffU)) {
            vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[__Vilp] = 2U;
            __Vilp = ((IData)(1U) + __Vilp);
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchimmM 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchimmE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__branchimmM = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__br_takenE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__br_takenE 
                = vlTOPp->top__DOT__riscv_32i__DOT__br_takenD;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchM 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__branchM = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcM = vlTOPp->top__DOT__riscv_32i__DOT__pcE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__pcM = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__memwriteE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__memwriteE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 5U));
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__memtoregM 
                = vlTOPp->top__DOT__riscv_32i__DOT__memtoregE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__memtoregM = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__funct3M 
                = vlTOPp->top__DOT__riscv_32i__DOT__funct3E;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__funct3M = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushD) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallD)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD 
                = vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__aluoutM 
                = (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__jumpE) 
                    | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__jalrE))
                    ? vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E
                    : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__auipcE)
                        ? (vlTOPp->top__DOT__riscv_32i__DOT__pcE 
                           + vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE)
                        : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__luiE)
                            ? vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE
                            : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
                                ? ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                    ? (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                       - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                    : ((5U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                        ? VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, 
                                                         (0x1fU 
                                                          & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                        : 0U)) : ((4U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                     : 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     | vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     >> 
                                                     (0x1fU 
                                                      & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                     : 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     ^ vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    ((vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                      < vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    VL_LTS_III(32,32,32, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                     ? 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     << 
                                                     (0x1fU 
                                                      & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                     : 
                                                    (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                     + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))))))));
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__aluoutM = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__branchimmE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchimmE 
                = vlTOPp->top__DOT__riscv_32i__DOT__branchimmD;
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__branchE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__branchE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 6U));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__memtoregE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__memtoregE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 4U));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__funct3E = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__funct3E 
                = (7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                         >> 0xcU));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__jumpE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__jumpE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 3U));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__jalrE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__jalrE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 2U));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__auipcE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__auipcE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 1U));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__luiE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__luiE 
                = (1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E 
                = vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D;
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__pcE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcE = vlTOPp->top__DOT__riscv_32i__DOT__pcD;
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE 
                = (0xfffff000U & vlTOPp->top__DOT__riscv_32i__DOT__instnD);
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__alu_subE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__alu_subE 
                = (1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                          ? ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                              ? ((5U == (7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0xcU))) 
                                 & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                    >> 0x1eU)) : (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x1eU))
                          : (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop)));
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE 
                = ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                    ? (7U & ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                              ? (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                 >> 0xcU) : (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0xcU)))
                    : 0U);
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushD) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallD)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D 
                = ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out);
        }
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushD) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__pcD = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallD)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pcD = vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallF)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                = vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_in;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out = 0U;
    }
    vlTOPp->pc = vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out;
    vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF = (((0xdbffU 
                                                   >= 
                                                   (0xffffU 
                                                    & ((IData)(0x23U) 
                                                       + 
                                                       ((IData)(0x37U) 
                                                        * 
                                                        (0x3ffU 
                                                         & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                            >> 2U))))))
                                                   ? 
                                                  (0xfffffU 
                                                   & (((0U 
                                                        == 
                                                        (0x1fU 
                                                         & ((IData)(0x23U) 
                                                            + 
                                                            ((IData)(0x37U) 
                                                             * 
                                                             (0x3ffU 
                                                              & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                                 >> 2U))))))
                                                        ? 0U
                                                        : 
                                                       (vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB[
                                                        ((IData)(1U) 
                                                         + 
                                                         (0x7ffU 
                                                          & (((IData)(0x23U) 
                                                              + 
                                                              ((IData)(0x37U) 
                                                               * 
                                                               (0x3ffU 
                                                                & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                                   >> 2U)))) 
                                                             >> 5U)))] 
                                                        << 
                                                        ((IData)(0x20U) 
                                                         - 
                                                         (0x1fU 
                                                          & ((IData)(0x23U) 
                                                             + 
                                                             ((IData)(0x37U) 
                                                              * 
                                                              (0x3ffU 
                                                               & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                                  >> 2U)))))))) 
                                                      | (vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB[
                                                         (0x7ffU 
                                                          & (((IData)(0x23U) 
                                                              + 
                                                              ((IData)(0x37U) 
                                                               * 
                                                               (0x3ffU 
                                                                & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                                   >> 2U)))) 
                                                             >> 5U))] 
                                                         >> 
                                                         (0x1fU 
                                                          & ((IData)(0x23U) 
                                                             + 
                                                             ((IData)(0x37U) 
                                                              * 
                                                              (0x3ffU 
                                                               & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                                  >> 2U))))))))
                                                   : 0U) 
                                                 == 
                                                 (0xfffffU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                     >> 0xcU)));
    vlTOPp->top__DOT__riscv_32i__DOT__branchimmF = 
        ((0xdbffU >= (0xffffU & ((IData)(0x37U) * (0x3ffU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                      >> 2U)))))
          ? (((0U == (0x1fU & ((IData)(0x37U) * (0x3ffU 
                                                 & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                    >> 2U)))))
               ? 0U : (vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB[
                       ((IData)(1U) + (0x7ffU & (((IData)(0x37U) 
                                                  * 
                                                  (0x3ffU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                      >> 2U))) 
                                                 >> 5U)))] 
                       << ((IData)(0x20U) - (0x1fU 
                                             & ((IData)(0x37U) 
                                                * (0x3ffU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                      >> 2U))))))) 
             | (vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB[
                (0x7ffU & (((IData)(0x37U) * (0x3ffU 
                                              & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                 >> 2U))) 
                           >> 5U))] >> (0x1fU & ((IData)(0x37U) 
                                                 * 
                                                 (0x3ffU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                                     >> 2U))))))
          : 0U);
    vlTOPp->top__DOT__riscv_32i__DOT__BpredF = (1U 
                                                & (vlTOPp->top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE
                                                   [
                                                   (0x3ffU 
                                                    & vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)] 
                                                   >> 1U));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3;
    SData/*13:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0;
    SData/*13:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1;
    SData/*13:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2;
    SData/*13:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3;
    // Body
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2 = 0U;
    __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3 = 0U;
    if (vlTOPp->memwrite) {
        if ((1U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0 
                = (0xffU & vlTOPp->writedata);
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0 = 0U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0 
                = (0x3fffU & (vlTOPp->dataadr >> 2U));
        }
        if ((2U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1 
                = (0xffU & (vlTOPp->writedata >> 8U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1 = 8U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1 
                = (0x3fffU & (vlTOPp->dataadr >> 2U));
        }
        if ((4U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2 
                = (0xffU & (vlTOPp->writedata >> 0x10U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2 = 0x10U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2 
                = (0x3fffU & (vlTOPp->dataadr >> 2U));
        }
        if ((8U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3 
                = (0xffU & (vlTOPp->writedata >> 0x18U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3 = 0x18U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3 
                = (0x3fffU & (vlTOPp->dataadr >> 2U));
        }
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v0) {
        vlTOPp->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0))) 
                & vlTOPp->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0]) 
               | ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v0) 
                  << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v0)));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1) {
        vlTOPp->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1))) 
                & vlTOPp->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1]) 
               | ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1) 
                  << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1)));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2) {
        vlTOPp->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2))) 
                & vlTOPp->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2]) 
               | ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2) 
                  << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2)));
    }
    if (__Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3) {
        vlTOPp->top__DOT__L1_cache__DOT__MEM[__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3))) 
                & vlTOPp->top__DOT__L1_cache__DOT__MEM
                [__Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3]) 
               | ((IData)(__Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3) 
                  << (IData)(__Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3)));
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v1;
    IData/*31:0*/ __Vdlyvval__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0;
    // Body
    __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0 = 0U;
    __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v1 = 0U;
    if (vlTOPp->reset) {
        if (vlTOPp->top__DOT__riscv_32i__DOT__regwriteW) {
            __Vdlyvval__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0 
                = vlTOPp->top__DOT__riscv_32i__DOT__resultW;
            __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0 = 1U;
            __Vdlyvdim0__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0 
                = vlTOPp->top__DOT__riscv_32i__DOT__writeregW;
        }
    } else {
        __Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v1 = 1U;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0) {
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[__Vdlyvdim0__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v0;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf__v1) {
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1fU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1eU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1dU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1cU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1bU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x1aU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x19U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x18U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x17U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x16U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x15U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x14U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x13U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x12U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x11U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0x10U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xfU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xeU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xdU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xcU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xbU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0xaU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[9U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[8U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[7U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[6U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[5U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[4U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[3U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[2U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[1U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0U] = 0U;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->memwrite = vlTOPp->top__DOT__riscv_32i__DOT__memwriteM;
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 
        = vlTOPp->top__DOT__riscv_32i__DOT__writedataM;
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout 
        = vlTOPp->top__DOT__riscv_32i__DOT__aluoutM;
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3 
        = vlTOPp->top__DOT__riscv_32i__DOT__funct3M;
    if ((0U == (IData)(vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3))) {
        if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout)) {
            if ((1U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout)) {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                    = (0xff000000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 
                                      << 0x18U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 8U;
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                    = (0xff0000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 
                                    << 0x10U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 4U;
            }
        } else {
            if ((1U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout)) {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                    = (0xff00U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 
                                  << 8U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 2U;
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                    = (0xffU & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0);
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 1U;
            }
        }
    } else {
        if ((1U == (IData)(vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3))) {
            if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout)) {
                if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout)) {
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                        = (0xffff0000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 
                                          << 0x10U));
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 0xcU;
                } else {
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata = 0U;
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 0U;
                }
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                    = (0xffffU & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0);
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 3U;
            }
        } else {
            vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata 
                = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0;
            vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = 0xfU;
        }
    }
    vlTOPp->top__DOT__dmem_mask = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask;
    vlTOPp->writedata = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata;
    vlTOPp->dataadr = vlTOPp->top__DOT__riscv_32i__DOT__aluoutM;
    vlTOPp->top__DOT__riscv_32i__DOT__resultW = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__memtoregW)
                                                  ? vlTOPp->top__DOT__riscv_32i__DOT__readdataW
                                                  : vlTOPp->top__DOT__riscv_32i__DOT__aluoutW);
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__regwriteW 
                = vlTOPp->top__DOT__riscv_32i__DOT__regwriteM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__regwriteW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallW)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__writeregW 
                = vlTOPp->top__DOT__riscv_32i__DOT__writeregM;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__writeregW = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__regwriteM 
                = vlTOPp->top__DOT__riscv_32i__DOT__regwriteE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__regwriteM = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallM)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__writeregM 
                = vlTOPp->top__DOT__riscv_32i__DOT__rdE;
        }
    } else {
        vlTOPp->top__DOT__riscv_32i__DOT__writeregM = 0U;
    }
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__regwriteE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__regwriteE 
                = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 8U));
        }
    }
    vlTOPp->top__DOT__riscv_32i__DOT__forwardAE = (
                                                   (((0U 
                                                      != (IData)(vlTOPp->top__DOT__riscv_32i__DOT__rsE)) 
                                                     & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rsE) 
                                                        == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))
                                                    ? 2U
                                                    : 
                                                   ((((0U 
                                                       != (IData)(vlTOPp->top__DOT__riscv_32i__DOT__rsE)) 
                                                      & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rsE) 
                                                         == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregW))) 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteW))
                                                     ? 1U
                                                     : 0U));
    vlTOPp->top__DOT__riscv_32i__DOT__forwardBE = (
                                                   (((0U 
                                                      != (IData)(vlTOPp->top__DOT__riscv_32i__DOT__rtE)) 
                                                     & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rtE) 
                                                        == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))
                                                    ? 2U
                                                    : 
                                                   ((((0U 
                                                       != (IData)(vlTOPp->top__DOT__riscv_32i__DOT__rtE)) 
                                                      & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rtE) 
                                                         == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregW))) 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteW))
                                                     ? 1U
                                                     : 0U));
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushE) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__rdE = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallE)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__rdE = 
                (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                          >> 7U));
        }
    }
    vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
        = ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE))
            ? vlTOPp->top__DOT__riscv_32i__DOT__aE : 
           ((1U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE))
             ? vlTOPp->top__DOT__riscv_32i__DOT__resultW
             : ((2U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE))
                 ? vlTOPp->top__DOT__riscv_32i__DOT__aluoutM
                 : 0U)));
    vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0 
        = ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE))
            ? vlTOPp->top__DOT__riscv_32i__DOT__bE : 
           ((1U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE))
             ? vlTOPp->top__DOT__riscv_32i__DOT__resultW
             : ((2U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE))
                 ? vlTOPp->top__DOT__riscv_32i__DOT__aluoutM
                 : 0U)));
    vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE 
        = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alusrcE)
            ? vlTOPp->top__DOT__riscv_32i__DOT__signimmE
            : vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0);
    if ((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__flushD) 
               | (~ (IData)(vlTOPp->reset))))) {
        vlTOPp->top__DOT__riscv_32i__DOT__instnD = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallD)))) {
            vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                = vlTOPp->instr;
        }
    }
    vlTOPp->top__DOT__riscv_32i__DOT__branchimmD = 
        ((0xffffe000U & ((- (IData)((1U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                           >> 0x1fU)))) 
                         << 0xdU)) | ((0x1000U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x13U)) 
                                      | ((0x800U & 
                                          (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                           << 4U)) 
                                         | ((0x7e0U 
                                             & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 7U))))));
    vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD = (
                                                   (0xfffff000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                                      >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | (0xfffU 
                                                      & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                         >> 0x14U)));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->top__DOT__riscv_32i__DOT__instnD);
    vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls
        [vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop
        [vlTOPp->__Vtableidx1];
}

VL_INLINE_OPT void Vtop::_multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_multiclk__TOP__7\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__riscv_32i__DOT__bD = ((((0U != 
                                               (0x1fU 
                                                & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                   >> 0x14U))) 
                                              & ((0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0x14U)) 
                                                 == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                             & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))
                                             ? vlTOPp->top__DOT__riscv_32i__DOT__aluoutM
                                             : ((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0x14U)))
                                                 ? 
                                                vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                                [(0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0x14U))]
                                                 : 0U));
    vlTOPp->top__DOT__riscv_32i__DOT__aD = ((((0U != 
                                               (0x1fU 
                                                & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                   >> 0xfU))) 
                                              & ((0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0xfU)) 
                                                 == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                             & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))
                                             ? vlTOPp->top__DOT__riscv_32i__DOT__aluoutM
                                             : ((0U 
                                                 != 
                                                 (0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0xfU)))
                                                 ? 
                                                vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                                [(0x1fU 
                                                  & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                     >> 0xfU))]
                                                 : 0U));
    vlTOPp->top__DOT__riscv_32i__DOT__br_takenD = (
                                                   ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                                    >> 6U) 
                                                   & ((0x4000U 
                                                       & vlTOPp->top__DOT__riscv_32i__DOT__instnD)
                                                       ? 
                                                      ((0x2000U 
                                                        & vlTOPp->top__DOT__riscv_32i__DOT__instnD)
                                                        ? 
                                                       ((0x1000U 
                                                         & vlTOPp->top__DOT__riscv_32i__DOT__instnD)
                                                         ? 
                                                        (vlTOPp->top__DOT__riscv_32i__DOT__aD 
                                                         >= vlTOPp->top__DOT__riscv_32i__DOT__bD)
                                                         : 
                                                        (vlTOPp->top__DOT__riscv_32i__DOT__aD 
                                                         < vlTOPp->top__DOT__riscv_32i__DOT__bD))
                                                        : 
                                                       ((0x1000U 
                                                         & vlTOPp->top__DOT__riscv_32i__DOT__instnD)
                                                         ? 
                                                        VL_GTES_III(1,32,32, vlTOPp->top__DOT__riscv_32i__DOT__aD, vlTOPp->top__DOT__riscv_32i__DOT__bD)
                                                         : 
                                                        VL_LTS_III(1,32,32, vlTOPp->top__DOT__riscv_32i__DOT__aD, vlTOPp->top__DOT__riscv_32i__DOT__bD)))
                                                       : 
                                                      ((~ 
                                                        (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                         >> 0xdU)) 
                                                       & ((0x1000U 
                                                           & vlTOPp->top__DOT__riscv_32i__DOT__instnD)
                                                           ? 
                                                          (vlTOPp->top__DOT__riscv_32i__DOT__aD 
                                                           != vlTOPp->top__DOT__riscv_32i__DOT__bD)
                                                           : 
                                                          (vlTOPp->top__DOT__riscv_32i__DOT__aD 
                                                           == vlTOPp->top__DOT__riscv_32i__DOT__bD)))));
    vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_in = 
        ((0x40U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
          ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)
              ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredD)
                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
                      ? ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                          ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                          : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                              ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                              : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
                                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
                                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
                                      : ((IData)(4U) 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
                                  : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))))
                      : vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D)
                  : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
                      : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                          ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                          : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                              ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                              : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
                                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
                                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
                                      : ((IData)(4U) 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
                                  : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))))))
              : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredD)
                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
                      : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                          ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                          : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                              ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                              : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
                                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
                                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
                                      : ((IData)(4U) 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
                                  : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))))
                  : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
                      : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                          ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                          : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                              ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                              : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
                                  ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
                                      ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
                                      : ((IData)(4U) 
                                         + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
                                  : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))))))
          : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
              ? ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                  ? ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
                  : (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
                     + ((0xffe00000U & ((- (IData)(
                                                   (1U 
                                                    & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                       >> 0x1fU)))) 
                                        << 0x15U)) 
                        | ((0x100000U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                         >> 0xbU)) 
                           | ((0xff000U & vlTOPp->top__DOT__riscv_32i__DOT__instnD) 
                              | ((0x800U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                            >> 9U)) 
                                 | (0x7feU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                              >> 0x14U))))))))
              : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                  ? (0xfffffffeU & (vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD 
                                    + vlTOPp->top__DOT__riscv_32i__DOT__aD))
                  : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
                      ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
                          ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
                             + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
                          : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
                      : ((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))));
    vlTOPp->top__DOT__dmem_req = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__memtoregM) 
                                  | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__memwriteM));
    vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall = 0U;
    vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall 
        = ((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rdE) 
             == (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                          >> 0xfU))) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rdE) 
                                        == (0x1fU & 
                                            (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0x14U)))) 
           & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__memtoregE));
    vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall 
        = ((((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
               >> 6U) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                         >> 2U)) & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteE)) 
            & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rdE) 
                == (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                             >> 0xfU))) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__rdE) 
                                           == (0x1fU 
                                               & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x14U))))) 
           | (((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                 >> 6U) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                           >> 2U)) & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__memtoregM)) 
              & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM) 
                  == (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                               >> 0xfU))) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM) 
                                             == (0x1fU 
                                                 & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                    >> 0x14U))))));
    vlTOPp->top__DOT__riscv_32i__DOT__stallF = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall) 
                                                | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
    vlTOPp->top__DOT__riscv_32i__DOT__stallD = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall) 
                                                | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
    vlTOPp->top__DOT__riscv_32i__DOT__stallE = 0U;
    vlTOPp->top__DOT__riscv_32i__DOT__stallM = 0U;
    vlTOPp->top__DOT__riscv_32i__DOT__stallW = 0U;
    vlTOPp->top__DOT__riscv_32i__DOT__flushD = (1U 
                                                & ((((~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall)) 
                                                     & (((~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)) 
                                                         & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)) 
                                                        | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD) 
                                                           & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredD) 
                                                              != (IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD))))) 
                                                    | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                                       >> 3U)) 
                                                   | (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                                       >> 2U) 
                                                      & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall)))));
    vlTOPp->top__DOT__riscv_32i__DOT__flushE = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall) 
                                                | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
    vlTOPp->top__DOT__imem_req = (1U & (~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__stallF)));
    vlTOPp->instr = ((IData)(vlTOPp->top__DOT__imem_req)
                      ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                     [(0x3fffU & (vlTOPp->pc >> 2U))]
                      : 0U);
    vlTOPp->readdata = ((IData)(vlTOPp->top__DOT__dmem_req)
                         ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                        [(0x3fffU & (vlTOPp->dataadr 
                                     >> 2U))] : 0U);
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
        = vlTOPp->readdata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout 
        = vlTOPp->top__DOT__riscv_32i__DOT__aluoutM;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3 
        = vlTOPp->top__DOT__riscv_32i__DOT__funct3M;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__result 
        = ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3))
            ? ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3))
                ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3))
                    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                            ? (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                          >> 0x10U))
                            : 0U) : (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata))
                    : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                        ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                            ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                        >> 0x18U)) : 
                           (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                     >> 0x10U))) : 
                       ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                         ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                     >> 8U)) : (0xffU 
                                                & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata)))))
            : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3))
                ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3))
                    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                            ? ((0xffff0000U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                              >> 0x1fU)))) 
                                               << 0x10U)) 
                               | (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                             >> 0x10U)))
                            : 0U) : ((0xffff0000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                      >> 0xfU)))) 
                                       << 0x10U)) | 
                                     (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata)))
                    : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                        ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                            ? ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                              >> 0x1fU)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                           >> 0x18U)))
                            : ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                              >> 0x17U)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                           >> 0x10U))))
                        : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout)
                            ? ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                              >> 0xfU)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                           >> 8U)))
                            : ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata 
                                                              >> 7U)))) 
                                               << 8U)) 
                               | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata)))))));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__Vfuncout 
        = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__result;
    vlTOPp->top__DOT__riscv_32i__DOT__readdataM = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__Vfuncout;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
        vlTOPp->__Vm_traceActivity[3U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) ^ (IData)(vlTOPp->__Vclklast__TOP__clk)) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_multiclk__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
