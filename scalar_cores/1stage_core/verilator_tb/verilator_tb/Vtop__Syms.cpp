// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop___024unit.h"
#include "Vtop_mem_bus.h"
#include "Vtop_controller_if.h"

// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_activity(false)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__top__DOT__Bus             (Verilated::catName(topp->name(),"top.Bus"))
	, TOP__top__DOT__riscv_32i__DOT__c_bus (Verilated::catName(topp->name(),"top.riscv_32i.c_bus"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__top__DOT__Bus      = &TOP__top__DOT__Bus;
    TOPp->__PVT__top__DOT__riscv_32i__DOT__c_bus  = &TOP__top__DOT__riscv_32i__DOT__c_bus;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__top__DOT__Bus.__Vconfigure(this, true);
    TOP__top__DOT__riscv_32i__DOT__c_bus.__Vconfigure(this, true);
}
