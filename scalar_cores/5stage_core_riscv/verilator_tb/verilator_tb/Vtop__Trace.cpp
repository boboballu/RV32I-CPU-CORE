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
				  >> 3U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 3U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 4U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				>> 2U) | (vlTOPp->__Vm_traceActivity 
					  >> 3U))))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
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
	vcdp->chgBit  (c+1,(vlTOPp->top__DOT__memaccessM));
	vcdp->chgBus  (c+2,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmD),32);
	vcdp->chgBus  (c+3,(vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD),32);
	vcdp->chgBus  (c+4,(((0x20U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
			      ? ((0xfffff000U & (VL_NEGATE_I((IData)(
								     (1U 
								      & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
									 >> 0x1fU)))) 
						 << 0xcU)) 
				 | ((0xfe0U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					       >> 0x14U)) 
				    | (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						>> 7U))))
			      : vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD)),32);
	vcdp->chgBus  (c+5,((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__jumpE) 
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
					      : ((5U 
						  == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
						  ? (IData)(
							    ((((QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE)) 
							       << 0x20U) 
							      | (QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE))) 
							     >> 
							     (0x1fU 
							      & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
						  : 0U))
					  : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
					      ? ((2U 
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
					      : ((2U 
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
	vcdp->chgBus  (c+6,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0),32);
	vcdp->chgBus  (c+7,(vlTOPp->top__DOT__riscv_32i__DOT__resultW),32);
	vcdp->chgBit  (c+8,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				   >> 2U))));
	vcdp->chgBit  (c+9,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				   >> 1U))));
	vcdp->chgBit  (c+10,((1U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))));
	vcdp->chgBit  (c+11,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 6U))));
	vcdp->chgBit  (c+12,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 3U))));
	vcdp->chgBit  (c+13,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 8U))));
	vcdp->chgBit  (c+14,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 4U))));
	vcdp->chgBit  (c+15,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 5U))));
	vcdp->chgBit  (c+16,((1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				    >> 7U))));
	vcdp->chgBit  (c+17,(vlTOPp->top__DOT__riscv_32i__DOT__alu_subD));
	vcdp->chgBus  (c+18,(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolD),3);
	vcdp->chgBus  (c+19,(vlTOPp->top__DOT__riscv_32i__DOT__forwardAE),2);
	vcdp->chgBus  (c+20,(vlTOPp->top__DOT__riscv_32i__DOT__forwardBE),2);
	vcdp->chgBus  (c+21,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmF),32);
	vcdp->chgBit  (c+22,(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF));
	vcdp->chgBit  (c+23,(vlTOPp->top__DOT__riscv_32i__DOT__BpredF));
	vcdp->chgBus  (c+24,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE),32);
	vcdp->chgBus  (c+25,(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE),32);
	vcdp->chgBus  (c+26,(((IData)(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE)
			       ? ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
				   ? (vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE 
				      - vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)
				   : ((5U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE))
				       ? (IData)(((
						   ((QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE)) 
						    << 0x20U) 
						   | (QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE))) 
						  >> 
						  (0x1fU 
						   & vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))
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
						    + vlTOPp->top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE)))))),32);
	vcdp->chgBus  (c+27,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__aluop),2);
	vcdp->chgBus  (c+28,(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls),9);
	vcdp->chgBit  (c+29,((1U & ((~ (IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)) 
				    & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls) 
				       >> 6U)))));
    }
}

void Vtop::traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+30,(((0x40U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
			       ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD)
				   ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredD)
				       ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
					   ? ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
					       ? ((IData)(4U) 
						  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
						   ? 
						  ((IData)(4U) 
						   + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
						   : 
						  ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
						    ? 
						   ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
						     ? 
						    (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
						     + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
						     : 
						    ((IData)(4U) 
						     + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))))
					   : vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D)
				       : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
					   ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					      + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
					   : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
					       ? ((IData)(4U) 
						  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
						   ? 
						  ((IData)(4U) 
						   + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
						   : 
						  ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
						    ? 
						   ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
						     ? 
						    (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
						     + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
						     : 
						    ((IData)(4U) 
						     + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))))))
				   : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredD)
				       ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
					   ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					      + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
					   : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
					       ? ((IData)(4U) 
						  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
						   ? 
						  ((IData)(4U) 
						   + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
						   : 
						  ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
						    ? 
						   ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
						     ? 
						    (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
						     + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
						     : 
						    ((IData)(4U) 
						     + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))))
				       : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD)
					   ? (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					      + vlTOPp->top__DOT__riscv_32i__DOT__branchimmD)
					   : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
					       ? ((IData)(4U) 
						  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
					       : ((4U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
						   ? 
						  ((IData)(4U) 
						   + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
						   : 
						  ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
						    ? 
						   ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
						     ? 
						    (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
						     + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
						     : 
						    ((IData)(4U) 
						     + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
						    : 
						   ((IData)(4U) 
						    + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))))))
			       : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
				   ? ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
				       ? ((IData)(4U) 
					  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)
				       : (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					  + ((0xffe00000U 
					      & (VL_NEGATE_I((IData)(
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
							    >> 0x14U))))))))
				   : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls))
				       ? (0xfffffffeU 
					  & (vlTOPp->top__DOT__riscv_32i__DOT__itypeimmD 
					     + vlTOPp->top__DOT__riscv_32i__DOT__aD))
				       : ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitF)
					   ? ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__BpredF)
					       ? (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
						  + vlTOPp->top__DOT__riscv_32i__DOT__branchimmF)
					       : ((IData)(4U) 
						  + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out))
					   : ((IData)(4U) 
					      + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)))))),32);
    }
}

void Vtop::traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+31,(vlTOPp->top__DOT__riscv_32i__DOT__readdataM),32);
	vcdp->chgBus  (c+32,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutM_out),32);
    }
}

void Vtop::traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+33,(vlTOPp->top__DOT__riscv_32i__DOT__aD),32);
	vcdp->chgBus  (c+34,(vlTOPp->top__DOT__riscv_32i__DOT__bD),32);
	vcdp->chgBit  (c+35,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenD));
	vcdp->chgBit  (c+36,(vlTOPp->top__DOT__riscv_32i__DOT__stallF));
	vcdp->chgBit  (c+37,(vlTOPp->top__DOT__riscv_32i__DOT__stallD));
	vcdp->chgBit  (c+38,(vlTOPp->top__DOT__riscv_32i__DOT__stallE));
	vcdp->chgBit  (c+39,(vlTOPp->top__DOT__riscv_32i__DOT__stallM));
	vcdp->chgBit  (c+40,(vlTOPp->top__DOT__riscv_32i__DOT__stallW));
	vcdp->chgBit  (c+41,(vlTOPp->top__DOT__riscv_32i__DOT__flushD));
	vcdp->chgBit  (c+42,(vlTOPp->top__DOT__riscv_32i__DOT__flushE));
	vcdp->chgBit  (c+43,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall));
	vcdp->chgBit  (c+44,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall));
	vcdp->chgBit  (c+45,(vlTOPp->top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall));
    }
}

void Vtop::traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgArray(c+46,(vlTOPp->top__DOT__riscv_32i__DOT__BTB__DOT__BTB),56320);
    }
}

void Vtop::traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1806,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[0]),32);
	vcdp->chgBus  (c+1807,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[1]),32);
	vcdp->chgBus  (c+1808,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[2]),32);
	vcdp->chgBus  (c+1809,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[3]),32);
	vcdp->chgBus  (c+1810,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[4]),32);
	vcdp->chgBus  (c+1811,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[5]),32);
	vcdp->chgBus  (c+1812,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[6]),32);
	vcdp->chgBus  (c+1813,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[7]),32);
	vcdp->chgBus  (c+1814,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[8]),32);
	vcdp->chgBus  (c+1815,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[9]),32);
	vcdp->chgBus  (c+1816,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[10]),32);
	vcdp->chgBus  (c+1817,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[11]),32);
	vcdp->chgBus  (c+1818,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[12]),32);
	vcdp->chgBus  (c+1819,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[13]),32);
	vcdp->chgBus  (c+1820,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[14]),32);
	vcdp->chgBus  (c+1821,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[15]),32);
	vcdp->chgBus  (c+1822,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[16]),32);
	vcdp->chgBus  (c+1823,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[17]),32);
	vcdp->chgBus  (c+1824,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[18]),32);
	vcdp->chgBus  (c+1825,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[19]),32);
	vcdp->chgBus  (c+1826,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[20]),32);
	vcdp->chgBus  (c+1827,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[21]),32);
	vcdp->chgBus  (c+1828,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[22]),32);
	vcdp->chgBus  (c+1829,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[23]),32);
	vcdp->chgBus  (c+1830,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[24]),32);
	vcdp->chgBus  (c+1831,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[25]),32);
	vcdp->chgBus  (c+1832,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[26]),32);
	vcdp->chgBus  (c+1833,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[27]),32);
	vcdp->chgBus  (c+1834,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[28]),32);
	vcdp->chgBus  (c+1835,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[29]),32);
	vcdp->chgBus  (c+1836,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[30]),32);
	vcdp->chgBus  (c+1837,(vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[31]),32);
    }
}

void Vtop::traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1838,(((0U != (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						 >> 0xfU)))
				 ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
				[(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					   >> 0xfU))]
				 : 0U)),32);
	vcdp->chgBus  (c+1839,(((0U != (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						 >> 0x14U)))
				 ? vlTOPp->top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf
				[(0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					   >> 0x14U))]
				 : 0U)),32);
    }
}

void Vtop::traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+1840,(vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out),32);
	vcdp->chgBus  (c+1841,(vlTOPp->top__DOT__riscv_32i__DOT__pcD),32);
	vcdp->chgBus  (c+1842,(vlTOPp->top__DOT__riscv_32i__DOT__pcE),32);
	vcdp->chgBus  (c+1843,(vlTOPp->top__DOT__riscv_32i__DOT__pcM),32);
	vcdp->chgBus  (c+1844,(vlTOPp->top__DOT__riscv_32i__DOT__pcW),32);
	vcdp->chgBus  (c+1845,(((IData)(4U) + vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)),32);
	vcdp->chgBus  (c+1846,(vlTOPp->top__DOT__riscv_32i__DOT__instnD),32);
	vcdp->chgBus  (c+1847,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4D),32);
	vcdp->chgBus  (c+1848,(((0xffe00000U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
									>> 0x1fU)))) 
						<< 0x15U)) 
				| ((0x100000U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						 >> 0xbU)) 
				   | ((0xff000U & vlTOPp->top__DOT__riscv_32i__DOT__instnD) 
				      | ((0x800U & 
					  (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					   >> 9U)) 
					 | (0x7feU 
					    & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					       >> 0x14U))))))),32);
	vcdp->chgBus  (c+1849,((0xfffff000U & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),32);
	vcdp->chgBus  (c+1850,(((0xfffff000U & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
									>> 0x1fU)))) 
						<< 0xcU)) 
				| ((0xfe0U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					      >> 0x14U)) 
				   | (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					       >> 7U))))),32);
	vcdp->chgBus  (c+1851,(vlTOPp->top__DOT__riscv_32i__DOT__pcplus4E),32);
	vcdp->chgBus  (c+1852,(vlTOPp->top__DOT__riscv_32i__DOT__aE),32);
	vcdp->chgBus  (c+1853,(vlTOPp->top__DOT__riscv_32i__DOT__bE),32);
	vcdp->chgBus  (c+1854,(vlTOPp->top__DOT__riscv_32i__DOT__signimmE),32);
	vcdp->chgBus  (c+1855,(vlTOPp->top__DOT__riscv_32i__DOT__utypeimmE),32);
	vcdp->chgBus  (c+1856,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmE),32);
	vcdp->chgBus  (c+1857,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutM),32);
	vcdp->chgBus  (c+1858,(vlTOPp->top__DOT__riscv_32i__DOT__writedataM),32);
	vcdp->chgBus  (c+1859,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmM),32);
	vcdp->chgBus  (c+1860,(vlTOPp->top__DOT__riscv_32i__DOT__readdataW),32);
	vcdp->chgBus  (c+1861,(vlTOPp->top__DOT__riscv_32i__DOT__aluoutW),32);
	vcdp->chgBus  (c+1862,(vlTOPp->top__DOT__riscv_32i__DOT__branchimmW),32);
	vcdp->chgBus  (c+1863,((0x7fU & vlTOPp->top__DOT__riscv_32i__DOT__instnD)),7);
	vcdp->chgBus  (c+1864,((7U & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
				      >> 0xcU))),3);
	vcdp->chgBus  (c+1865,(vlTOPp->top__DOT__riscv_32i__DOT__funct3E),3);
	vcdp->chgBus  (c+1866,(vlTOPp->top__DOT__riscv_32i__DOT__funct3M),3);
	vcdp->chgBus  (c+1867,(vlTOPp->top__DOT__riscv_32i__DOT__funct3W),3);
	vcdp->chgBus  (c+1868,((0x7fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					 >> 0x19U))),7);
	vcdp->chgBit  (c+1869,(vlTOPp->top__DOT__riscv_32i__DOT__branchE));
	vcdp->chgBit  (c+1870,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenE));
	vcdp->chgBit  (c+1871,(vlTOPp->top__DOT__riscv_32i__DOT__jumpE));
	vcdp->chgBit  (c+1872,(vlTOPp->top__DOT__riscv_32i__DOT__jalrE));
	vcdp->chgBit  (c+1873,(vlTOPp->top__DOT__riscv_32i__DOT__auipcE));
	vcdp->chgBit  (c+1874,(vlTOPp->top__DOT__riscv_32i__DOT__luiE));
	vcdp->chgBit  (c+1875,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteE));
	vcdp->chgBit  (c+1876,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregE));
	vcdp->chgBit  (c+1877,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteE));
	vcdp->chgBit  (c+1878,(vlTOPp->top__DOT__riscv_32i__DOT__alusrcE));
	vcdp->chgBit  (c+1879,(vlTOPp->top__DOT__riscv_32i__DOT__alu_subE));
	vcdp->chgBus  (c+1880,(vlTOPp->top__DOT__riscv_32i__DOT__alucontrolE),3);
	vcdp->chgBit  (c+1881,(vlTOPp->top__DOT__riscv_32i__DOT__branchM));
	vcdp->chgBit  (c+1882,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenM));
	vcdp->chgBit  (c+1883,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM));
	vcdp->chgBit  (c+1884,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregM));
	vcdp->chgBit  (c+1885,(vlTOPp->top__DOT__riscv_32i__DOT__memwriteM));
	vcdp->chgBit  (c+1886,(vlTOPp->top__DOT__riscv_32i__DOT__branchW));
	vcdp->chgBit  (c+1887,(vlTOPp->top__DOT__riscv_32i__DOT__br_takenW));
	vcdp->chgBit  (c+1888,(vlTOPp->top__DOT__riscv_32i__DOT__regwriteW));
	vcdp->chgBit  (c+1889,(vlTOPp->top__DOT__riscv_32i__DOT__memtoregW));
	vcdp->chgBus  (c+1890,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					 >> 0xfU))),5);
	vcdp->chgBus  (c+1891,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					 >> 0x14U))),5);
	vcdp->chgBus  (c+1892,((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					 >> 7U))),5);
	vcdp->chgBus  (c+1893,(vlTOPp->top__DOT__riscv_32i__DOT__rsE),5);
	vcdp->chgBus  (c+1894,(vlTOPp->top__DOT__riscv_32i__DOT__rtE),5);
	vcdp->chgBus  (c+1895,(vlTOPp->top__DOT__riscv_32i__DOT__rdE),5);
	vcdp->chgBus  (c+1896,(vlTOPp->top__DOT__riscv_32i__DOT__writeregM),5);
	vcdp->chgBus  (c+1897,(vlTOPp->top__DOT__riscv_32i__DOT__writeregW),5);
	vcdp->chgBit  (c+1898,((((0U != (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						  >> 0xfU))) 
				 & ((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					      >> 0xfU)) 
				    == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
				& (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
	vcdp->chgBit  (c+1899,((((0U != (0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
						  >> 0x14U))) 
				 & ((0x1fU & (vlTOPp->top__DOT__riscv_32i__DOT__instnD 
					      >> 0x14U)) 
				    == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__writeregM))) 
				& (IData)(vlTOPp->top__DOT__riscv_32i__DOT__regwriteM))));
	vcdp->chgBit  (c+1900,(vlTOPp->top__DOT__riscv_32i__DOT__BTBHitD));
	vcdp->chgBit  (c+1901,(vlTOPp->top__DOT__riscv_32i__DOT__BpredD));
	vcdp->chgBus  (c+1902,((0xfffffU & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
					    >> 0xcU))),20);
	vcdp->chgBus  (c+1903,((0x3ffU & (vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out 
					  >> 2U))),10);
	vcdp->chgBus  (c+1904,((0xfffffU & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					    >> 0xcU))),20);
	vcdp->chgBus  (c+1905,((0x3ffU & (vlTOPp->top__DOT__riscv_32i__DOT__pcD 
					  >> 2U))),10);
	vcdp->chgBus  (c+1906,((0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pc_genF_out)),10);
	vcdp->chgBus  (c+1907,((0x3ffU & vlTOPp->top__DOT__riscv_32i__DOT__pcD)),10);
    }
}

void Vtop::traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1908,(vlTOPp->clk));
	vcdp->chgBit  (c+1909,(vlTOPp->reset));
	vcdp->chgBus  (c+1910,(vlTOPp->writedata),32);
	vcdp->chgBus  (c+1911,(vlTOPp->dataadr),32);
	vcdp->chgBus  (c+1912,(vlTOPp->readdata),32);
	vcdp->chgBus  (c+1913,(vlTOPp->pc),32);
	vcdp->chgBus  (c+1914,(vlTOPp->instr),32);
	vcdp->chgBit  (c+1915,(vlTOPp->memwrite));
	vcdp->chgBus  (c+1916,(vlTOPp->top__DOT__L1_cache__DOT__MEM
			       [(0x1ffffU & (vlTOPp->pc 
					     >> 2U))]),32);
	vcdp->chgBus  (c+1917,(((IData)(vlTOPp->top__DOT__memaccessM)
				 ? vlTOPp->top__DOT__L1_cache__DOT__MEM
				[(0x1ffffU & (vlTOPp->dataadr 
					      >> 2U))]
				 : 0U)),32);
    }
}
