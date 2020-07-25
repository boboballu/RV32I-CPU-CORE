// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES

VL_ST_SIG16(Vtop::__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[128],8,0);
VL_ST_SIG8(Vtop::__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[128],1,0);

//--------------------

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL (__PVT__top__DOT__Bus, Vtop_mem_bus);
    VL_CELL (__PVT__top__DOT__riscv_32i__DOT__c_bus, Vtop_controller_if);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    QData __Vchange = 1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0,4,0);
    VL_SIG8(__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0,0,0);
    VL_SIG(__Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0,31,0);
    // Body
    __Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 0U;
    // ALWAYS at ../datapath.sv:163
    if ((0x100U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))) {
	__Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
	    = vlTOPp->top__DOT__riscv_32i__DOT__result;
	__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 = 1U;
	__Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0 
	    = (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
			>> 7U));
    }
    // ALWAYSPOST at ../datapath.sv:164
    if (__Vdlyvset__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0) {
	vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[__Vdlyvdim0__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0] 
	    = __Vdlyvval__top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf__v0;
    }
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG(__Vdly__top__DOT__pc,31,0);
    // Body
    __Vdly__top__DOT__pc = vlTOPp->top__DOT__pc;
    // ALWAYS at ../datapath.sv:63
    __Vdly__top__DOT__pc = ((IData)(vlTOPp->reset) ? 0U
			     : ((((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
				  >> 6U) & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken))
				 ? ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
				     ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
				     : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
					 ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4
					 : (vlTOPp->top__DOT__pc 
					    + ((0xffffe000U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlSymsp->TOP__top__DOT__Bus.Iinstn 
									   >> 0x1fU)))) 
						   << 0xdU)) 
					       | ((0x1000U 
						   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						      >> 0x13U)) 
						  | ((0x800U 
						      & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							 << 4U)) 
						     | ((0x7e0U 
							 & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							    >> 0x14U)) 
							| (0x1eU 
							   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							      >> 7U)))))))))
				 : ((8U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
				     ? ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
					 ? (0xfffffffeU 
					    & (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
					       + vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca))
					 : (vlTOPp->top__DOT__pc 
					    + ((0xffe00000U 
						& (VL_NEGATE_I((IData)(
								       (1U 
									& (vlSymsp->TOP__top__DOT__Bus.Iinstn 
									   >> 0x1fU)))) 
						   << 0x15U)) 
					       | ((0x100000U 
						   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						      >> 0xbU)) 
						  | ((0xff000U 
						      & vlSymsp->TOP__top__DOT__Bus.Iinstn) 
						     | ((0x800U 
							 & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							    >> 9U)) 
							| (0x7feU 
							   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							      >> 0x14U))))))))
				     : ((4U & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
					 ? (0xfffffffeU 
					    & (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
					       + vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca))
					 : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4))));
    vlTOPp->top__DOT__pc = __Vdly__top__DOT__pc;
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 
	= ((IData)(4U) + vlTOPp->top__DOT__pc);
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
	= ((0U != (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
			    >> 0xfU))) ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
	   [(0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		      >> 0xfU))] : 0U);
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm 
	= ((0xfffff000U & (VL_NEGATE_I((IData)((1U 
						& (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						   >> 0x1fU)))) 
			   << 0xcU)) | (0xfffU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						  >> 0x14U)));
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0 
	= ((0U != (0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
			    >> 0x14U))) ? vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf
	   [(0x1fU & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		      >> 0x14U))] : 0U);
    // ALWAYS at ../controller.sv:27
    vlTOPp->__Vtableidx1 = (0x7fU & vlSymsp->TOP__top__DOT__Bus.Iinstn);
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
	        ? ((0xfffff000U & (VL_NEGATE_I((IData)(
						       (1U 
							& (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							   >> 0x1fU)))) 
				   << 0xcU)) | ((0xfe0U 
						 & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						    >> 0x14U)) 
						| (0x1fU 
						   & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						      >> 7U))))
	        : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm)
	    : vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0);
    // ALWAYS at ../controller.sv:48
    if ((0U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))) {
	vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol = 0U;
	vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub = 0U;
    } else {
	if ((1U == (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__aluop))) {
	    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol = 0U;
	    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub = 1U;
	} else {
	    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol 
		= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
			 >> 0xcU));
	    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub 
		= (1U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
			 >> 0x1eU));
	}
    }
    // ALWAYS at ../datapath.sv:123
    vlTOPp->dataadr = ((IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alu_sub)
		        ? ((0U == (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
			    ? (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
			       - vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
			    : ((5U == (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
			        ? (IData)(((((QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca)) 
					     << 0x20U) 
					    | (QData)((IData)(vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca))) 
					   >> (0x1fU 
					       & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))
			        : 0U)) : ((4U & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
					   ? ((2U & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
					       ? ((1U 
						   & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
						   ? 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
						   : 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   | vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
					       : ((1U 
						   & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
						   ? 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   >> 
						   (0x1fU 
						    & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
						   : 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   ^ vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))
					   : ((2U & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
					       ? ((1U 
						   & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
						   ? 
						  ((vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						    < vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
						    ? 1U
						    : 0U)
						   : 
						  (VL_LTS_III(1,32,32, vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca, vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)
						    ? 1U
						    : 0U))
					       : ((1U 
						   & (IData)(vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.alucontrol))
						   ? 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   << 
						   (0x1fU 
						    & vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb))
						   : 
						  (vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca 
						   + vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb)))));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../datapath.sv:89
    // Function: load_compute at ../datapath.sv:100
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
	= vlSymsp->TOP__top__DOT__Bus.Dreaddata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout 
	= vlTOPp->dataadr;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    {
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
					    >> 0x18U))
			        : (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					    >> 0x10U)))
			    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					    >> 8U))
			        : (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))
	        : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
		    ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
		    : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
		        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffff0000U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0xfU)))) 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
						 >> 0x10U)))
			        : 0U) : ((0xffff0000U 
					  & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
								     >> 0xfU)))) 
					     << 0x10U)) 
					 | (0xffffU 
					    & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))
		        : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			    ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0x1fU)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 0x18U)))
			        : ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0x17U)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 0x10U))))
			    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0xfU)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 8U)))
			        : ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 7U)))) 
						   << 8U)) 
				   | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))));
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout 
	    = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
	goto __Vlabel1;
    }
    __Vlabel1: ;
    vlTOPp->top__DOT__riscv_32i__DOT__result = ((1U 
						 & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						     >> 3U) 
						    | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						       >> 2U)))
						 ? 
						((IData)(4U) 
						 + vlTOPp->top__DOT__pc)
						 : 
						((2U 
						  & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						  ? 
						 (vlTOPp->top__DOT__pc 
						  + 
						  (0xfffff000U 
						   & vlSymsp->TOP__top__DOT__Bus.Iinstn))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						   ? 
						  (0xfffff000U 
						   & vlSymsp->TOP__top__DOT__Bus.Iinstn)
						   : 
						  ((0x10U 
						    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						    ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout
						    : vlTOPp->dataadr))));
    // Function: store_compute at ../datapath.sv:105
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata 
	= vlSymsp->TOP__top__DOT__Bus.Dreaddata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout 
	= vlTOPp->dataadr;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    {
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
	    = ((0U == (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))
	        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		    ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((0xff000000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					   << 0x18U)) 
			   | (0xffffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))
		        : ((0xff000000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | ((0xff0000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					    << 0x10U)) 
			      | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))))
		    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((0xffff0000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | ((0xff00U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					  << 8U)) | 
			      (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata)))
		        : ((0xffffff00U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0))))
	        : ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))
		    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
			    ? ((0xffff0000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					       << 0x10U)) 
			       | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))
			    : 0U) : ((0xffff0000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
				     | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0)))
		    : vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0));
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout 
	    = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
	goto __Vlabel2;
    }
    __Vlabel2: ;
    vlTOPp->writedata = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout;
    // Function: br_compute at ../datapath.sv:106
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch 
	= (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
		 >> 6U));
    {
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
	goto __Vlabel3;
    }
    __Vlabel3: ;
    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken 
	= vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    vlTOPp->dbg[0U] = ((0xfffffff8U & (vlSymsp->TOP__top__DOT__Bus.Dreaddata 
				       << 3U)) | ((4U 
						   & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						      >> 5U)) 
						  | ((2U 
						      & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
							 >> 7U)) 
						     | (1U 
							& ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
							   >> 4U)))));
    vlTOPp->dbg[1U] = ((7U & (vlSymsp->TOP__top__DOT__Bus.Dreaddata 
			      >> 0x1dU)) | (0xfffffff8U 
					    & ((IData)(
						       (((QData)((IData)(vlTOPp->dataadr)) 
							 << 0x20U) 
							| (QData)((IData)(vlTOPp->writedata)))) 
					       << 3U)));
    vlTOPp->dbg[2U] = ((7U & ((IData)((((QData)((IData)(vlTOPp->dataadr)) 
					<< 0x20U) | (QData)((IData)(vlTOPp->writedata)))) 
			      >> 0x1dU)) | (0xfffffff8U 
					    & ((IData)(
						       ((((QData)((IData)(vlTOPp->dataadr)) 
							  << 0x20U) 
							 | (QData)((IData)(vlTOPp->writedata))) 
							>> 0x20U)) 
					       << 3U)));
    vlTOPp->dbg[3U] = ((0xfffffff0U & (vlTOPp->top__DOT__riscv_32i__DOT__result 
				       << 4U)) | ((8U 
						   & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						      >> 2U)) 
						  | (7U 
						     & ((IData)(
								((((QData)((IData)(vlTOPp->dataadr)) 
								   << 0x20U) 
								  | (QData)((IData)(vlTOPp->writedata))) 
								 >> 0x20U)) 
							>> 0x1dU))));
    vlTOPp->dbg[4U] = ((0xfc000000U & (vlTOPp->top__DOT__pc 
				       << 0x1aU)) | 
		       ((0x3f80000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       << 0x13U)) | 
			((0x7c000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				      >> 1U)) | ((0x3e00U 
						  & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						     >> 0xbU)) 
						 | ((0x1f0U 
						     & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							>> 3U)) 
						    | (0xfU 
						       & (vlTOPp->top__DOT__riscv_32i__DOT__result 
							  >> 0x1cU)))))));
    vlTOPp->dbg[5U] = (0x3ffffffU & (vlTOPp->top__DOT__pc 
				     >> 6U));
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 
	= ((IData)(4U) + vlTOPp->top__DOT__pc);
}

void Vtop::_settle__TOP__7(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__7\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../datapath.sv:89
    // Function: load_compute at ../datapath.sv:100
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
	= vlSymsp->TOP__top__DOT__Bus.Dreaddata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout 
	= vlTOPp->dataadr;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    {
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
					    >> 0x18U))
			        : (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					    >> 0x10U)))
			    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					    >> 8U))
			        : (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))
	        : ((2U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
		    ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata
		    : ((1U & (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3))
		        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffff0000U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0xfU)))) 
						   << 0x10U)) 
				   | (0xffffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
						 >> 0x10U)))
			        : 0U) : ((0xffff0000U 
					  & (VL_NEGATE_I((IData)(
								 (1U 
								  & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
								     >> 0xfU)))) 
					     << 0x10U)) 
					 | (0xffffU 
					    & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))
		        : ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			    ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0x1fU)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 0x18U)))
			        : ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0x17U)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 0x10U))))
			    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout)
			        ? ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 0xfU)))) 
						   << 8U)) 
				   | (0xffU & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
					       >> 8U)))
			        : ((0xffffff00U & (
						   VL_NEGATE_I((IData)(
								       (1U 
									& (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata 
									   >> 7U)))) 
						   << 8U)) 
				   | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata)))))));
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout 
	    = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
	goto __Vlabel4;
    }
    __Vlabel4: ;
    vlTOPp->top__DOT__riscv_32i__DOT__result = ((1U 
						 & (((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						     >> 3U) 
						    | ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						       >> 2U)))
						 ? 
						((IData)(4U) 
						 + vlTOPp->top__DOT__pc)
						 : 
						((2U 
						  & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						  ? 
						 (vlTOPp->top__DOT__pc 
						  + 
						  (0xfffff000U 
						   & vlSymsp->TOP__top__DOT__Bus.Iinstn))
						  : 
						 ((1U 
						   & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						   ? 
						  (0xfffff000U 
						   & vlSymsp->TOP__top__DOT__Bus.Iinstn)
						   : 
						  ((0x10U 
						    & (IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls))
						    ? vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout
						    : vlTOPp->dataadr))));
    // Function: store_compute at ../datapath.sv:105
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata 
	= vlSymsp->TOP__top__DOT__Bus.Dreaddata;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout 
	= vlTOPp->dataadr;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    {
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata 
	    = ((0U == (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))
	        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		    ? ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((0xff000000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					   << 0x18U)) 
			   | (0xffffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))
		        : ((0xff000000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | ((0xff0000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					    << 0x10U)) 
			      | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))))
		    : ((1U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((0xffff0000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | ((0xff00U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					  << 8U)) | 
			      (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata)))
		        : ((0xffffff00U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
			   | (0xffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0))))
	        : ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3))
		    ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
		        ? ((2U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout)
			    ? ((0xffff0000U & (vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 
					       << 0x10U)) 
			       | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata))
			    : 0U) : ((0xffff0000U & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata) 
				     | (0xffffU & vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0)))
		    : vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0));
	vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout 
	    = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
	goto __Vlabel5;
    }
    __Vlabel5: ;
    vlTOPp->writedata = vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout;
    // Function: br_compute at ../datapath.sv:106
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca 
	= vlTOPp->top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3 
	= (7U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
		 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch 
	= (1U & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
		 >> 6U));
    {
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
	goto __Vlabel6;
    }
    __Vlabel6: ;
    vlSymsp->TOP__top__DOT__riscv_32i__DOT__c_bus.br_taken 
	= vlTOPp->__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    vlTOPp->dbg[0U] = ((0xfffffff8U & (vlSymsp->TOP__top__DOT__Bus.Dreaddata 
				       << 3U)) | ((4U 
						   & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						      >> 5U)) 
						  | ((2U 
						      & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
							 >> 7U)) 
						     | (1U 
							& ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
							   >> 4U)))));
    vlTOPp->dbg[1U] = ((7U & (vlSymsp->TOP__top__DOT__Bus.Dreaddata 
			      >> 0x1dU)) | (0xfffffff8U 
					    & ((IData)(
						       (((QData)((IData)(vlTOPp->dataadr)) 
							 << 0x20U) 
							| (QData)((IData)(vlTOPp->writedata)))) 
					       << 3U)));
    vlTOPp->dbg[2U] = ((7U & ((IData)((((QData)((IData)(vlTOPp->dataadr)) 
					<< 0x20U) | (QData)((IData)(vlTOPp->writedata)))) 
			      >> 0x1dU)) | (0xfffffff8U 
					    & ((IData)(
						       ((((QData)((IData)(vlTOPp->dataadr)) 
							  << 0x20U) 
							 | (QData)((IData)(vlTOPp->writedata))) 
							>> 0x20U)) 
					       << 3U)));
    vlTOPp->dbg[3U] = ((0xfffffff0U & (vlTOPp->top__DOT__riscv_32i__DOT__result 
				       << 4U)) | ((8U 
						   & ((IData)(vlTOPp->top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls) 
						      >> 2U)) 
						  | (7U 
						     & ((IData)(
								((((QData)((IData)(vlTOPp->dataadr)) 
								   << 0x20U) 
								  | (QData)((IData)(vlTOPp->writedata))) 
								 >> 0x20U)) 
							>> 0x1dU))));
    vlTOPp->dbg[4U] = ((0xfc000000U & (vlTOPp->top__DOT__pc 
				       << 0x1aU)) | 
		       ((0x3f80000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				       << 0x13U)) | 
			((0x7c000U & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
				      >> 1U)) | ((0x3e00U 
						  & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
						     >> 0xbU)) 
						 | ((0x1f0U 
						     & (vlSymsp->TOP__top__DOT__Bus.Iinstn 
							>> 3U)) 
						    | (0xfU 
						       & (vlTOPp->top__DOT__riscv_32i__DOT__result 
							  >> 0x1cU)))))));
    vlTOPp->dbg[5U] = (0x3ffffffU & (vlTOPp->top__DOT__pc 
				     >> 6U));
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
	vlSymsp->TOP__top__DOT__Bus._sequent__TOP__top__DOT__Bus__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
	vlSymsp->TOP__top__DOT__Bus._sequent__TOP__top__DOT__Bus__3(vlSymsp);
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlSymsp->TOP__top__DOT__Bus._sequent__TOP__top__DOT__Bus__4(vlSymsp);
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__DOT__Bus._initial__TOP__top__DOT__Bus__1(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
    vlSymsp->TOP__top__DOT__Bus._sequent__TOP__top__DOT__Bus__3(vlSymsp);
    vlTOPp->_sequent__TOP__3(vlSymsp);
    vlSymsp->TOP__top__DOT__Bus._sequent__TOP__top__DOT__Bus__4(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
#endif // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    writedata = VL_RAND_RESET_I(32);
    dataadr = VL_RAND_RESET_I(32);
    memwrite = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(186,dbg);
    top__DOT__pc = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__result = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__controller__DOT__aluop = VL_RAND_RESET_I(2);
    top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls = VL_RAND_RESET_I(9);
    top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4 = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__datapath__DOT__srca = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__datapath__DOT__srcb = VL_RAND_RESET_I(32);
    top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[__Vi0] = 0;
    }}
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3 = VL_RAND_RESET_I(3);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3 = VL_RAND_RESET_I(3);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0 = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout = VL_RAND_RESET_I(1);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch = VL_RAND_RESET_I(1);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3 = VL_RAND_RESET_I(3);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken = VL_RAND_RESET_I(1);
    __Vtableidx1 = VL_RAND_RESET_I(7);
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[0] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[1] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[2] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[3] = 0x190U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[4] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[5] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[6] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[7] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[8] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[9] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[10] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[11] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[12] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[13] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[14] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[15] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[16] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[17] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[18] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[19] = 0x180U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[20] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[21] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[22] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[23] = 0x102U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[24] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[25] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[26] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[27] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[28] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[29] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[30] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[31] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[32] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[33] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[34] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[35] = 0xa0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[36] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[37] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[38] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[39] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[40] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[41] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[42] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[43] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[44] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[45] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[46] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[47] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[48] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[49] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[50] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[51] = 0x100U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[52] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[53] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[54] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[55] = 0x101U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[56] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[57] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[58] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[59] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[60] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[61] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[62] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[63] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[64] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[65] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[66] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[67] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[68] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[69] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[70] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[71] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[72] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[73] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[74] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[75] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[76] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[77] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[78] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[79] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[80] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[81] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[82] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[83] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[84] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[85] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[86] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[87] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[88] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[89] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[90] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[91] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[92] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[93] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[94] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[95] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[96] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[97] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[98] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[99] = 0x40U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[100] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[101] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[102] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[103] = 0x10cU;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[104] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[105] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[106] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[107] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[108] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[109] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[110] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[111] = 0x108U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[112] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[113] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[114] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[115] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[116] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[117] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[118] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[119] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[120] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[121] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[122] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[123] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[124] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[125] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[126] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[127] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[0] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[1] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[2] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[3] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[4] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[5] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[6] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[7] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[8] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[9] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[10] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[11] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[12] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[13] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[14] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[15] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[16] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[17] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[18] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[19] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[20] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[21] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[22] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[23] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[24] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[25] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[26] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[27] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[28] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[29] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[30] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[31] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[32] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[33] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[34] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[35] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[36] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[37] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[38] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[39] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[40] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[41] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[42] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[43] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[44] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[45] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[46] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[47] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[48] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[49] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[50] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[51] = 2U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[52] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[53] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[54] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[55] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[56] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[57] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[58] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[59] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[60] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[61] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[62] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[63] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[64] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[65] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[66] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[67] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[68] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[69] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[70] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[71] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[72] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[73] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[74] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[75] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[76] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[77] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[78] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[79] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[80] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[81] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[82] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[83] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[84] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[85] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[86] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[87] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[88] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[89] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[90] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[91] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[92] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[93] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[94] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[95] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[96] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[97] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[98] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[99] = 1U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[100] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[101] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[102] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[103] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[104] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[105] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[106] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[107] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[108] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[109] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[110] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[111] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[112] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[113] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[114] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[115] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[116] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[117] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[118] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[119] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[120] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[121] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[122] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[123] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[124] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[125] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[126] = 0U;
    __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[127] = 0U;
    __Vclklast__TOP__clk = VL_RAND_RESET_I(1);
    __Vclklast__TOP__reset = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
