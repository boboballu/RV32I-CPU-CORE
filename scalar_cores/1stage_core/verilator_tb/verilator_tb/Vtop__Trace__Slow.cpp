// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+52,"clk", false,-1);
        tracep->declBit(c+53,"reset", false,-1);
        tracep->declBus(c+54,"writedata", false,-1, 31,0);
        tracep->declBus(c+55,"dataadr", false,-1, 31,0);
        tracep->declBus(c+56,"readdata", false,-1, 31,0);
        tracep->declBus(c+57,"pc", false,-1, 31,0);
        tracep->declBus(c+58,"instr", false,-1, 31,0);
        tracep->declBit(c+59,"memwrite", false,-1);
        tracep->declBit(c+52,"top clk", false,-1);
        tracep->declBit(c+53,"top reset", false,-1);
        tracep->declBus(c+54,"top writedata", false,-1, 31,0);
        tracep->declBus(c+55,"top dataadr", false,-1, 31,0);
        tracep->declBus(c+56,"top readdata", false,-1, 31,0);
        tracep->declBus(c+57,"top pc", false,-1, 31,0);
        tracep->declBus(c+58,"top instr", false,-1, 31,0);
        tracep->declBit(c+59,"top memwrite", false,-1);
        tracep->declBit(c+76,"top Iwait", false,-1);
        tracep->declBit(c+76,"top Dwait", false,-1);
        tracep->declBit(c+1,"top memaccess", false,-1);
        tracep->declBit(c+52,"top riscv_32i clk", false,-1);
        tracep->declBit(c+53,"top riscv_32i reset", false,-1);
        tracep->declBus(c+57,"top riscv_32i pc", false,-1, 31,0);
        tracep->declBus(c+58,"top riscv_32i instr", false,-1, 31,0);
        tracep->declBit(c+59,"top riscv_32i memwrite", false,-1);
        tracep->declBus(c+55,"top riscv_32i aluout", false,-1, 31,0);
        tracep->declBus(c+54,"top riscv_32i writedata", false,-1, 31,0);
        tracep->declBit(c+1,"top riscv_32i memaccess", false,-1);
        tracep->declBus(c+56,"top riscv_32i readdata", false,-1, 31,0);
        tracep->declBit(c+76,"top riscv_32i Iwait", false,-1);
        tracep->declBit(c+76,"top riscv_32i Dwait", false,-1);
        tracep->declBus(c+2,"top riscv_32i controller aluop", false,-1, 1,0);
        tracep->declBus(c+2,"top riscv_32i controller maindec aluop", false,-1, 1,0);
        tracep->declBus(c+3,"top riscv_32i controller maindec controls", false,-1, 8,0);
        tracep->declBus(c+2,"top riscv_32i controller aludec aluop", false,-1, 1,0);
        tracep->declBit(c+52,"top riscv_32i datapath clk", false,-1);
        tracep->declBit(c+53,"top riscv_32i datapath reset", false,-1);
        tracep->declBus(c+57,"top riscv_32i datapath pc", false,-1, 31,0);
        tracep->declBus(c+55,"top riscv_32i datapath aluout", false,-1, 31,0);
        tracep->declBus(c+54,"top riscv_32i datapath writedata", false,-1, 31,0);
        tracep->declBus(c+56,"top riscv_32i datapath readdata", false,-1, 31,0);
        tracep->declBit(c+1,"top riscv_32i datapath memaccess", false,-1);
        tracep->declBit(c+76,"top riscv_32i datapath Iwait", false,-1);
        tracep->declBit(c+76,"top riscv_32i datapath Dwait", false,-1);
        tracep->declBus(c+60,"top riscv_32i datapath rs1", false,-1, 4,0);
        tracep->declBus(c+61,"top riscv_32i datapath rs2", false,-1, 4,0);
        tracep->declBus(c+62,"top riscv_32i datapath rd", false,-1, 4,0);
        tracep->declBus(c+63,"top riscv_32i datapath pcplus4", false,-1, 31,0);
        tracep->declBus(c+64,"top riscv_32i datapath signimm", false,-1, 31,0);
        tracep->declBus(c+65,"top riscv_32i datapath branchimm", false,-1, 31,0);
        tracep->declBus(c+66,"top riscv_32i datapath jumpimm", false,-1, 31,0);
        tracep->declBus(c+67,"top riscv_32i datapath stypeimm", false,-1, 31,0);
        tracep->declBus(c+4,"top riscv_32i datapath itypeimm", false,-1, 31,0);
        tracep->declBus(c+68,"top riscv_32i datapath utypeimm", false,-1, 31,0);
        tracep->declBus(c+5,"top riscv_32i datapath srca", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i datapath srcb", false,-1, 31,0);
        tracep->declBus(c+7,"top riscv_32i datapath result", false,-1, 31,0);
        tracep->declBus(c+8,"top riscv_32i datapath srcb_net0", false,-1, 31,0);
        tracep->declBus(c+69,"top riscv_32i datapath funct3", false,-1, 2,0);
        tracep->declBus(c+70,"top riscv_32i datapath funct7", false,-1, 6,0);
        tracep->declBit(c+76,"top riscv_32i datapath en_pc_reg", false,-1);
        tracep->declBus(c+58,"top riscv_32i datapath instn_decode instr", false,-1, 31,0);
        tracep->declBus(c+69,"top riscv_32i datapath instn_decode funct3", false,-1, 2,0);
        tracep->declBus(c+70,"top riscv_32i datapath instn_decode funct7", false,-1, 6,0);
        tracep->declBus(c+66,"top riscv_32i datapath instn_decode jumpimm", false,-1, 31,0);
        tracep->declBus(c+65,"top riscv_32i datapath instn_decode branchimm", false,-1, 31,0);
        tracep->declBus(c+68,"top riscv_32i datapath instn_decode utypeimm", false,-1, 31,0);
        tracep->declBus(c+67,"top riscv_32i datapath instn_decode stypeimm", false,-1, 31,0);
        tracep->declBus(c+4,"top riscv_32i datapath instn_decode itypeimm", false,-1, 31,0);
        tracep->declBus(c+60,"top riscv_32i datapath instn_decode rs1", false,-1, 4,0);
        tracep->declBus(c+61,"top riscv_32i datapath instn_decode rs2", false,-1, 4,0);
        tracep->declBus(c+62,"top riscv_32i datapath instn_decode rd", false,-1, 4,0);
        tracep->declBit(c+52,"top riscv_32i datapath rf clk", false,-1);
        tracep->declBit(c+53,"top riscv_32i datapath rf reset", false,-1);
        tracep->declBit(c+9,"top riscv_32i datapath rf we3", false,-1);
        tracep->declBus(c+60,"top riscv_32i datapath rf rs1", false,-1, 4,0);
        tracep->declBus(c+61,"top riscv_32i datapath rf rs2", false,-1, 4,0);
        tracep->declBus(c+62,"top riscv_32i datapath rf rd", false,-1, 4,0);
        tracep->declBus(c+7,"top riscv_32i datapath rf wd3", false,-1, 31,0);
        tracep->declBus(c+5,"top riscv_32i datapath rf rs1_data", false,-1, 31,0);
        tracep->declBus(c+8,"top riscv_32i datapath rf rs2_data", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+10+i*1,"top riscv_32i datapath rf rf", true,(i+0), 31,0);}}
        tracep->declBus(c+5,"top riscv_32i datapath alu srca", false,-1, 31,0);
        tracep->declBus(c+6,"top riscv_32i datapath alu srcb", false,-1, 31,0);
        tracep->declBus(c+71,"top riscv_32i datapath alu alucontrol", false,-1, 2,0);
        tracep->declBit(c+72,"top riscv_32i datapath alu alu_sub", false,-1);
        tracep->declBus(c+55,"top riscv_32i datapath alu aluout", false,-1, 31,0);
        tracep->declBus(c+57,"top imem a", false,-1, 31,0);
        tracep->declBus(c+58,"top imem rd", false,-1, 31,0);
        tracep->declBit(c+76,"top imem Iwait", false,-1);
        tracep->declBit(c+52,"top dmem clk", false,-1);
        tracep->declBit(c+59,"top dmem we", false,-1);
        tracep->declBus(c+55,"top dmem a", false,-1, 31,0);
        tracep->declBus(c+54,"top dmem wd", false,-1, 31,0);
        tracep->declBit(c+1,"top dmem Dmemaccess", false,-1);
        tracep->declBus(c+56,"top dmem rd", false,-1, 31,0);
        tracep->declBit(c+76,"top dmem Dwait", false,-1);
        vlTOPp->traceInitSub1(userp, tracep, "top Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top L1_cache Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top imem Bus");
        vlTOPp->traceInitSub1(userp, tracep, "top dmem Bus");
        vlTOPp->traceInitSub2(userp, tracep, "top riscv_32i c_bus");
        vlTOPp->traceInitSub2(userp, tracep, "top riscv_32i controller c_bus");
        vlTOPp->traceInitSub2(userp, tracep, "top riscv_32i controller maindec c_bus");
        vlTOPp->traceInitSub2(userp, tracep, "top riscv_32i controller aludec c_bus");
        vlTOPp->traceInitSub2(userp, tracep, "top riscv_32i datapath c_bus");
    }
}

void Vtop::traceInitSub1(void* userp, VerilatedVcd* tracep, const char* scopep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+52,Verilated::catName(scopep,"clk"," "), false,-1);
        tracep->declBus(c+57,Verilated::catName(scopep,"Iaddr"," "), false,-1, 31,0);
        tracep->declBus(c+73,Verilated::catName(scopep,"Iinstn"," "), false,-1, 31,0);
        tracep->declBus(c+55,Verilated::catName(scopep,"Daddr"," "), false,-1, 31,0);
        tracep->declBus(c+74,Verilated::catName(scopep,"Dreaddata"," "), false,-1, 31,0);
        tracep->declBus(c+54,Verilated::catName(scopep,"Dwritedata"," "), false,-1, 31,0);
        tracep->declBit(c+59,Verilated::catName(scopep,"Dwe"," "), false,-1);
        tracep->declBit(c+76,Verilated::catName(scopep,"Dwait"," "), false,-1);
        tracep->declBit(c+76,Verilated::catName(scopep,"Iwait"," "), false,-1);
        tracep->declBit(c+1,Verilated::catName(scopep,"Dmemaccess"," "), false,-1);
    }
}

void Vtop::traceInitSub2(void* userp, VerilatedVcd* tracep, const char* scopep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+58,Verilated::catName(scopep,"instr"," "), false,-1, 31,0);
        tracep->declBus(c+75,Verilated::catName(scopep,"op"," "), false,-1, 6,0);
        tracep->declBus(c+69,Verilated::catName(scopep,"funct3"," "), false,-1, 2,0);
        tracep->declBus(c+70,Verilated::catName(scopep,"funct7"," "), false,-1, 6,0);
        tracep->declBit(c+42,Verilated::catName(scopep,"br_taken"," "), false,-1);
        tracep->declBit(c+43,Verilated::catName(scopep,"branch"," "), false,-1);
        tracep->declBit(c+44,Verilated::catName(scopep,"jump"," "), false,-1);
        tracep->declBit(c+45,Verilated::catName(scopep,"jalr"," "), false,-1);
        tracep->declBit(c+46,Verilated::catName(scopep,"memtoreg"," "), false,-1);
        tracep->declBit(c+47,Verilated::catName(scopep,"memwrite"," "), false,-1);
        tracep->declBit(c+48,Verilated::catName(scopep,"pcsrc"," "), false,-1);
        tracep->declBit(c+49,Verilated::catName(scopep,"alusrc"," "), false,-1);
        tracep->declBit(c+9,Verilated::catName(scopep,"regwrite"," "), false,-1);
        tracep->declBus(c+71,Verilated::catName(scopep,"alucontrol"," "), false,-1, 2,0);
        tracep->declBit(c+72,Verilated::catName(scopep,"alu_sub"," "), false,-1);
        tracep->declBit(c+50,Verilated::catName(scopep,"auipc"," "), false,-1);
        tracep->declBit(c+51,Verilated::catName(scopep,"lui"," "), false,-1);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 4U) | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                                  >> 5U)))));
        tracep->fullCData(oldp+2,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
        tracep->fullSData(oldp+3,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
        tracep->fullIData(oldp+4,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
        tracep->fullIData(oldp+5,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
        tracep->fullIData(oldp+6,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
        tracep->fullIData(oldp+7,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__result),32);
        tracep->fullIData(oldp+8,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
        tracep->fullBit(oldp+9,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                       >> 8U))));
        tracep->fullIData(oldp+10,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
        tracep->fullIData(oldp+11,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
        tracep->fullIData(oldp+12,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
        tracep->fullIData(oldp+13,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
        tracep->fullIData(oldp+14,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
        tracep->fullIData(oldp+15,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
        tracep->fullIData(oldp+16,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
        tracep->fullIData(oldp+17,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
        tracep->fullIData(oldp+18,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
        tracep->fullIData(oldp+19,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
        tracep->fullIData(oldp+20,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
        tracep->fullIData(oldp+21,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
        tracep->fullIData(oldp+22,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
        tracep->fullIData(oldp+23,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
        tracep->fullIData(oldp+24,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
        tracep->fullIData(oldp+25,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
        tracep->fullIData(oldp+26,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
        tracep->fullIData(oldp+27,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
        tracep->fullIData(oldp+28,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
        tracep->fullIData(oldp+29,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
        tracep->fullIData(oldp+30,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
        tracep->fullIData(oldp+31,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
        tracep->fullIData(oldp+32,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
        tracep->fullIData(oldp+33,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
        tracep->fullIData(oldp+34,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
        tracep->fullIData(oldp+35,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
        tracep->fullIData(oldp+36,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
        tracep->fullIData(oldp+37,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
        tracep->fullIData(oldp+38,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
        tracep->fullIData(oldp+39,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
        tracep->fullIData(oldp+40,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
        tracep->fullIData(oldp+41,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
        tracep->fullBit(oldp+42,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
        tracep->fullBit(oldp+43,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 6U))));
        tracep->fullBit(oldp+44,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 3U))));
        tracep->fullBit(oldp+45,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 2U))));
        tracep->fullBit(oldp+46,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 4U))));
        tracep->fullBit(oldp+47,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 5U))));
        tracep->fullBit(oldp+48,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                   >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
        tracep->fullBit(oldp+49,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 7U))));
        tracep->fullBit(oldp+50,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                        >> 1U))));
        tracep->fullBit(oldp+51,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
        tracep->fullBit(oldp+52,(vlTOPp->clk));
        tracep->fullBit(oldp+53,(vlTOPp->reset));
        tracep->fullIData(oldp+54,(vlTOPp->writedata),32);
        tracep->fullIData(oldp+55,(vlTOPp->dataadr),32);
        tracep->fullIData(oldp+56,(vlTOPp->readdata),32);
        tracep->fullIData(oldp+57,(vlTOPp->pc),32);
        tracep->fullIData(oldp+58,(vlTOPp->instr),32);
        tracep->fullBit(oldp+59,(vlTOPp->memwrite));
        tracep->fullCData(oldp+60,((0x1fU & (vlTOPp->instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+61,((0x1fU & (vlTOPp->instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+62,((0x1fU & (vlTOPp->instr 
                                             >> 7U))),5);
        tracep->fullIData(oldp+63,(((IData)(4U) + vlTOPp->pc)),32);
        tracep->fullIData(oldp+64,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                                     ? ((0xfffff000U 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->instr 
                                                           >> 0x1fU)))) 
                                            << 0xcU)) 
                                        | ((0xfe0U 
                                            & (vlTOPp->instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlTOPp->instr 
                                                 >> 7U))))
                                     : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)),32);
        tracep->fullIData(oldp+65,(((0xffffe000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->instr 
                                                     >> 0x1fU)))) 
                                      << 0xdU)) | (
                                                   (0x1000U 
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
                                                               >> 7U))))))),32);
        tracep->fullIData(oldp+66,(((0xffe00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->instr 
                                                     >> 0x1fU)))) 
                                      << 0x15U)) | 
                                    ((0x100000U & (vlTOPp->instr 
                                                   >> 0xbU)) 
                                     | ((0xff000U & vlTOPp->instr) 
                                        | ((0x800U 
                                            & (vlTOPp->instr 
                                               >> 9U)) 
                                           | (0x7feU 
                                              & (vlTOPp->instr 
                                                 >> 0x14U))))))),32);
        tracep->fullIData(oldp+67,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->instr 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->instr 
                                                         >> 7U))))),32);
        tracep->fullIData(oldp+68,((0xfffff000U & vlTOPp->instr)),32);
        tracep->fullCData(oldp+69,((7U & (vlTOPp->instr 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+70,((0x7fU & (vlTOPp->instr 
                                             >> 0x19U))),7);
        tracep->fullCData(oldp+71,(((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                     ? (7U & ((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                               ? (vlTOPp->instr 
                                                  >> 0xcU)
                                               : (vlTOPp->instr 
                                                  >> 0xcU)))
                                     : 0U)),3);
        tracep->fullBit(oldp+72,((1U & ((2U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
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
        tracep->fullIData(oldp+73,(vlTOPp->top__DOT__L1_cache__DOT__MEM
                                   [(0x1ffffU & (vlTOPp->pc 
                                                 >> 2U))]),32);
        tracep->fullIData(oldp+74,(((1U & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                            >> 4U) 
                                           | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                              >> 5U)))
                                     ? vlTOPp->top__DOT__L1_cache__DOT__MEM
                                    [(0x1ffffU & (vlTOPp->dataadr 
                                                  >> 2U))]
                                     : 0U)),32);
        tracep->fullCData(oldp+75,((0x7fU & vlTOPp->instr)),7);
        tracep->fullBit(oldp+76,(0U));
    }
}
