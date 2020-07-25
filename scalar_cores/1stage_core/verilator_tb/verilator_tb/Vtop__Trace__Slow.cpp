// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vtop::traceInit, &Vtop::traceFull, &Vtop::traceChg, this);
}
void Vtop::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vtop::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vtop::traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vtop::traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+68,"clk",-1);
	vcdp->declBit  (c+69,"reset",-1);
	vcdp->declBus  (c+70,"writedata",-1,31,0);
	vcdp->declBus  (c+71,"dataadr",-1,31,0);
	vcdp->declBit  (c+72,"memwrite",-1);
	vcdp->declArray(c+73,"dbg",-1,185,0);
	vcdp->declBit  (c+68,"top clk",-1);
	vcdp->declBit  (c+69,"top reset",-1);
	vcdp->declBus  (c+70,"top writedata",-1,31,0);
	vcdp->declBus  (c+71,"top dataadr",-1,31,0);
	vcdp->declBit  (c+72,"top memwrite",-1);
	vcdp->declArray(c+73,"top dbg",-1,185,0);
	vcdp->declBus  (c+66,"top pc",-1,31,0);
	vcdp->declBus  (c+1,"top instr",-1,31,0);
	vcdp->declBus  (c+2,"top readdata",-1,31,0);
	// Tracing: top Bus__Viftop // Ignored: Verilator trace_off at ../top_test.sv:28
	vcdp->declBit  (c+68,"top riscv_32i clk",-1);
	vcdp->declBit  (c+69,"top riscv_32i reset",-1);
	vcdp->declBus  (c+66,"top riscv_32i pc",-1,31,0);
	vcdp->declBus  (c+1,"top riscv_32i instr",-1,31,0);
	vcdp->declBit  (c+72,"top riscv_32i memwrite",-1);
	vcdp->declBus  (c+71,"top riscv_32i aluout",-1,31,0);
	vcdp->declBus  (c+70,"top riscv_32i writedata",-1,31,0);
	vcdp->declBus  (c+2,"top riscv_32i readdata",-1,31,0);
	vcdp->declArray(c+73,"top riscv_32i dbg",-1,185,0);
	vcdp->declBus  (c+3,"top riscv_32i result",-1,31,0);
	// Tracing: top riscv_32i c_bus__Viftop // Ignored: Verilator trace_off at ../core_top.sv:43
	// Tracing: top riscv_32i controller_if__Vmp__ctrl__Viftop1 // Ignored: Verilator trace_off at ../core_top.sv:44
	// Tracing: top riscv_32i controller_if__Vmp__dp__Viftop2 // Ignored: Verilator trace_off at ../core_top.sv:46
	// Tracing: top riscv_32i controller c_bus // Ignored: Unsupported: data type at ../controller.sv:5
	vcdp->declBus  (c+4,"top riscv_32i controller aluop",-1,1,0);
	// Tracing: top riscv_32i controller maindec c_bus // Ignored: Unsupported: data type at ../controller.sv:19
	vcdp->declBus  (c+4,"top riscv_32i controller maindec aluop",-1,1,0);
	vcdp->declBus  (c+5,"top riscv_32i controller maindec controls",-1,8,0);
	// Tracing: top riscv_32i controller aludec c_bus // Ignored: Unsupported: data type at ../controller.sv:44
	vcdp->declBus  (c+4,"top riscv_32i controller aludec aluop",-1,1,0);
	vcdp->declBit  (c+68,"top riscv_32i datapath clk",-1);
	vcdp->declBit  (c+69,"top riscv_32i datapath reset",-1);
	// Tracing: top riscv_32i datapath c_bus // Ignored: Unsupported: data type at ../datapath.sv:7
	vcdp->declBus  (c+66,"top riscv_32i datapath pc",-1,31,0);
	vcdp->declBus  (c+71,"top riscv_32i datapath aluout",-1,31,0);
	vcdp->declBus  (c+70,"top riscv_32i datapath writedata",-1,31,0);
	vcdp->declBus  (c+2,"top riscv_32i datapath readdata",-1,31,0);
	vcdp->declBus  (c+3,"top riscv_32i datapath result",-1,31,0);
	vcdp->declBus  (c+6,"top riscv_32i datapath rs1",-1,4,0);
	vcdp->declBus  (c+7,"top riscv_32i datapath rs2",-1,4,0);
	vcdp->declBus  (c+8,"top riscv_32i datapath rd",-1,4,0);
	vcdp->declBus  (c+67,"top riscv_32i datapath pcplus4",-1,31,0);
	vcdp->declBus  (c+9,"top riscv_32i datapath signimm",-1,31,0);
	vcdp->declBus  (c+10,"top riscv_32i datapath branchimm",-1,31,0);
	vcdp->declBus  (c+11,"top riscv_32i datapath jumpimm",-1,31,0);
	vcdp->declBus  (c+12,"top riscv_32i datapath stypeimm",-1,31,0);
	vcdp->declBus  (c+13,"top riscv_32i datapath itypeimm",-1,31,0);
	vcdp->declBus  (c+14,"top riscv_32i datapath utypeimm",-1,31,0);
	vcdp->declBus  (c+15,"top riscv_32i datapath srca",-1,31,0);
	vcdp->declBus  (c+16,"top riscv_32i datapath srcb",-1,31,0);
	vcdp->declBus  (c+17,"top riscv_32i datapath srcb_net0",-1,31,0);
	vcdp->declBus  (c+18,"top riscv_32i datapath funct3",-1,2,0);
	vcdp->declBus  (c+19,"top riscv_32i datapath funct7",-1,6,0);
	vcdp->declBus  (c+1,"top riscv_32i datapath instn_decode instr",-1,31,0);
	vcdp->declBus  (c+18,"top riscv_32i datapath instn_decode funct3",-1,2,0);
	vcdp->declBus  (c+19,"top riscv_32i datapath instn_decode funct7",-1,6,0);
	vcdp->declBus  (c+11,"top riscv_32i datapath instn_decode jumpimm",-1,31,0);
	vcdp->declBus  (c+10,"top riscv_32i datapath instn_decode branchimm",-1,31,0);
	vcdp->declBus  (c+14,"top riscv_32i datapath instn_decode utypeimm",-1,31,0);
	vcdp->declBus  (c+12,"top riscv_32i datapath instn_decode stypeimm",-1,31,0);
	vcdp->declBus  (c+13,"top riscv_32i datapath instn_decode itypeimm",-1,31,0);
	vcdp->declBus  (c+6,"top riscv_32i datapath instn_decode rs1",-1,4,0);
	vcdp->declBus  (c+7,"top riscv_32i datapath instn_decode rs2",-1,4,0);
	vcdp->declBus  (c+8,"top riscv_32i datapath instn_decode rd",-1,4,0);
	vcdp->declBit  (c+68,"top riscv_32i datapath rf clk",-1);
	vcdp->declBit  (c+20,"top riscv_32i datapath rf we3",-1);
	vcdp->declBus  (c+6,"top riscv_32i datapath rf rs1",-1,4,0);
	vcdp->declBus  (c+7,"top riscv_32i datapath rf rs2",-1,4,0);
	vcdp->declBus  (c+8,"top riscv_32i datapath rf rd",-1,4,0);
	vcdp->declBus  (c+3,"top riscv_32i datapath rf wd3",-1,31,0);
	vcdp->declBus  (c+15,"top riscv_32i datapath rf rs1_data",-1,31,0);
	vcdp->declBus  (c+17,"top riscv_32i datapath rf rs2_data",-1,31,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+34+i*1,"top riscv_32i datapath rf rf",(i+0),31,0);}}
	vcdp->declBus  (c+15,"top riscv_32i datapath alu srca",-1,31,0);
	vcdp->declBus  (c+16,"top riscv_32i datapath alu srcb",-1,31,0);
	vcdp->declBus  (c+21,"top riscv_32i datapath alu alucontrol",-1,2,0);
	vcdp->declBit  (c+22,"top riscv_32i datapath alu alu_sub",-1);
	vcdp->declBus  (c+71,"top riscv_32i datapath alu aluout",-1,31,0);
	vcdp->declBus  (c+66,"top imem a",-1,31,0);
	vcdp->declBus  (c+1,"top imem rd",-1,31,0);
	// Tracing: top imem Bus // Ignored: Unsupported: data type at ../top_test.sv:49
	vcdp->declBit  (c+68,"top dmem clk",-1);
	vcdp->declBit  (c+72,"top dmem we",-1);
	vcdp->declBus  (c+71,"top dmem a",-1,31,0);
	vcdp->declBus  (c+70,"top dmem wd",-1,31,0);
	vcdp->declBus  (c+2,"top dmem rd",-1,31,0);
	// Tracing: top dmem Bus // Ignored: Unsupported: data type at ../top_test.sv:36
	vcdp->declBit  (c+68,"top Bus clk",-1);
	vcdp->declBus  (c+66,"top Bus Iaddr",-1,31,0);
	vcdp->declBus  (c+1,"top Bus Iinstn",-1,31,0);
	vcdp->declBus  (c+71,"top Bus Daddr",-1,31,0);
	vcdp->declBus  (c+2,"top Bus Dreaddata",-1,31,0);
	vcdp->declBus  (c+70,"top Bus Dwritedata",-1,31,0);
	vcdp->declBit  (c+72,"top Bus Dwe",-1);
	// Tracing: top Bus MEM // Ignored: Wide memory > --trace-max-array ents at ../top_test.sv:75
	vcdp->declBus  (c+1,"top riscv_32i c_bus instr",-1,31,0);
	vcdp->declBus  (c+23,"top riscv_32i c_bus op",-1,6,0);
	vcdp->declBus  (c+18,"top riscv_32i c_bus funct3",-1,2,0);
	vcdp->declBus  (c+19,"top riscv_32i c_bus funct7",-1,6,0);
	vcdp->declBit  (c+24,"top riscv_32i c_bus br_taken",-1);
	vcdp->declBit  (c+25,"top riscv_32i c_bus branch",-1);
	vcdp->declBit  (c+26,"top riscv_32i c_bus jump",-1);
	vcdp->declBit  (c+27,"top riscv_32i c_bus jalr",-1);
	vcdp->declBit  (c+28,"top riscv_32i c_bus memtoreg",-1);
	vcdp->declBit  (c+29,"top riscv_32i c_bus memwrite",-1);
	vcdp->declBit  (c+30,"top riscv_32i c_bus pcsrc",-1);
	vcdp->declBit  (c+31,"top riscv_32i c_bus alusrc",-1);
	vcdp->declBit  (c+20,"top riscv_32i c_bus regwrite",-1);
	vcdp->declBus  (c+21,"top riscv_32i c_bus alucontrol",-1,2,0);
	vcdp->declBit  (c+22,"top riscv_32i c_bus alu_sub",-1);
	vcdp->declBit  (c+32,"top riscv_32i c_bus auipc",-1);
	vcdp->declBit  (c+33,"top riscv_32i c_bus lui",-1);
    }
}

void Vtop::traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBus  (c+1,(vlSymsp->TOP__top__DOT__Bus.Iinstn),32);
	vcdp->fullBus  (c+2,(vlSymsp->TOP__top__DOT__Bus.Dreaddata),32);
	vcdp->fullBus  (c+3,(vlTOPp->top__DOT__riscv_32i__DOT__result),32);
	vcdp->fullBus  (c+4,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
	vcdp->fullBus  (c+5,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
	vcdp->fullBus  (c+6,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       >> 0xfU))),5);
	vcdp->fullBus  (c+7,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       >> 0x14U))),5);
	vcdp->fullBus  (c+8,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       >> 7U))),5);
	vcdp->fullBus  (c+9,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
			       ? ((0xfffff000U & (VL_NEGATE_I((IData)(
								      (1U 
								       & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
									  >> 0x1fU)))) 
						  << 0xcU)) 
				  | ((0xfe0U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						>> 0x14U)) 
				     | (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						 >> 7U))))
			       : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)),32);
	vcdp->fullBus  (c+10,(((0xffffe000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
								       >> 0x1fU)))) 
					       << 0xdU)) 
			       | ((0x1000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					      >> 0x13U)) 
				  | ((0x800U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						<< 4U)) 
				     | ((0x7e0U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						   >> 0x14U)) 
					| (0x1eU & 
					   (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					    >> 7U))))))),32);
	vcdp->fullBus  (c+11,(((0xffe00000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
								       >> 0x1fU)))) 
					       << 0x15U)) 
			       | ((0x100000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						>> 0xbU)) 
				  | ((0xff000U & vlSymsp->TOP__top__DOT__Bus.Iinstn) 
				     | ((0x800U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						   >> 9U)) 
					| (0x7feU & 
					   (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					    >> 0x14U))))))),32);
	vcdp->fullBus  (c+12,(((0xfffff000U & (VL_NEGATE_I((IData)(
								   (1U 
								    & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
								       >> 0x1fU)))) 
					       << 0xcU)) 
			       | ((0xfe0U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					     >> 0x14U)) 
				  | (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					      >> 7U))))),32);
	vcdp->fullBus  (c+13,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
	vcdp->fullBus  (c+14,((0xfffff000U & vlSymsp->TOP__top__DOT__Bus.Iinstn)),32);
	vcdp->fullBus  (c+15,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
	vcdp->fullBus  (c+16,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
	vcdp->fullBus  (c+17,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
	vcdp->fullBus  (c+18,((7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				     >> 0xcU))),3);
	vcdp->fullBus  (c+19,((0x7fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					>> 0x19U))),7);
	vcdp->fullBit  (c+20,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 8U))));
	vcdp->fullBus  (c+21,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol),3);
	vcdp->fullBit  (c+22,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub));
	vcdp->fullBus  (c+23,((0x7fU & vlSymsp->TOP__top__DOT__Bus.Iinstn)),7);
	vcdp->fullBit  (c+24,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
	vcdp->fullBit  (c+25,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 6U))));
	vcdp->fullBit  (c+26,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 3U))));
	vcdp->fullBit  (c+27,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 2U))));
	vcdp->fullBit  (c+28,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 4U))));
	vcdp->fullBit  (c+29,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 5U))));
	vcdp->fullBit  (c+30,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				>> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
	vcdp->fullBit  (c+31,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 7U))));
	vcdp->fullBit  (c+32,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				     >> 1U))));
	vcdp->fullBit  (c+33,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
	vcdp->fullBus  (c+34,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
	vcdp->fullBus  (c+35,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
	vcdp->fullBus  (c+36,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
	vcdp->fullBus  (c+37,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
	vcdp->fullBus  (c+38,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
	vcdp->fullBus  (c+39,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
	vcdp->fullBus  (c+40,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
	vcdp->fullBus  (c+41,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
	vcdp->fullBus  (c+42,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
	vcdp->fullBus  (c+43,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
	vcdp->fullBus  (c+44,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
	vcdp->fullBus  (c+45,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
	vcdp->fullBus  (c+46,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
	vcdp->fullBus  (c+47,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
	vcdp->fullBus  (c+48,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
	vcdp->fullBus  (c+49,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
	vcdp->fullBus  (c+50,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
	vcdp->fullBus  (c+51,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
	vcdp->fullBus  (c+52,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
	vcdp->fullBus  (c+53,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
	vcdp->fullBus  (c+54,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
	vcdp->fullBus  (c+55,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
	vcdp->fullBus  (c+56,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
	vcdp->fullBus  (c+57,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
	vcdp->fullBus  (c+58,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
	vcdp->fullBus  (c+59,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
	vcdp->fullBus  (c+60,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
	vcdp->fullBus  (c+61,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
	vcdp->fullBus  (c+62,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
	vcdp->fullBus  (c+63,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
	vcdp->fullBus  (c+64,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
	vcdp->fullBus  (c+65,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
	vcdp->fullBus  (c+66,(vlTOPp->top__DOT__pc),32);
	vcdp->fullBus  (c+67,(((IData)(4U) + vlTOPp->top__DOT__pc)),32);
	vcdp->fullBit  (c+68,(vlTOPp->clk));
	vcdp->fullBit  (c+69,(vlTOPp->reset));
	vcdp->fullBus  (c+70,(vlTOPp->writedata),32);
	vcdp->fullBus  (c+71,(vlTOPp->dataadr),32);
	vcdp->fullBit  (c+72,(vlTOPp->memwrite));
	vcdp->fullArray(c+73,(vlTOPp->dbg),186);
    }
}
