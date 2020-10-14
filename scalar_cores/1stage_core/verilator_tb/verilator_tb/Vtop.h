// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOP_H_
#define _VTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;
class Vtop_controller_if;


//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_controller_if* __PVT__top__DOT__riscv_32i__DOT__c_bus;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(memwrite,0,0);
    VL_OUT(writedata,31,0);
    VL_OUT(dataadr,31,0);
    VL_OUT(readdata,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(instr,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ top__DOT__dmem_mask;
    CData/*1:0*/ top__DOT__riscv_32i__DOT__controller__DOT__aluop;
    SData/*8:0*/ top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srca;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srcb;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__result;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[32];
    IData/*31:0*/ top__DOT__L1_cache__DOT__MEM[65536];
    std::string top__DOT__L1_cache__DOT__EXEC;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3;
    CData/*2:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3;
    CData/*3:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__dmem_mask;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch;
    CData/*2:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3;
    CData/*0:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken;
    CData/*6:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb;
    CData/*0:0*/ __Vm_traceActivity[3];
    static SData/*8:0*/ __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[128];
    static CData/*1:0*/ __Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub1(void* userp, VerilatedVcd* tracep, const char* scopep) VL_ATTR_COLD;
    static void traceInitSub2(void* userp, VerilatedVcd* tracep, const char* scopep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
