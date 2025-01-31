// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vblink.h for the primary calling header

#ifndef VERILATED_VBLINK___024ROOT_H_
#define VERILATED_VBLINK___024ROOT_H_  // guard

#include "verilated.h"

class Vblink__Syms;

class Vblink___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_OUT8(led,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    IData/*20:0*/ blink__DOT__cnt;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vblink__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vblink___024root(Vblink__Syms* symsp, const char* v__name);
    ~Vblink___024root();
    VL_UNCOPYABLE(Vblink___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
