// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"reset", false,-1);
    tracep->declBus(c+55,"writedata", false,-1, 31,0);
    tracep->declBus(c+56,"dataadr", false,-1, 31,0);
    tracep->declBus(c+57,"readdata", false,-1, 31,0);
    tracep->declBus(c+58,"pc", false,-1, 31,0);
    tracep->declBus(c+59,"instr", false,-1, 31,0);
    tracep->declBit(c+60,"memwrite", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"reset", false,-1);
    tracep->declBus(c+55,"writedata", false,-1, 31,0);
    tracep->declBus(c+56,"dataadr", false,-1, 31,0);
    tracep->declBus(c+57,"readdata", false,-1, 31,0);
    tracep->declBus(c+58,"pc", false,-1, 31,0);
    tracep->declBus(c+59,"instr", false,-1, 31,0);
    tracep->declBit(c+60,"memwrite", false,-1);
    tracep->declBit(c+77,"Iwait", false,-1);
    tracep->declBit(c+77,"Dwait", false,-1);
    tracep->declBit(c+33,"dmem_req", false,-1);
    tracep->declBit(c+78,"imem_req", false,-1);
    tracep->declBus(c+34,"dmem_mask", false,-1, 3,0);
    tracep->pushNamePrefix("L1_cache ");
    tracep->declBus(c+79,"RAM_SIZE", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("dmem ");
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+60,"dmem_we", false,-1);
    tracep->declBus(c+56,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+55,"dmem_wd", false,-1, 31,0);
    tracep->declBus(c+34,"dmem_mask", false,-1, 3,0);
    tracep->declBit(c+33,"dmem_req", false,-1);
    tracep->declBus(c+57,"dmem_rd", false,-1, 31,0);
    tracep->declBit(c+77,"dmem_wait", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("imem ");
    tracep->declBus(c+58,"imem_addr", false,-1, 31,0);
    tracep->declBit(c+78,"imem_req", false,-1);
    tracep->declBus(c+59,"imem_instn", false,-1, 31,0);
    tracep->declBit(c+77,"imem_wait", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("riscv_32i ");
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"reset", false,-1);
    tracep->declBus(c+58,"imem_pc_addr", false,-1, 31,0);
    tracep->declBit(c+78,"imem_req", false,-1);
    tracep->declBus(c+59,"imem_instn", false,-1, 31,0);
    tracep->declBit(c+77,"imem_wait", false,-1);
    tracep->declBit(c+60,"dmem_we", false,-1);
    tracep->declBus(c+56,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+55,"dmem_wd", false,-1, 31,0);
    tracep->declBus(c+34,"dmem_mask", false,-1, 3,0);
    tracep->declBit(c+33,"dmem_req", false,-1);
    tracep->declBus(c+57,"dmem_rd", false,-1, 31,0);
    tracep->declBit(c+77,"dmem_wait", false,-1);
    tracep->pushNamePrefix("controller ");
    tracep->declBus(c+35,"aluop", false,-1, 1,0);
    tracep->pushNamePrefix("aludec ");
    tracep->declBus(c+35,"aluop", false,-1, 1,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maindec ");
    tracep->declBus(c+35,"aluop", false,-1, 1,0);
    tracep->declBus(c+36,"controls", false,-1, 8,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("datapath ");
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"reset", false,-1);
    tracep->declBus(c+58,"pc", false,-1, 31,0);
    tracep->declBus(c+56,"aluout", false,-1, 31,0);
    tracep->declBus(c+55,"writedata", false,-1, 31,0);
    tracep->declBus(c+57,"readdata", false,-1, 31,0);
    tracep->declBus(c+34,"dmem_mask", false,-1, 3,0);
    tracep->declBit(c+33,"memaccess", false,-1);
    tracep->declBit(c+77,"Iwait", false,-1);
    tracep->declBit(c+77,"Dwait", false,-1);
    tracep->declBus(c+61,"rs1", false,-1, 4,0);
    tracep->declBus(c+62,"rs2", false,-1, 4,0);
    tracep->declBus(c+63,"rd", false,-1, 4,0);
    tracep->declBus(c+64,"pcplus4", false,-1, 31,0);
    tracep->declBus(c+65,"signimm", false,-1, 31,0);
    tracep->declBus(c+66,"branchimm", false,-1, 31,0);
    tracep->declBus(c+67,"jumpimm", false,-1, 31,0);
    tracep->declBus(c+68,"stypeimm", false,-1, 31,0);
    tracep->declBus(c+37,"itypeimm", false,-1, 31,0);
    tracep->declBus(c+69,"utypeimm", false,-1, 31,0);
    tracep->declBus(c+38,"srca", false,-1, 31,0);
    tracep->declBus(c+39,"srcb", false,-1, 31,0);
    tracep->declBus(c+40,"result", false,-1, 31,0);
    tracep->declBus(c+41,"srcb_net0", false,-1, 31,0);
    tracep->declBus(c+70,"funct3", false,-1, 2,0);
    tracep->declBus(c+71,"funct7", false,-1, 6,0);
    tracep->declBit(c+77,"en_pc_reg", false,-1);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+38,"srca", false,-1, 31,0);
    tracep->declBus(c+39,"srcb", false,-1, 31,0);
    tracep->declBus(c+72,"alucontrol", false,-1, 2,0);
    tracep->declBit(c+73,"alu_sub", false,-1);
    tracep->declBus(c+56,"aluout", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("instn_decode ");
    tracep->declBus(c+59,"instr", false,-1, 31,0);
    tracep->declBus(c+70,"funct3", false,-1, 2,0);
    tracep->declBus(c+71,"funct7", false,-1, 6,0);
    tracep->declBus(c+67,"jumpimm", false,-1, 31,0);
    tracep->declBus(c+66,"branchimm", false,-1, 31,0);
    tracep->declBus(c+69,"utypeimm", false,-1, 31,0);
    tracep->declBus(c+68,"stypeimm", false,-1, 31,0);
    tracep->declBus(c+37,"itypeimm", false,-1, 31,0);
    tracep->declBus(c+61,"rs1", false,-1, 4,0);
    tracep->declBus(c+62,"rs2", false,-1, 4,0);
    tracep->declBus(c+63,"rd", false,-1, 4,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("rf ");
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBit(c+54,"reset", false,-1);
    tracep->declBit(c+77,"en_pc_reg", false,-1);
    tracep->declBit(c+42,"we3", false,-1);
    tracep->declBus(c+61,"rs1", false,-1, 4,0);
    tracep->declBus(c+62,"rs2", false,-1, 4,0);
    tracep->declBus(c+63,"rd", false,-1, 4,0);
    tracep->declBus(c+40,"wd3", false,-1, 31,0);
    tracep->declBus(c+38,"rs1_data", false,-1, 31,0);
    tracep->declBus(c+41,"rs2_data", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,"rf", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(4);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+53,"clk", false,-1);
    tracep->declBus(c+58,"imem_addr", false,-1, 31,0);
    tracep->declBus(c+74,"imem_instn", false,-1, 31,0);
    tracep->declBit(c+77,"imem_wait", false,-1);
    tracep->declBit(c+78,"imem_req", false,-1);
    tracep->declBus(c+56,"dmem_addr", false,-1, 31,0);
    tracep->declBus(c+75,"dmem_rd", false,-1, 31,0);
    tracep->declBus(c+55,"dmem_wd", false,-1, 31,0);
    tracep->declBit(c+60,"dmem_we", false,-1);
    tracep->declBit(c+77,"dmem_wait", false,-1);
    tracep->declBit(c+33,"dmem_req", false,-1);
    tracep->declBus(c+34,"dmem_mask", false,-1, 3,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+59,"instr", false,-1, 31,0);
    tracep->declBus(c+76,"op", false,-1, 6,0);
    tracep->declBus(c+70,"funct3", false,-1, 2,0);
    tracep->declBus(c+71,"funct7", false,-1, 6,0);
    tracep->declBit(c+43,"br_taken", false,-1);
    tracep->declBit(c+44,"branch", false,-1);
    tracep->declBit(c+45,"jump", false,-1);
    tracep->declBit(c+46,"jalr", false,-1);
    tracep->declBit(c+47,"memtoreg", false,-1);
    tracep->declBit(c+48,"memwrite", false,-1);
    tracep->declBit(c+49,"pcsrc", false,-1);
    tracep->declBit(c+50,"alusrc", false,-1);
    tracep->declBit(c+42,"regwrite", false,-1);
    tracep->declBus(c+72,"alucontrol", false,-1, 2,0);
    tracep->declBit(c+73,"alu_sub", false,-1);
    tracep->declBit(c+51,"auipc", false,-1);
    tracep->declBit(c+52,"lui", false,-1);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("top ");
    tracep->pushNamePrefix("Bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("L1_cache ");
    tracep->pushNamePrefix("Bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("dmem ");
    tracep->pushNamePrefix("Bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("imem ");
    tracep->pushNamePrefix("Bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__Bus__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("riscv_32i ");
    tracep->pushNamePrefix("c_bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("controller ");
    tracep->pushNamePrefix("aludec ");
    tracep->pushNamePrefix("c_bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(vlSelf, tracep);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("c_bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("maindec ");
    tracep->pushNamePrefix("c_bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(vlSelf, tracep);
    tracep->popNamePrefix(3);
    tracep->pushNamePrefix("datapath ");
    tracep->pushNamePrefix("c_bus\211 ");
    Vtop___024root__trace_init_sub__TOP__top__DOT__riscv_32i__DOT__c_bus__0(vlSelf, tracep);
    tracep->popNamePrefix(4);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf, nullptr);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf, nullptr);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
    bufp->fullIData(oldp+2,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
    bufp->fullIData(oldp+3,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
    bufp->fullIData(oldp+4,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
    bufp->fullIData(oldp+5,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
    bufp->fullIData(oldp+6,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
    bufp->fullIData(oldp+7,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
    bufp->fullIData(oldp+8,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
    bufp->fullIData(oldp+9,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
    bufp->fullIData(oldp+10,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
    bufp->fullIData(oldp+11,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
    bufp->fullIData(oldp+13,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
    bufp->fullIData(oldp+14,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
    bufp->fullIData(oldp+15,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
    bufp->fullIData(oldp+16,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
    bufp->fullIData(oldp+17,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
    bufp->fullIData(oldp+18,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
    bufp->fullBit(oldp+33,((IData)((0U != (0x30U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))));
    bufp->fullCData(oldp+34,(vlSelf->top__DOT__dmem_mask),4);
    bufp->fullCData(oldp+35,(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
    bufp->fullSData(oldp+36,(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__result),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
    bufp->fullBit(oldp+42,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 8U))));
    bufp->fullBit(oldp+43,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
    bufp->fullBit(oldp+44,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 6U))));
    bufp->fullBit(oldp+45,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 3U))));
    bufp->fullBit(oldp+46,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 2U))));
    bufp->fullBit(oldp+47,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 4U))));
    bufp->fullBit(oldp+48,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 5U))));
    bufp->fullBit(oldp+49,((((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                             >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
    bufp->fullBit(oldp+50,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 7U))));
    bufp->fullBit(oldp+51,((1U & ((IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
                                  >> 1U))));
    bufp->fullBit(oldp+52,((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
    bufp->fullBit(oldp+53,(vlSelf->clk));
    bufp->fullBit(oldp+54,(vlSelf->reset));
    bufp->fullIData(oldp+55,(vlSelf->writedata),32);
    bufp->fullIData(oldp+56,(vlSelf->dataadr),32);
    bufp->fullIData(oldp+57,(vlSelf->readdata),32);
    bufp->fullIData(oldp+58,(vlSelf->pc),32);
    bufp->fullIData(oldp+59,(vlSelf->instr),32);
    bufp->fullBit(oldp+60,(vlSelf->memwrite));
    bufp->fullCData(oldp+61,((0x1fU & (vlSelf->instr 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+62,((0x1fU & (vlSelf->instr 
                                       >> 0x14U))),5);
    bufp->fullCData(oldp+63,((0x1fU & (vlSelf->instr 
                                       >> 7U))),5);
    bufp->fullIData(oldp+64,(((IData)(4U) + vlSelf->pc)),32);
    bufp->fullIData(oldp+65,(((0x20U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
                               ? (((- (IData)((vlSelf->instr 
                                               >> 0x1fU))) 
                                   << 0xcU) | ((0xfe0U 
                                                & (vlSelf->instr 
                                                   >> 0x14U)) 
                                               | (0x1fU 
                                                  & (vlSelf->instr 
                                                     >> 7U))))
                               : vlSelf->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)),32);
    bufp->fullIData(oldp+66,((((- (IData)((vlSelf->instr 
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
    bufp->fullIData(oldp+67,((((- (IData)((vlSelf->instr 
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
    bufp->fullIData(oldp+68,((((- (IData)((vlSelf->instr 
                                           >> 0x1fU))) 
                               << 0xcU) | ((0xfe0U 
                                            & (vlSelf->instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlSelf->instr 
                                                 >> 7U))))),32);
    bufp->fullIData(oldp+69,((0xfffff000U & vlSelf->instr)),32);
    bufp->fullCData(oldp+70,((7U & (vlSelf->instr >> 0xcU))),3);
    bufp->fullCData(oldp+71,((vlSelf->instr >> 0x19U)),7);
    bufp->fullCData(oldp+72,(((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                               ? (7U & ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                         ? (vlSelf->instr 
                                            >> 0xcU)
                                         : (vlSelf->instr 
                                            >> 0xcU)))
                               : 0U)),3);
    bufp->fullBit(oldp+73,((1U & ((2U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                   ? ((1U & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop))
                                       ? (IData)((0x40005000U 
                                                  == 
                                                  (0x40007000U 
                                                   & vlSelf->instr)))
                                       : (vlSelf->instr 
                                          >> 0x1eU))
                                   : (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__aluop)))));
    bufp->fullIData(oldp+74,(vlSelf->top__DOT__L1_cache__DOT__MEM
                             [(0xfffffU & (vlSelf->pc 
                                           >> 2U))]),32);
    bufp->fullIData(oldp+75,(((IData)((0U != (0x30U 
                                              & (IData)(vlSelf->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))))
                               ? vlSelf->top__DOT__L1_cache__DOT__MEM
                              [(0xfffffU & (vlSelf->dataadr 
                                            >> 2U))]
                               : 0U)),32);
    bufp->fullCData(oldp+76,((0x7fU & vlSelf->instr)),7);
    bufp->fullBit(oldp+77,(0U));
    bufp->fullBit(oldp+78,(1U));
    bufp->fullIData(oldp+79,(0x400000U),32);
}
