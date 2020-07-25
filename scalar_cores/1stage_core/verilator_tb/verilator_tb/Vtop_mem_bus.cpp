// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop_mem_bus.h"      // For This
#include "Vtop__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop_mem_bus) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void Vtop_mem_bus::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop_mem_bus::~Vtop_mem_bus() {
}

//--------------------
// Internal Methods

void Vtop_mem_bus::_initial__TOP__top__DOT__Bus__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_mem_bus::_initial__TOP__top__DOT__Bus__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIGW(__Vtemp1,543,0,17);
    // Body
    // INITIAL at ../top_test.sv:78
    __Vtemp1[0U] = 0x2e646174U;
    __Vtemp1[1U] = 0x66696c65U;
    __Vtemp1[2U] = 0x2f6d656dU;
    __Vtemp1[3U] = 0x636f7265U;
    __Vtemp1[4U] = 0x6167655fU;
    __Vtemp1[5U] = 0x2f317374U;
    __Vtemp1[6U] = 0x6f726573U;
    __Vtemp1[7U] = 0x61725f63U;
    __Vtemp1[8U] = 0x7363616cU;
    __Vtemp1[9U] = 0x6f72652fU;
    __Vtemp1[0xaU] = 0x6c746963U;
    __Vtemp1[0xbU] = 0x732d6d75U;
    __Vtemp1[0xcU] = 0x6e656f75U;
    __Vtemp1[0xdU] = 0x726f6765U;
    __Vtemp1[0xeU] = 0x48657465U;
    __Vtemp1[0xfU] = 0x6f6f742fU;
    __Vtemp1[0x10U] = 0x2f72U;
    VL_READMEM_W (true,32,131072, 0,17, __Vtemp1, vlSymsp->TOP__top__DOT__Bus.__PVT__MEM
		  ,0,~0);
}

VL_INLINE_OPT void Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__MEM__v0,0,0);
    VL_SIG(__Vdlyvdim0__MEM__v0,16,0);
    VL_SIG(__Vdlyvval__MEM__v0,31,0);
    // Body
    __Vdlyvset__MEM__v0 = 0U;
    // ALWAYS at ../top_test.sv:88
    if (vlTOPp->memwrite) {
	__Vdlyvval__MEM__v0 = vlTOPp->writedata;
	__Vdlyvset__MEM__v0 = 1U;
	__Vdlyvdim0__MEM__v0 = (0x1ffffU & (vlTOPp->dataadr 
					    >> 2U));
    }
    // ALWAYSPOST at ../top_test.sv:89
    if (__Vdlyvset__MEM__v0) {
	vlSymsp->TOP__top__DOT__Bus.__PVT__MEM[__Vdlyvdim0__MEM__v0] 
	    = __Vdlyvval__MEM__v0;
    }
}

VL_INLINE_OPT void Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__DOT__Bus.Iinstn = vlSymsp->TOP__top__DOT__Bus.__PVT__MEM
	[(0x1ffffU & (vlTOPp->top__DOT__pc >> 2U))];
}

VL_INLINE_OPT void Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_mem_bus::_sequent__TOP__top__DOT__Bus__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__top__DOT__Bus.Dreaddata = vlSymsp->TOP__top__DOT__Bus.__PVT__MEM
	[(0x1ffffU & (vlTOPp->dataadr >> 2U))];
}

void Vtop_mem_bus::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_mem_bus::_ctor_var_reset\n"); );
    // Body
    Iinstn = VL_RAND_RESET_I(32);
    Dreaddata = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<131072; ++__Vi0) {
	    __PVT__MEM[__Vi0] = 0;
    }}
}
