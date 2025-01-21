// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VBLINK__SYMS_H_
#define VERILATED_VBLINK__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vblink.h"

// INCLUDE MODULE CLASSES
#include "Vblink___024root.h"

// SYMS CLASS (contains all model state)
class Vblink__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vblink* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vblink___024root               TOP;

    // CONSTRUCTORS
    Vblink__Syms(VerilatedContext* contextp, const char* namep, Vblink* modelp);
    ~Vblink__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
