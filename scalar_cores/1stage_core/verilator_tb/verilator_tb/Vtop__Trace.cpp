// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
            tracep->chgIData(oldp+1,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
            tracep->chgIData(oldp+2,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
            tracep->chgIData(oldp+3,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
            tracep->chgIData(oldp+4,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
            tracep->chgIData(oldp+5,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
            tracep->chgIData(oldp+6,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
            tracep->chgIData(oldp+7,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
            tracep->chgIData(oldp+8,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
            tracep->chgIData(oldp+9,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
            tracep->chgIData(oldp+10,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
            tracep->chgIData(oldp+11,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
            tracep->chgIData(oldp+12,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
            tracep->chgIData(oldp+13,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
            tracep->chgIData(oldp+14,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
            tracep->chgIData(oldp+15,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
            tracep->chgIData(oldp+16,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
            tracep->chgIData(oldp+17,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
            tracep->chgIData(oldp+18,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
            tracep->chgIData(oldp+19,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
            tracep->chgIData(oldp+20,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
            tracep->chgIData(oldp+21,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
            tracep->chgIData(oldp+22,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
            tracep->chgIData(oldp+23,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
            tracep->chgIData(oldp+24,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
            tracep->chgIData(oldp+25,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
            tracep->chgIData(oldp+26,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
            tracep->chgIData(oldp+27,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
            tracep->chgIData(oldp+28,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
            tracep->chgIData(oldp+29,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
            tracep->chgIData(oldp+30,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
            tracep->chgIData(oldp+31,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+32,((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                            >> 4U) 
                                           | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                              >> 5U)))));
            tracep->chgCData(oldp+33,(vlTOPp->top__DOT__dmem_mask),4);
            tracep->chgCData(oldp+34,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
            tracep->chgSData(oldp+35,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
            tracep->chgIData(oldp+36,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
            tracep->chgIData(oldp+37,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
            tracep->chgIData(oldp+38,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
            tracep->chgIData(oldp+39,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__result),32);
            tracep->chgIData(oldp+40,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
            tracep->chgBit(oldp+41,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 8U))));
            tracep->chgBit(oldp+42,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
            tracep->chgBit(oldp+43,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 6U))));
            tracep->chgBit(oldp+44,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 3U))));
            tracep->chgBit(oldp+45,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 2U))));
            tracep->chgBit(oldp+46,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 4U))));
            tracep->chgBit(oldp+47,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 5U))));
            tracep->chgBit(oldp+48,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                      >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
            tracep->chgBit(oldp+49,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 7U))));
            tracep->chgBit(oldp+50,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 1U))));
            tracep->chgBit(oldp+51,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
        }
        tracep->chgBit(oldp+52,(vlTOPp->clk));
        tracep->chgBit(oldp+53,(vlTOPp->reset));
        tracep->chgIData(oldp+54,(vlTOPp->writedata),32);
        tracep->chgIData(oldp+55,(vlTOPp->dataadr),32);
        tracep->chgIData(oldp+56,(vlTOPp->readdata),32);
        tracep->chgIData(oldp+57,(vlTOPp->pc),32);
        tracep->chgIData(oldp+58,(vlTOPp->instr),32);
        tracep->chgBit(oldp+59,(vlTOPp->memwrite));
        tracep->chgCData(oldp+60,((0x1fU & (vlTOPp->instr 
                                            >> 0xfU))),5);
        tracep->chgCData(oldp+61,((0x1fU & (vlTOPp->instr 
                                            >> 0x14U))),5);
        tracep->chgCData(oldp+62,((0x1fU & (vlTOPp->instr 
                                            >> 7U))),5);
        tracep->chgIData(oldp+63,(((IData)(4U) + vlTOPp->pc)),32);
        tracep->chgIData(oldp+64,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                    ? ((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->instr 
                                                >> 7U))))
                                    : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)),32);
        tracep->chgIData(oldp+65,(((0xffffe000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->instr 
                                                                  >> 0x1fU)))) 
                                                   << 0xdU)) 
                                   | ((0x1000U & (vlTOPp->instr 
                                                  >> 0x13U)) 
                                      | ((0x800U & 
                                          (vlTOPp->instr 
                                           << 4U)) 
                                         | ((0x7e0U 
                                             & (vlTOPp->instr 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlTOPp->instr 
                                                  >> 7U))))))),32);
        tracep->chgIData(oldp+66,(((0xffe00000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->instr 
                                                                  >> 0x1fU)))) 
                                                   << 0x15U)) 
                                   | ((0x100000U & 
                                       (vlTOPp->instr 
                                        >> 0xbU)) | 
                                      ((0xff000U & vlTOPp->instr) 
                                       | ((0x800U & 
                                           (vlTOPp->instr 
                                            >> 9U)) 
                                          | (0x7feU 
                                             & (vlTOPp->instr 
                                                >> 0x14U))))))),32);
        tracep->chgIData(oldp+67,(((0xfffff000U & (
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlTOPp->instr 
                                                                  >> 0x1fU)))) 
                                                   << 0xcU)) 
                                   | ((0xfe0U & (vlTOPp->instr 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->instr 
                                                  >> 7U))))),32);
        tracep->chgIData(oldp+68,((0xfffff000U & vlTOPp->instr)),32);
        tracep->chgCData(oldp+69,((7U & (vlTOPp->instr 
                                         >> 0xcU))),3);
        tracep->chgCData(oldp+70,((0x7fU & (vlTOPp->instr 
                                            >> 0x19U))),7);
        tracep->chgCData(oldp+71,(((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                    ? (7U & ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                              ? (vlTOPp->instr 
                                                 >> 0xcU)
                                              : (vlTOPp->instr 
                                                 >> 0xcU)))
                                    : 0U)),3);
        tracep->chgBit(oldp+72,((1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                        ? ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                            ? ((5U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->instr 
                                                    >> 0xcU))) 
                                               & (vlTOPp->instr 
                                                  >> 0x1eU))
                                            : (vlTOPp->instr 
                                               >> 0x1eU))
                                        : (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop)))));
        tracep->chgIData(oldp+73,(vlTOPp->top__DOT__L1_cache__DOT__MEM
                                  [(0x3fffU & (vlTOPp->pc 
                                               >> 2U))]),32);
        tracep->chgIData(oldp+74,(((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 4U) | 
                                          ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                           >> 5U)))
                                    ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                   [(0x3fffU & (vlTOPp->dataadr 
                                                >> 2U))]
                                    : 0U)),32);
        tracep->chgCData(oldp+75,((0x7fU & vlTOPp->instr)),7);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
