// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop___024unit.h"
#include "Vtop_controller_if.h"

// FUNCTIONS
Vtop__Syms::~Vtop__Syms()
{
}

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep,Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__top__DOT__riscv_32i__DOT__c_bus{this, Verilated::catName(namep, "top.riscv_32i.c_bus")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__top__DOT__riscv_32i__DOT__c_bus = &TOP__top__DOT__riscv_32i__DOT__c_bus;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__top__DOT__riscv_32i__DOT__c_bus.__Vconfigure(true);
    // Setup scopes
    __Vscope_top__L1_cache.configure(this, name(), "top.L1_cache", "L1_cache", -12, VerilatedScope::SCOPE_OTHER);
}
