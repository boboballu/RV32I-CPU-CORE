// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated.h"

class Vtop__Syms;
class Vtop_mem_bus;
class Vtop_controller_if;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vtop_mem_bus*      	__PVT__top__DOT__Bus;
    Vtop_controller_if*	__PVT__top__DOT__riscv_32i__DOT__c_bus;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(memwrite,0,0);
    VL_OUT(writedata,31,0);
    VL_OUT(dataadr,31,0);
    VL_OUTW(dbg,185,0,6);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(top__DOT__riscv_32i__DOT__controller__DOT__aluop,1,0);
    VL_SIG16(top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls,8,0);
    VL_SIG(top__DOT__pc,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__result,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__pcplus4,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__itypeimm,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__srca,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__srcb,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__srcb_net0,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__datapath__DOT__rf__DOT__rf[32],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG16(__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__maindec__DOT__controls[128],8,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__riscv_32i__DOT__controller__DOT__aluop[128],1,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__funct3,2,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__funct3,2,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__Vfuncout,0,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__branch,0,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__funct3,2,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__br_taken,0,0);
    VL_SIG8(__Vtableidx1,6,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__Vfuncout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__aluout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__readdata,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__load_compute__0__result,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__Vfuncout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__aluout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__readdata,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__srcb_net0,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__store_compute__1__writedata,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srca,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__datapath__DOT__br_compute__2__srcb,31,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtop__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vtop& operator= (const Vtop&);  ///< Copying not allowed
    Vtop(const Vtop&);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vtop(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtop();
    /// Trace signals in the model; called by application code
    void trace (VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtop__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtop__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vtop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vtop__Syms* __restrict vlSymsp);
    static void _eval_settle(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
