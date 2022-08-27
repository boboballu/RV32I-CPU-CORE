// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
        bufp->chgIData(oldp+1,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
        bufp->chgIData(oldp+2,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
        bufp->chgIData(oldp+3,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
        bufp->chgIData(oldp+4,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
        bufp->chgIData(oldp+5,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
        bufp->chgIData(oldp+6,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
        bufp->chgIData(oldp+7,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
        bufp->chgIData(oldp+8,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
        bufp->chgIData(oldp+9,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
        bufp->chgIData(oldp+12,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
        bufp->chgIData(oldp+13,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
        bufp->chgIData(oldp+14,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
        bufp->chgIData(oldp+15,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
        bufp->chgIData(oldp+16,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+32,((IData)((0U != (0x30U 
                                              & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))));
        bufp->chgCData(oldp+33,(vlSelf->top__DOT__dmem_mask),4);
        bufp->chgCData(oldp+34,(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
        bufp->chgSData(oldp+35,(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__result),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
        bufp->chgBit(oldp+41,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 8U))));
        bufp->chgBit(oldp+42,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
        bufp->chgBit(oldp+43,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 6U))));
        bufp->chgBit(oldp+44,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 3U))));
        bufp->chgBit(oldp+45,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 2U))));
        bufp->chgBit(oldp+46,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 4U))));
        bufp->chgBit(oldp+47,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 5U))));
        bufp->chgBit(oldp+48,((((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
        bufp->chgBit(oldp+49,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 7U))));
        bufp->chgBit(oldp+50,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                     >> 1U))));
        bufp->chgBit(oldp+51,((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
    }
    bufp->chgBit(oldp+52,(vlSelf->clk));
    bufp->chgBit(oldp+53,(vlSelf->reset));
    bufp->chgIData(oldp+54,(vlSelf->writedata),32);
    bufp->chgIData(oldp+55,(vlSelf->dataadr),32);
    bufp->chgIData(oldp+56,(vlSelf->readdata),32);
    bufp->chgIData(oldp+57,(vlSelf->pc),32);
    bufp->chgIData(oldp+58,(vlSelf->instr),32);
    bufp->chgBit(oldp+59,(vlSelf->memwrite));
    bufp->chgCData(oldp+60,((0x1fU & (vlSelf->instr 
                                      >> 0xfU))),5);
    bufp->chgCData(oldp+61,((0x1fU & (vlSelf->instr 
                                      >> 0x14U))),5);
    bufp->chgCData(oldp+62,((0x1fU & (vlSelf->instr 
                                      >> 7U))),5);
    bufp->chgIData(oldp+63,(((IData)(4U) + vlSelf->pc)),32);
    bufp->chgIData(oldp+64,(((0x20U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                              ? (((- (IData)((vlSelf->instr 
                                              >> 0x1fU))) 
                                  << 0xcU) | ((0xfe0U 
                                               & (vlSelf->instr 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlSelf->instr 
                                                    >> 7U))))
                              : vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)),32);
    bufp->chgIData(oldp+65,((((- (IData)((vlSelf->instr 
                                          >> 0x1fU))) 
                              << 0xdU) | ((0x1000U 
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
                                                      >> 7U))))))),32);
    bufp->chgIData(oldp+66,((((- (IData)((vlSelf->instr 
                                          >> 0x1fU))) 
                              << 0x15U) | ((0x100000U 
                                            & (vlSelf->instr 
                                               >> 0xbU)) 
                                           | ((0xff000U 
                                               & vlSelf->instr) 
                                              | ((0x800U 
                                                  & (vlSelf->instr 
                                                     >> 9U)) 
                                                 | (0x7feU 
                                                    & (vlSelf->instr 
                                                       >> 0x14U))))))),32);
    bufp->chgIData(oldp+67,((((- (IData)((vlSelf->instr 
                                          >> 0x1fU))) 
                              << 0xcU) | ((0xfe0U & 
                                           (vlSelf->instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlSelf->instr 
                                                >> 7U))))),32);
    bufp->chgIData(oldp+68,((0xfffff000U & vlSelf->instr)),32);
    bufp->chgCData(oldp+69,((7U & (vlSelf->instr >> 0xcU))),3);
    bufp->chgCData(oldp+70,((vlSelf->instr >> 0x19U)),7);
    bufp->chgCData(oldp+71,(((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                              ? (7U & ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                        ? (vlSelf->instr 
                                           >> 0xcU)
                                        : (vlSelf->instr 
                                           >> 0xcU)))
                              : 0U)),3);
    bufp->chgBit(oldp+72,((1U & ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                  ? ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                      ? (IData)((0x40005000U 
                                                 == 
                                                 (0x40007000U 
                                                  & vlSelf->instr)))
                                      : (vlSelf->instr 
                                         >> 0x1eU))
                                  : (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop)))));
    bufp->chgIData(oldp+73,(vlSelf->top__DOT__L1_cache__DOT__MEM
                            [(0xfffffU & (vlSelf->pc 
                                          >> 2U))]),32);
    bufp->chgIData(oldp+74,(((IData)((0U != (0x30U 
                                             & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))
                              ? vlSelf->top__DOT__L1_cache__DOT__MEM
                             [(0xfffffU & (vlSelf->dataadr 
                                           >> 2U))]
                              : 0U)),32);
    bufp->chgCData(oldp+75,((0x7fU & vlSelf->instr)),7);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
