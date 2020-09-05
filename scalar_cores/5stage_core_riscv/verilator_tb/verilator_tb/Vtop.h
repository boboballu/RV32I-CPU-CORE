// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vtop_H_
#define _Vtop_H_

#include "verilated_heavy.h"

class Vtop__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vtop) {
  public:
    
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
    VL_SIG8(top__DOT__memaccessM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__funct3E,2,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__funct3M,2,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__funct3W,2,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__br_takenD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__alu_subD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__alucontrolD,2,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__branchE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__br_takenE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__jumpE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__jalrE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__auipcE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__luiE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__regwriteE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__memtoregE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__memwriteE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__alusrcE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__alu_subE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__alucontrolE,2,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__branchM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__br_takenM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__regwriteM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__memtoregM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__memwriteM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__branchW,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__br_takenW,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__regwriteW,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__memtoregW,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__br_actual,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__rsE,4,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__rtE,4,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__rdE,4,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__writeregM,4,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__writeregW,4,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__forwardAE,1,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__forwardBE,1,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__stallF,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__stallD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__stallE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__stallM,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__stallW,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__flushD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__flushE,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__BTBHitF,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__BpredF,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__BTBHitD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__BpredD,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__ctrl__DOT__aluop,1,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall,0,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall,0,0);
    VL_SIG16(top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls,8,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pc_genF_in,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pc_genF_out,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcM,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcW,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__instnD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcplus4D,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__branchimmD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__itypeimmD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__aD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__bD,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__pcplus4E,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__aE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__bE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__signimmE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__utypeimmE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__branchimmE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__aluoutM,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__writedataM,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__branchimmM,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__readdataM,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__aluoutM_out,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__readdataW,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__aluoutW,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__branchimmW,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__resultW,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__branchimmF,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE,31,0);
    VL_SIG(top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0,31,0);
    VL_SIGW(top__DOT__riscv_32i__DOT__BTB__DOT__BTB,56319,0,1760);
    std::string top__DOT__L1_cache__DOT__EXEC;
    VL_SIG(top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[32],31,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[1024],1,0);
    VL_SIG(top__DOT__L1_cache__DOT__MEM[131072],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    static VL_ST_SIG16(__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[128],8,0);
    static VL_ST_SIG8(__Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[128],1,0);
    VL_SIG8(top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound2,2,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3,2,0);
    VL_SIG8(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3,2,0);
    VL_SIG8(__Vtableidx1,6,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__BTBHitD,0,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__BpredD,0,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__alusrcE,0,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__rsE,4,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__rtE,4,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__memwriteM,0,0);
    VL_SIG8(__Vdly__top__DOT__riscv_32i__DOT__memtoregW,0,0);
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    VL_SIG(top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound1,19,0);
    VL_SIG(top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound3,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__Vfuncout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__result,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__Vfuncout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__readdata,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0,31,0);
    VL_SIG(__Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__aE,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__bE,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__signimmE,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__aluoutM,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__writedataM,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__aluoutW,31,0);
    VL_SIG(__Vdly__top__DOT__riscv_32i__DOT__readdataW,31,0);
    VL_SIG(__Vchglast__TOP__readdata,31,0);
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
  public:
    static void _combo__TOP__7(Vtop__Syms* __restrict vlSymsp);
  private:
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
    static void _initial__TOP__1(Vtop__Syms* __restrict vlSymsp);
    static void _multiclk__TOP__8(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vtop__Syms* __restrict vlSymsp);
    static void traceChgThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__10(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInitThis__1(Vtop__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceInit (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull (VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg  (VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
