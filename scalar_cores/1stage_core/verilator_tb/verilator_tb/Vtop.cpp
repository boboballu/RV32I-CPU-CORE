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
            VL_FATAL_MT("../rtl_top_test.sv", 10, "",
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
            VL_FATAL_MT("../rtl_top_test.sv", 10, "",
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
    CData/*4:0*/ __Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1;
    IData/*31:0*/ __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    IData/*31:0*/ __Vtemp1;
    // Body
    __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 0U;
    __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1 = 0U;
    if (vlTOPp->reset) {
        if ((0x100U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))) {
            __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
                = vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__result;
            __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 1U;
            __Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
                = (0x1fU & (vlTOPp->instr >> 7U));
        }
    } else {
        __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1 = 1U;
    }
    __Vtemp1 = ((IData)(vlTOPp->reset) ? ((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                            >> 6U) 
                                           & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))
                                           ? ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                               ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                               : ((4U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                                   ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                                   : 
                                                  (vlTOPp->pc 
                                                   + 
                                                   ((0xffffe000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->instr 
                                                                       >> 0x1fU)))) 
                                                        << 0xdU)) 
                                                    | ((0x1000U 
                                                        & (vlTOPp->instr 
                                                           >> 0x13U)) 
                                                       | ((0x800U 
                                                           & (vlTOPp->instr 
                                                              << 4U)) 
                                                          | ((0x7e0U 
                                                              & (vlTOPp->instr 
                                                                 >> 0x14U)) 
                                                             | (0x1eU 
                                                                & (vlTOPp->instr 
                                                                   >> 7U)))))))))
                                           : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                               ? ((4U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                                   ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
                                                   : 
                                                  (vlTOPp->pc 
                                                   + 
                                                   ((0xffe00000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->instr 
                                                                       >> 0x1fU)))) 
                                                        << 0x15U)) 
                                                    | ((0x100000U 
                                                        & (vlTOPp->instr 
                                                           >> 0xbU)) 
                                                       | ((0xff000U 
                                                           & vlTOPp->instr) 
                                                          | ((0x800U 
                                                              & (vlTOPp->instr 
                                                                 >> 9U)) 
                                                             | (0x7feU 
                                                                & (vlTOPp->instr 
                                                                   >> 0x14U))))))))
                                               : ((4U 
                                                   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                                   ? 
                                                  (0xfffffffeU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
                                                      + vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca))
                                                   : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4)))
                 : 0U);
    vlTOPp->pc = __Vtemp1;
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0) {
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[__Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    }
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v1) {
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1fU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1eU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1dU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1cU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1bU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x1aU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x19U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x18U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x17U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x16U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x15U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x14U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x13U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x12U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x11U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0x10U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xfU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xeU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xdU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xcU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xbU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0xaU] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1U] = 0U;
        vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0U] = 0U;
    }
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 
        = ((IData)(4U) + vlTOPp->pc);
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
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v0;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2;
    IData/*19:0*/ __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3;
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
                = (0xfffffU & (vlTOPp->dataadr >> 2U));
        }
        if ((2U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v1 
                = (0xffU & (vlTOPp->writedata >> 8U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v1 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v1 = 8U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v1 
                = (0xfffffU & (vlTOPp->dataadr >> 2U));
        }
        if ((4U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v2 
                = (0xffU & (vlTOPp->writedata >> 0x10U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v2 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v2 = 0x10U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v2 
                = (0xfffffU & (vlTOPp->dataadr >> 2U));
        }
        if ((8U & (IData)(vlTOPp->top__DOT__dmem_mask))) {
            __Vdlyvval__top__DOT__L1_cache__DOT__MEM__v3 
                = (0xffU & (vlTOPp->writedata >> 0x18U));
            __Vdlyvset__top__DOT__L1_cache__DOT__MEM__v3 = 1U;
            __Vdlyvlsb__top__DOT__L1_cache__DOT__MEM__v3 = 0x18U;
            __Vdlyvdim0__top__DOT__L1_cache__DOT__MEM__v3 
                = (0xfffffU & (vlTOPp->dataadr >> 2U));
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

VL_INLINE_OPT void Vtop::_sequent__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->instr = vlTOPp->top__DOT__L1_cache__DOT__MEM
        [(0xfffffU & (vlTOPp->pc >> 2U))];
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
        = ((0U != (0x1fU & (vlTOPp->instr >> 0xfU)))
            ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
           [(0x1fU & (vlTOPp->instr >> 0xfU))] : 0U);
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
        = ((0xfffff000U & ((- (IData)((1U & (vlTOPp->instr 
                                             >> 0x1fU)))) 
                           << 0xcU)) | (0xfffU & (vlTOPp->instr 
                                                  >> 0x14U)));
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0 
        = ((0U != (0x1fU & (vlTOPp->instr >> 0x14U)))
            ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
           [(0x1fU & (vlTOPp->instr >> 0x14U))] : 0U);
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->instr);
    vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls
        [vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop
        [vlTOPp->__Vtableidx1];
    vlTOPp->memwrite = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                              >> 5U));
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb 
        = ((0x80U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
            ? ((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                ? ((0xfffff000U & ((- (IData)((1U & 
                                               (vlTOPp->instr 
                                                >> 0x1fU)))) 
                                   << 0xcU)) | ((0xfe0U 
                                                 & (vlTOPp->instr 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlTOPp->instr 
                                                      >> 7U))))
                : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)
            : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0);
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb 
        = vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
        = vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3 
        = (7U & (vlTOPp->instr >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch 
        = (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                 >> 6U));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken 
        = ((IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch) 
           & ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
               ? ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                   ? ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                       ? (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                          >= vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                       : (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                          < vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb))
                   : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                       ? VL_GTES_III(1,32,32, vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca, vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                       : VL_LTS_III(1,32,32, vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca, vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)))
               : ((~ ((IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3) 
                      >> 1U)) & ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3))
                                  ? (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                                     != vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)
                                  : (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
                                     == vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb)))));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout 
        = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken;
    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken 
        = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    vlTOPp->dataadr = ((1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                               ? ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                   ? ((5U == (7U & 
                                              (vlTOPp->instr 
                                               >> 0xcU))) 
                                      & (vlTOPp->instr 
                                         >> 0x1eU))
                                   : (vlTOPp->instr 
                                      >> 0x1eU)) : (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop)))
                        ? ((0U == ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                    ? (7U & ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                              ? (vlTOPp->instr 
                                                 >> 0xcU)
                                              : (vlTOPp->instr 
                                                 >> 0xcU)))
                                    : 0U)) ? (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                              - vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                            : ((5U == ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                        ? (7U & ((1U 
                                                  & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                  ? 
                                                 (vlTOPp->instr 
                                                  >> 0xcU)
                                                  : 
                                                 (vlTOPp->instr 
                                                  >> 0xcU)))
                                        : 0U)) ? VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca, 
                                                                (0x1fU 
                                                                 & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                : 0U)) : (((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                            ? (4U & 
                                               ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                 ? 
                                                (vlTOPp->instr 
                                                 >> 0xcU)
                                                 : 
                                                (vlTOPp->instr 
                                                 >> 0xcU)))
                                            : 0U) ? 
                                          (((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                             ? (2U 
                                                & ((1U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (vlTOPp->instr 
                                                    >> 0xcU)
                                                    : 
                                                   (vlTOPp->instr 
                                                    >> 0xcU)))
                                             : 0U) ? 
                                           (((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                              ? (1U 
                                                 & ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                     ? 
                                                    (vlTOPp->instr 
                                                     >> 0xcU)
                                                     : 
                                                    (vlTOPp->instr 
                                                     >> 0xcU)))
                                              : 0U)
                                             ? (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                             : (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                | vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                            : (((2U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                 ? 
                                                (1U 
                                                 & ((1U 
                                                     & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                     ? 
                                                    (vlTOPp->instr 
                                                     >> 0xcU)
                                                     : 
                                                    (vlTOPp->instr 
                                                     >> 0xcU)))
                                                 : 0U)
                                                ? (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   >> 
                                                   (0x1fU 
                                                    & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                                : (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   ^ vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))
                                           : (((2U 
                                                & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                ? (2U 
                                                   & ((1U 
                                                       & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                       ? 
                                                      (vlTOPp->instr 
                                                       >> 0xcU)
                                                       : 
                                                      (vlTOPp->instr 
                                                       >> 0xcU)))
                                                : 0U)
                                               ? ((
                                                   (2U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (1U 
                                                    & ((1U 
                                                        & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                        ? 
                                                       (vlTOPp->instr 
                                                        >> 0xcU)
                                                        : 
                                                       (vlTOPp->instr 
                                                        >> 0xcU)))
                                                    : 0U)
                                                   ? 
                                                  ((vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                    < vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  (VL_LTS_III(1,32,32, vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca, vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
                                                    ? 1U
                                                    : 0U))
                                               : ((
                                                   (2U 
                                                    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                    ? 
                                                   (1U 
                                                    & ((1U 
                                                        & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                                        ? 
                                                       (vlTOPp->instr 
                                                        >> 0xcU)
                                                        : 
                                                       (vlTOPp->instr 
                                                        >> 0xcU)))
                                                    : 0U)
                                                   ? 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   << 
                                                   (0x1fU 
                                                    & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
                                                   : 
                                                  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
                                                   + vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))));
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
        = vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout 
        = vlTOPp->dataadr;
    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3 
        = (7U & (vlTOPp->instr >> 0xcU));
    if ((0U == (IData)(vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))) {
        if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
            if ((1U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xff000000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                                      << 0x18U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 8U;
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xff0000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                                    << 0x10U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 4U;
            }
        } else {
            if ((1U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xff00U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                                  << 8U));
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 2U;
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xffU & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0);
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 1U;
            }
        }
    } else {
        if ((1U == (IData)(vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))) {
            if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                if ((2U & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)) {
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                        = (0xffff0000U & (vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
                                          << 0x10U));
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0xcU;
                } else {
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata = 0U;
                    vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0U;
                }
            } else {
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                    = (0xffffU & vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0);
                vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 3U;
            }
        } else {
            vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
                = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0;
            vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask = 0xfU;
        }
    }
    vlTOPp->top__DOT__dmem_mask = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask;
    vlTOPp->writedata = vlTOPp->__Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
    vlTOPp->readdata = ((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                >> 4U) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                          >> 5U))) ? 
                        vlTOPp->top__DOT__L1_cache__DOT__MEM
                        [(0xfffffU & (vlTOPp->dataadr 
                                      >> 2U))] : 0U);
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
        = vlTOPp->readdata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout 
        = vlTOPp->dataadr;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3 
        = (7U & (vlTOPp->instr >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result 
        = ((4U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
            ? ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                          >> 0x10U))
                            : 0U) : (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata))
                    : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                        >> 0x18U)) : 
                           (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                     >> 0x10U))) : 
                       ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                         ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                     >> 8U)) : (0xffU 
                                                & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))
            : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
                : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
                    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? ((0xffff0000U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                              >> 0x1fU)))) 
                                               << 0x10U)) 
                               | (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                             >> 0x10U)))
                            : 0U) : ((0xffff0000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                      >> 0xfU)))) 
                                       << 0x10U)) | 
                                     (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))
                    : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                        ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                              >> 0x1fU)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                           >> 0x18U)))
                            : ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                              >> 0x17U)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                           >> 0x10U))))
                        : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
                            ? ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                              >> 0xfU)))) 
                                               << 8U)) 
                               | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                           >> 8U)))
                            : ((0xffffff00U & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
                                                              >> 7U)))) 
                                               << 8U)) 
                               | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout 
        = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__result 
        = ((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                   >> 3U) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                             >> 2U))) ? ((IData)(4U) 
                                         + vlTOPp->pc)
            : ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                ? (vlTOPp->pc + (0xfffff000U & vlTOPp->instr))
                : ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                    ? (0xfffff000U & vlTOPp->instr)
                    : ((0x10U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                        ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout
                        : vlTOPp->dataadr))));
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
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
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
