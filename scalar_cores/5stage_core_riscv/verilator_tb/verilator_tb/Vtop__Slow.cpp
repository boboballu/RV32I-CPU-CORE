// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
SData/*8:0*/ Vtop::__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[128];
CData/*1:0*/ Vtop::__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[128];

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (VL_UNLIKELY((! VL_VALUEPLUSARGS_INN(64,std::string("EXEC=%s"),
                                            vlTOPp->top__DOT__L1_cache__DOT__EXEC)))) {
        VL_WRITEF("FATAL: +EXEC plusarg not found on command line\n");
        VL_WRITEF("[%0t] %%Error: L1_cache.sv:91: Assertion failed in %Ntop.L1_cache\n",
                  64,VL_TIME_UNITED_Q(1),vlSymsp->name());
        VL_STOP_MT("../L1_cache.sv", 91, "");
    }
    VL_WRITEF("%Ntop.L1_cache found +EXEC=%@\n",vlSymsp->name(),
              64,&(vlTOPp->top__DOT__L1_cache__DOT__EXEC));
    VL_READMEM_N(true, 32, 16384, 0, VL_CVT_PACK_STR_NN(vlTOPp->top__DOT__L1_cache__DOT__EXEC)
                 , vlTOPp->top__DOT__L1_cache__DOT__MEM
                 , 0, ~0ULL);
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->memwrite = vlTOPp->top__DOT__riscv_32i__DOT__memwriteM;
    vlTOPp->top__DOT__riscv_32i__DOT__resultW = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__memtoregW)
                                                  ? vlTOPp->top__DOT__riscv_32i__DOT__readdataW
                                                  : vlTOPp->top__DOT__riscv_32i__DOT__aluoutW);
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
    vlTOPp->pc = vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out;
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
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->top__DOT__riscv_32i__DOT__instnD);
    vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls
        [vlTOPp->__Vtableidx1];
    vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop 
        = vlTOPp->__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop
        [vlTOPp->__Vtableidx1];
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
    vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE 
        = ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alusrcE)
            ? vlTOPp->top__DOT__riscv_32i__DOT__signimmE
            : vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0);
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    writedata = VL_RAND_RESET_I(32);
    dataadr = VL_RAND_RESET_I(32);
    readdata = VL_RAND_RESET_I(32);
    pc = VL_RAND_RESET_I(32);
    instr = VL_RAND_RESET_I(32);
    memwrite = VL_RAND_RESET_I(1);
    top__DOT__dmem_req = VL_RAND_RESET_I(1);
    top__DOT__imem_req = VL_RAND_RESET_I(1);
    top__DOT__dmem_mask = VL_RAND_RESET_I(4);
    top__DOT__riscv_32i__DOT__pc_genF_in = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pc_genF_out = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcM = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcW = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__instnD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcplus4D = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__branchimmD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__itypeimmD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__aD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__bD = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__pcplus4E = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__aE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__bE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__signimmE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__utypeimmE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__branchimmE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__aluoutM = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__writedataM = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__branchimmM = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__readdataM = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__readdataW = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__aluoutW = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__branchimmW = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__resultW = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__funct3E = VL_RAND_RESET_I(3);
    top__DOT__riscv_32i__DOT__funct3M = VL_RAND_RESET_I(3);
    top__DOT__riscv_32i__DOT__funct3W = VL_RAND_RESET_I(3);
    top__DOT__riscv_32i__DOT__br_takenD = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__branchE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__br_takenE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__jumpE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__jalrE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__auipcE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__luiE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__regwriteE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__memtoregE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__memwriteE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__alusrcE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__alu_subE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__alucontrolE = VL_RAND_RESET_I(3);
    top__DOT__riscv_32i__DOT__branchM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__br_takenM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__regwriteM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__memtoregM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__memwriteM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__branchW = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__br_takenW = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__regwriteW = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__memtoregW = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__br_actual = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__rsE = VL_RAND_RESET_I(5);
    top__DOT__riscv_32i__DOT__rtE = VL_RAND_RESET_I(5);
    top__DOT__riscv_32i__DOT__rdE = VL_RAND_RESET_I(5);
    top__DOT__riscv_32i__DOT__writeregM = VL_RAND_RESET_I(5);
    top__DOT__riscv_32i__DOT__writeregW = VL_RAND_RESET_I(5);
    top__DOT__riscv_32i__DOT__forwardAE = VL_RAND_RESET_I(2);
    top__DOT__riscv_32i__DOT__forwardBE = VL_RAND_RESET_I(2);
    top__DOT__riscv_32i__DOT__stallF = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__stallD = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__stallE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__stallM = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__stallW = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__flushD = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__flushE = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__branchimmF = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__BTBHitF = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__BpredF = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__BTBHitD = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__BpredD = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[__Vi0] = 0;
    }}
    top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0 = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__ctrl__DOT__aluop = VL_RAND_RESET_I(2);
    top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls = VL_RAND_RESET_I(9);
    top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall = VL_RAND_RESET_I(1);
    top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(56320, top__DOT__riscv_32i__DOT__BTB__DOT__BTB);
    top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound1 = VL_RAND_RESET_I(20);
    top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound2 = VL_RAND_RESET_I(3);
    top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
            top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[__Vi0] = VL_RAND_RESET_I(2);
    }}
    { int __Vi0=0; for (; __Vi0<16384; ++__Vi0) {
            top__DOT__L1_cache__DOT__MEM[__Vi0] = 0;
    }}
    __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3 = VL_RAND_RESET_I(3);
    __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__result = VL_RAND_RESET_I(32);
    __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3 = VL_RAND_RESET_I(3);
    __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout = VL_RAND_RESET_I(32);
    __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0 = VL_RAND_RESET_I(32);
    __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask = VL_RAND_RESET_I(4);
    __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata = VL_RAND_RESET_I(32);
    __Vtableidx1 = 0;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[0] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[1] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[2] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[3] = 0x190U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[4] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[5] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[6] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[7] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[8] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[9] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[10] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[11] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[12] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[13] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[14] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[15] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[16] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[17] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[18] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[19] = 0x180U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[20] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[21] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[22] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[23] = 0x102U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[24] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[25] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[26] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[27] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[28] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[29] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[30] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[31] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[32] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[33] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[34] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[35] = 0xa0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[36] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[37] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[38] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[39] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[40] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[41] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[42] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[43] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[44] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[45] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[46] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[47] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[48] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[49] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[50] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[51] = 0x100U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[52] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[53] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[54] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[55] = 0x101U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[56] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[57] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[58] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[59] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[60] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[61] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[62] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[63] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[64] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[65] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[66] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[67] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[68] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[69] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[70] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[71] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[72] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[73] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[74] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[75] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[76] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[77] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[78] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[79] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[80] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[81] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[82] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[83] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[84] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[85] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[86] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[87] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[88] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[89] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[90] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[91] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[92] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[93] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[94] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[95] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[96] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[97] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[98] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[99] = 0x40U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[100] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[101] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[102] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[103] = 0x104U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[104] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[105] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[106] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[107] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[108] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[109] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[110] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[111] = 0x108U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[112] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[113] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[114] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[115] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[116] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[117] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[118] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[119] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[120] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[121] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[122] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[123] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[124] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[125] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[126] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[127] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[0] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[1] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[2] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[3] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[4] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[5] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[6] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[7] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[8] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[9] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[10] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[11] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[12] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[13] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[14] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[15] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[16] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[17] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[18] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[19] = 3U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[20] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[21] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[22] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[23] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[24] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[25] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[26] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[27] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[28] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[29] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[30] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[31] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[32] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[33] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[34] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[35] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[36] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[37] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[38] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[39] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[40] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[41] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[42] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[43] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[44] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[45] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[46] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[47] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[48] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[49] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[50] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[51] = 2U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[52] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[53] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[54] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[55] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[56] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[57] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[58] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[59] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[60] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[61] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[62] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[63] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[64] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[65] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[66] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[67] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[68] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[69] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[70] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[71] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[72] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[73] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[74] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[75] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[76] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[77] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[78] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[79] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[80] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[81] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[82] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[83] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[84] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[85] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[86] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[87] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[88] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[89] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[90] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[91] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[92] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[93] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[94] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[95] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[96] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[97] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[98] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[99] = 1U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[100] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[101] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[102] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[103] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[104] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[105] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[106] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[107] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[108] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[109] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[110] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[111] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[112] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[113] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[114] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[115] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[116] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[117] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[118] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[119] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[120] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[121] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[122] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[123] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[124] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[125] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[126] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[127] = 0U;
    { int __Vi0=0; for (; __Vi0<5; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
