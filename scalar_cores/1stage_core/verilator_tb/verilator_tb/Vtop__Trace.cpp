// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vtop* t=(Vtop*)userthis;
    Vtop__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vtop::traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vtop::traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1,(vlSymsp->TOP__top__DOT__Bus.Iinstn),32);
	vcdp->chgBus  (c+2,(vlSymsp->TOP__top__DOT__Bus.Dreaddata),32);
	vcdp->chgBus  (c+3,(vlTOPp->top__DOT__riscv_32i__DOT__result),32);
	vcdp->chgBus  (c+4,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop),2);
	vcdp->chgBus  (c+5,(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls),9);
	vcdp->chgBus  (c+6,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				      >> 0xfU))),5);
	vcdp->chgBus  (c+7,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				      >> 0x14U))),5);
	vcdp->chgBus  (c+8,((0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				      >> 7U))),5);
	vcdp->chgBus  (c+9,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
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
	vcdp->chgBus  (c+10,(((0xffffe000U & (VL_NEGATE_I((IData)(
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
				       | (0x1eU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						   >> 7U))))))),32);
	vcdp->chgBus  (c+11,(((0xffe00000U & (VL_NEGATE_I((IData)(
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
	vcdp->chgBus  (c+12,(((0xfffff000U & (VL_NEGATE_I((IData)(
								  (1U 
								   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
								      >> 0x1fU)))) 
					      << 0xcU)) 
			      | ((0xfe0U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					    >> 0x14U)) 
				 | (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
					     >> 7U))))),32);
	vcdp->chgBus  (c+13,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm),32);
	vcdp->chgBus  (c+14,((0xfffff000U & vlSymsp->TOP__top__DOT__Bus.Iinstn)),32);
	vcdp->chgBus  (c+15,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca),32);
	vcdp->chgBus  (c+16,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb),32);
	vcdp->chgBus  (c+17,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0),32);
	vcdp->chgBus  (c+18,((7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				    >> 0xcU))),3);
	vcdp->chgBus  (c+19,((0x7fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       >> 0x19U))),7);
	vcdp->chgBit  (c+20,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 8U))));
	vcdp->chgBus  (c+21,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol),3);
	vcdp->chgBit  (c+22,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub));
	vcdp->chgBus  (c+23,((0x7fU & vlSymsp->TOP__top__DOT__Bus.Iinstn)),7);
	vcdp->chgBit  (c+24,(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken));
	vcdp->chgBit  (c+25,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 6U))));
	vcdp->chgBit  (c+26,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 3U))));
	vcdp->chgBit  (c+27,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 2U))));
	vcdp->chgBit  (c+28,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 4U))));
	vcdp->chgBit  (c+29,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 5U))));
	vcdp->chgBit  (c+30,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
			       >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))));
	vcdp->chgBit  (c+31,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 7U))));
	vcdp->chgBit  (c+32,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				    >> 1U))));
	vcdp->chgBit  (c+33,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+34,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[0]),32);
	vcdp->chgBus  (c+35,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[1]),32);
	vcdp->chgBus  (c+36,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[2]),32);
	vcdp->chgBus  (c+37,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[3]),32);
	vcdp->chgBus  (c+38,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[4]),32);
	vcdp->chgBus  (c+39,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[5]),32);
	vcdp->chgBus  (c+40,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[6]),32);
	vcdp->chgBus  (c+41,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[7]),32);
	vcdp->chgBus  (c+42,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[8]),32);
	vcdp->chgBus  (c+43,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[9]),32);
	vcdp->chgBus  (c+44,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[10]),32);
	vcdp->chgBus  (c+45,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[11]),32);
	vcdp->chgBus  (c+46,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[12]),32);
	vcdp->chgBus  (c+47,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[13]),32);
	vcdp->chgBus  (c+48,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[14]),32);
	vcdp->chgBus  (c+49,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[15]),32);
	vcdp->chgBus  (c+50,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[16]),32);
	vcdp->chgBus  (c+51,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[17]),32);
	vcdp->chgBus  (c+52,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[18]),32);
	vcdp->chgBus  (c+53,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[19]),32);
	vcdp->chgBus  (c+54,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[20]),32);
	vcdp->chgBus  (c+55,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[21]),32);
	vcdp->chgBus  (c+56,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[22]),32);
	vcdp->chgBus  (c+57,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[23]),32);
	vcdp->chgBus  (c+58,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[24]),32);
	vcdp->chgBus  (c+59,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[25]),32);
	vcdp->chgBus  (c+60,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[26]),32);
	vcdp->chgBus  (c+61,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[27]),32);
	vcdp->chgBus  (c+62,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[28]),32);
	vcdp->chgBus  (c+63,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[29]),32);
	vcdp->chgBus  (c+64,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[30]),32);
	vcdp->chgBus  (c+65,(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[31]),32);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+66,(vlTOPp->top__DOT__pc),32);
	vcdp->chgBus  (c+67,(((IData)(4U) + vlTOPp->top__DOT__pc)),32);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+68,(vlTOPp->clk));
	vcdp->chgBit  (c+69,(vlTOPp->reset));
	vcdp->chgBus  (c+70,(vlTOPp->writedata),32);
	vcdp->chgBus  (c+71,(vlTOPp->dataadr),32);
	vcdp->chgBit  (c+72,(vlTOPp->memwrite));
	vcdp->chgArray(c+73,(vlTOPp->dbg),186);
    }
}
