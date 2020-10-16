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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ top__DOT__dmem_req;
        CData/*0:0*/ top__DOT__imem_req;
        CData/*3:0*/ top__DOT__dmem_mask;
        CData/*2:0*/ top__DOT__riscv_32i__DOT__funct3E;
        CData/*2:0*/ top__DOT__riscv_32i__DOT__funct3M;
        CData/*2:0*/ top__DOT__riscv_32i__DOT__funct3W;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__br_takenD;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__branchE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__br_takenE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__jumpE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__jalrE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__auipcE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__luiE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__regwriteE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__memtoregE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__memwriteE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__alusrcE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__alu_subE;
        CData/*2:0*/ top__DOT__riscv_32i__DOT__alucontrolE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__branchM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__br_takenM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__regwriteM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__memtoregM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__memwriteM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__branchW;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__br_takenW;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__regwriteW;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__memtoregW;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__br_actual;
        CData/*4:0*/ top__DOT__riscv_32i__DOT__rsE;
        CData/*4:0*/ top__DOT__riscv_32i__DOT__rtE;
        CData/*4:0*/ top__DOT__riscv_32i__DOT__rdE;
        CData/*4:0*/ top__DOT__riscv_32i__DOT__writeregM;
        CData/*4:0*/ top__DOT__riscv_32i__DOT__writeregW;
        CData/*1:0*/ top__DOT__riscv_32i__DOT__forwardAE;
        CData/*1:0*/ top__DOT__riscv_32i__DOT__forwardBE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__stallF;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__stallD;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__stallE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__stallM;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__stallW;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__flushD;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__flushE;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__BTBHitF;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__BpredF;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__BTBHitD;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__BpredD;
        CData/*1:0*/ top__DOT__riscv_32i__DOT__ctrl__DOT__aluop;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__hazard_unit1__DOT__lwstall;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__hazard_unit1__DOT__branchstall;
        CData/*0:0*/ top__DOT__riscv_32i__DOT__hazard_unit1__DOT__memstall;
        SData/*8:0*/ top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pc_genF_in;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pc_genF_out;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcD;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcM;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcW;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__instnD;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcplus4D;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__branchimmD;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__itypeimmD;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__aD;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__bD;
    };
    struct {
        IData/*31:0*/ top__DOT__riscv_32i__DOT__pcplus4E;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__aE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__bE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__signimmE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__utypeimmE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__branchimmE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__aluoutM;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__writedataM;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__branchimmM;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__readdataM;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__readdataW;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__aluoutW;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__branchimmW;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__resultW;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__branchimmF;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__ex_comb__DOT__srcAE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE;
        IData/*31:0*/ top__DOT__riscv_32i__DOT__ex_comb__DOT__srcBE_net0;
        WData/*56319:0*/ top__DOT__riscv_32i__DOT__BTB__DOT__BTB[1760];
        IData/*31:0*/ top__DOT__riscv_32i__DOT__id_comb__DOT__rf__DOT__rf[32];
        CData/*1:0*/ top__DOT__riscv_32i__DOT__Bpred__DOT__BIMODAL_TABLE[1024];
        IData/*31:0*/ top__DOT__L1_cache__DOT__MEM[16384];
    };
    std::string top__DOT__L1_cache__DOT__EXEC;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound2;
    CData/*2:0*/ __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__funct3;
    CData/*2:0*/ __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__funct3;
    CData/*3:0*/ __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__dmem_mask;
    CData/*6:0*/ __Vtableidx1;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    IData/*19:0*/ top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound1;
    IData/*31:0*/ top__DOT__riscv_32i__DOT__BTB__DOT____Vlvbound3;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__Vfuncout;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__aluout;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__readdata;
    IData/*31:0*/ __Vfunc_top__DOT__riscv_32i__DOT__mem_comb__DOT__load_compute__0__result;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__aluout;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__srcb_net0;
    IData/*31:0*/ __Vtask_top__DOT__riscv_32i__DOT__mem_comb__DOT__store_compute__1__writedata;
    CData/*0:0*/ __Vm_traceActivity[5];
    static SData/*8:0*/ __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__maindec__DOT__controls[128];
    static CData/*1:0*/ __Vtable1_top__DOT__riscv_32i__DOT__ctrl__DOT__aluop[128];
    
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
    static void _multiclk__TOP__7(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtop__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtop__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vtop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub1(void* userp, VerilatedVcd* tracep, const char* scopep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
