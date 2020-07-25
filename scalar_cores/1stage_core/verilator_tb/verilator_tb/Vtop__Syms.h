// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vtop__Syms_H_
#define _Vtop__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vtop.h"
#include "Vtop___024unit.h"
#include "Vtop_mem_bus.h"
#include "Vtop_controller_if.h"

// SYMS CLASS
class Vtop__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_activity;  ///< Used by trace routines to determine change occurred
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtop*                          TOPp;
    Vtop_mem_bus                   TOP__top__DOT__Bus;
    Vtop_controller_if             TOP__top__DOT__riscv_32i__DOT__c_bus;
    
    // CREATORS
    Vtop__Syms(Vtop* topp, const char* namep);
    ~Vtop__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    inline bool getClearActivity() { bool r=__Vm_activity; __Vm_activity=false; return r; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
