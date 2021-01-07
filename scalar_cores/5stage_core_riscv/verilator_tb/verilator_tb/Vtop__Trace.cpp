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
            tracep->chgIData(oldp+0,(vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out),32);
            tracep->chgIData(oldp+1,(vlTOPp->top__DOT__riscv_32i__DOT__pcD),32);
            tracep->chgIData(oldp+2,(vlTOPp->top__DOT__riscv_32i__DOT__pcE),32);
            tracep->chgIData(oldp+3,(vlTOPp->top__DOT__riscv_32i__DOT__pcM),32);
            tracep->chgIData(oldp+4,(vlTOPp->top__DOT__riscv_32i__DOT__pcW),32);
            tracep->chgIData(oldp+5,(((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)),32);
            tracep->chgIData(oldp+6,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D),32);
            tracep->chgIData(oldp+7,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E),32);
            tracep->chgIData(oldp+8,(vlTOPp->top__DOT__riscv_32i__DOT__aE),32);
            tracep->chgIData(oldp+9,(vlTOPp->top__DOT__riscv_32i__DOT__bE),32);
            tracep->chgIData(oldp+10,(vlTOPp->top__DOT__riscv_32i__DOT__signimmE),32);
            tracep->chgIData(oldp+11,(vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE),32);
            tracep->chgIData(oldp+12,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmE),32);
            tracep->chgIData(oldp+13,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutM),32);
            tracep->chgIData(oldp+14,(vlTOPp->top__DOT__riscv_32i__DOT__writedataM),32);
            tracep->chgIData(oldp+15,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmM),32);
            tracep->chgIData(oldp+16,(vlTOPp->top__DOT__riscv_32i__DOT__readdataW),32);
            tracep->chgIData(oldp+17,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutW),32);
            tracep->chgIData(oldp+18,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmW),32);
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__riscv_32i__DOT__funct3E),3);
            tracep->chgCData(oldp+20,(vlTOPp->top__DOT__riscv_32i__DOT__funct3M),3);
            tracep->chgCData(oldp+21,(vlTOPp->top__DOT__riscv_32i__DOT__funct3W),3);
            tracep->chgBit(oldp+22,(vlTOPp->top__DOT__riscv_32i__DOT__branchE));
            tracep->chgBit(oldp+23,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenE));
            tracep->chgBit(oldp+24,(vlTOPp->top__DOT__riscv_32i__DOT__jumpE));
            tracep->chgBit(oldp+25,(vlTOPp->top__DOT__riscv_32i__DOT__jalrE));
            tracep->chgBit(oldp+26,(vlTOPp->top__DOT__riscv_32i__DOT__auipcE));
            tracep->chgBit(oldp+27,(vlTOPp->top__DOT__riscv_32i__DOT__luiE));
            tracep->chgBit(oldp+28,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregE));
            tracep->chgBit(oldp+29,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteE));
            tracep->chgBit(oldp+30,(vlTOPp->top__DOT__riscv_32i__DOT__alusrcE));
            tracep->chgBit(oldp+31,(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE));
            tracep->chgCData(oldp+32,(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE),3);
            tracep->chgBit(oldp+33,(vlTOPp->top__DOT__riscv_32i__DOT__branchM));
            tracep->chgBit(oldp+34,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenM));
            tracep->chgBit(oldp+35,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregM));
            tracep->chgBit(oldp+36,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteM));
            tracep->chgBit(oldp+37,(vlTOPp->top__DOT__riscv_32i__DOT__branchW));
            tracep->chgBit(oldp+38,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenW));
            tracep->chgBit(oldp+39,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregW));
            tracep->chgCData(oldp+40,(vlTOPp->top__DOT__riscv_32i__DOT__rsE),5);
            tracep->chgCData(oldp+41,(vlTOPp->top__DOT__riscv_32i__DOT__rtE),5);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+42,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0]),32);
            tracep->chgIData(oldp+43,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[1]),32);
            tracep->chgIData(oldp+44,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[2]),32);
            tracep->chgIData(oldp+45,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[3]),32);
            tracep->chgIData(oldp+46,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[4]),32);
            tracep->chgIData(oldp+47,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[5]),32);
            tracep->chgIData(oldp+48,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[6]),32);
            tracep->chgIData(oldp+49,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[7]),32);
            tracep->chgIData(oldp+50,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[8]),32);
            tracep->chgIData(oldp+51,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[9]),32);
            tracep->chgIData(oldp+52,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[10]),32);
            tracep->chgIData(oldp+53,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[11]),32);
            tracep->chgIData(oldp+54,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[12]),32);
            tracep->chgIData(oldp+55,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[13]),32);
            tracep->chgIData(oldp+56,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[14]),32);
            tracep->chgIData(oldp+57,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[15]),32);
            tracep->chgIData(oldp+58,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[16]),32);
            tracep->chgIData(oldp+59,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[17]),32);
            tracep->chgIData(oldp+60,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[18]),32);
            tracep->chgIData(oldp+61,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[19]),32);
            tracep->chgIData(oldp+62,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[20]),32);
            tracep->chgIData(oldp+63,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[21]),32);
            tracep->chgIData(oldp+64,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[22]),32);
            tracep->chgIData(oldp+65,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[23]),32);
            tracep->chgIData(oldp+66,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[24]),32);
            tracep->chgIData(oldp+67,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[25]),32);
            tracep->chgIData(oldp+68,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[26]),32);
            tracep->chgIData(oldp+69,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[27]),32);
            tracep->chgIData(oldp+70,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[28]),32);
            tracep->chgIData(oldp+71,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[29]),32);
            tracep->chgIData(oldp+72,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[30]),32);
            tracep->chgIData(oldp+73,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[31]),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgCData(oldp+74,(vlTOPp->top__DOT__dmem_mask),4);
            tracep->chgIData(oldp+75,(vlTOPp->top__DOT__riscv_32i__DOT__instnD),32);
            tracep->chgIData(oldp+76,(((0xffe00000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                          >> 0x1fU)))) 
                                           << 0x15U)) 
                                       | ((0x100000U 
                                           & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                              >> 0xbU)) 
                                          | ((0xff000U 
                                              & vlTOPp->top__DOT__riscv_32i__DOT__instnD) 
                                             | ((0x800U 
                                                 & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                    >> 9U)) 
                                                | (0x7feU 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                      >> 0x14U))))))),32);
            tracep->chgIData(oldp+77,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmD),32);
            tracep->chgIData(oldp+78,((0xfffff000U 
                                       & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),32);
            tracep->chgIData(oldp+79,(vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD),32);
            tracep->chgIData(oldp+80,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+81,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
                                        ? ((0xfffff000U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                              >> 0x1fU)))) 
                                               << 0xcU)) 
                                           | ((0xfe0U 
                                               & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x14U)) 
                                              | (0x1fU 
                                                 & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                    >> 7U))))
                                        : vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD)),32);
            tracep->chgIData(oldp+82,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0),32);
            tracep->chgIData(oldp+83,(vlTOPp->top__DOT__riscv_32i__DOT__resultW),32);
            tracep->chgCData(oldp+84,((0x7fU & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),7);
            tracep->chgCData(oldp+85,((7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+86,((0x7fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                >> 0x19U))),7);
            tracep->chgBit(oldp+87,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 2U))));
            tracep->chgBit(oldp+88,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 1U))));
            tracep->chgBit(oldp+89,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))));
            tracep->chgBit(oldp+90,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 6U))));
            tracep->chgBit(oldp+91,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 3U))));
            tracep->chgBit(oldp+92,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 8U))));
            tracep->chgBit(oldp+93,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 4U))));
            tracep->chgBit(oldp+94,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 5U))));
            tracep->chgBit(oldp+95,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
                                           >> 7U))));
            tracep->chgBit(oldp+96,((1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                            ? ((1U 
                                                & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                                ? (
                                                   (5U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                        >> 0xcU))) 
                                                   & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                      >> 0x1eU))
                                                : (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                   >> 0x1eU))
                                            : (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop)))));
            tracep->chgCData(oldp+97,(((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                        ? (7U & ((1U 
                                                  & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop))
                                                  ? 
                                                 (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0xcU)
                                                  : 
                                                 (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0xcU)))
                                        : 0U)),3);
            tracep->chgBit(oldp+98,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteE));
            tracep->chgBit(oldp+99,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM));
            tracep->chgBit(oldp+100,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteW));
            tracep->chgCData(oldp+101,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+102,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 0x14U))),5);
            tracep->chgCData(oldp+103,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                 >> 7U))),5);
            tracep->chgCData(oldp+104,(vlTOPp->top__DOT__riscv_32i__DOT__rdE),5);
            tracep->chgCData(oldp+105,(vlTOPp->top__DOT__riscv_32i__DOT__writeregM),5);
            tracep->chgCData(oldp+106,(vlTOPp->top__DOT__riscv_32i__DOT__writeregW),5);
            tracep->chgBit(oldp+107,((((0U != (0x1fU 
                                               & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0xfU))) 
                                       & ((0x1fU & 
                                           (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                            >> 0xfU)) 
                                          == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
            tracep->chgBit(oldp+108,((((0U != (0x1fU 
                                               & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                                  >> 0x14U))) 
                                       & ((0x1fU & 
                                           (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                            >> 0x14U)) 
                                          == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
                                      & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
            tracep->chgCData(oldp+109,(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE),2);
            tracep->chgCData(oldp+110,(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE),2);
            tracep->chgIData(oldp+111,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE),32);
            tracep->chgIData(oldp+112,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE),32);
            tracep->chgCData(oldp+113,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop),2);
            tracep->chgSData(oldp+114,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls),9);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+115,(vlTOPp->top__DOT__dmem_req));
            tracep->chgBit(oldp+116,(vlTOPp->top__DOT__imem_req));
            tracep->chgIData(oldp+117,(vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_in),32);
            tracep->chgIData(oldp+118,(vlTOPp->top__DOT__riscv_32i__DOT__aD),32);
            tracep->chgIData(oldp+119,(vlTOPp->top__DOT__riscv_32i__DOT__bD),32);
            tracep->chgIData(oldp+120,(vlTOPp->top__DOT__riscv_32i__DOT__readdataM),32);
            tracep->chgBit(oldp+121,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD));
            tracep->chgBit(oldp+122,(vlTOPp->top__DOT__riscv_32i__DOT__stallF));
            tracep->chgBit(oldp+123,(vlTOPp->top__DOT__riscv_32i__DOT__stallD));
            tracep->chgBit(oldp+124,(vlTOPp->top__DOT__riscv_32i__DOT__stallE));
            tracep->chgBit(oldp+125,(vlTOPp->top__DOT__riscv_32i__DOT__stallM));
            tracep->chgBit(oldp+126,(vlTOPp->top__DOT__riscv_32i__DOT__stallW));
            tracep->chgBit(oldp+127,(vlTOPp->top__DOT__riscv_32i__DOT__flushD));
            tracep->chgBit(oldp+128,(vlTOPp->top__DOT__riscv_32i__DOT__flushE));
            tracep->chgBit(oldp+129,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall));
            tracep->chgBit(oldp+130,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
            tracep->chgBit(oldp+131,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall));
        }
        tracep->chgBit(oldp+132,(vlTOPp->clk));
        tracep->chgBit(oldp+133,(vlTOPp->reset));
        tracep->chgIData(oldp+134,(vlTOPp->writedata),32);
        tracep->chgIData(oldp+135,(vlTOPp->dataadr),32);
        tracep->chgIData(oldp+136,(vlTOPp->readdata),32);
        tracep->chgIData(oldp+137,(vlTOPp->pc),32);
        tracep->chgIData(oldp+138,(vlTOPp->instr),32);
        tracep->chgBit(oldp+139,(vlTOPp->memwrite));
        tracep->chgIData(oldp+140,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__jumpE) 
                                     | (IData)(vlTOPp->top__DOT__riscv_32i__DOT__jalrE))
                                     ? vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E
                                     : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__auipcE)
                                         ? (vlTOPp->top__DOT__riscv_32i__DOT__pcE 
                                            + vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE)
                                         : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__luiE)
                                             ? vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE
                                             : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
                                                 ? 
                                                ((0U 
                                                  == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                  ? 
                                                 (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                  - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, 
                                                                 (0x1fU 
                                                                  & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                   : 0U))
                                                 : 
                                                ((4U 
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
                                                    + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))))))))),32);
        tracep->chgIData(oldp+141,(((0U != (0x1fU & 
                                            (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0xfU)))
                                     ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                    [(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0xfU))]
                                     : 0U)),32);
        tracep->chgIData(oldp+142,(((0U != (0x1fU & 
                                            (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                             >> 0x14U)))
                                     ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
                                    [(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
                                               >> 0x14U))]
                                     : 0U)),32);
        tracep->chgIData(oldp+143,(((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
                                     ? ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                         ? (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                            - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                         : ((5U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                             ? VL_SHIFTRS_III(32,32,5, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, 
                                                              (0x1fU 
                                                               & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                             : 0U))
                                     : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                         ? ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                 ? 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                 : 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 | vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                             : ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                 ? 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 >> 
                                                 (0x1fU 
                                                  & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                 : 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 ^ vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
                                         : ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                             ? ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                 ? 
                                                ((vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                  < vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
                                                  ? 1U
                                                  : 0U)
                                                 : 
                                                VL_LTS_III(32,32,32, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE, vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                             : ((1U 
                                                 & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
                                                 ? 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 << 
                                                 (0x1fU 
                                                  & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE))
                                                 : 
                                                (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
                                                 + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))))),32);
        tracep->chgIData(oldp+144,(((IData)(vlTOPp->top__DOT__imem_req)
                                     ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                    [(0xfffffU & (vlTOPp->pc 
                                                  >> 2U))]
                                     : 0U)),32);
        tracep->chgIData(oldp+145,(((IData)(vlTOPp->top__DOT__dmem_req)
                                     ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                    [(0xfffffU & (vlTOPp->dataadr 
                                                  >> 2U))]
                                     : 0U)),32);
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
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
    }
}
