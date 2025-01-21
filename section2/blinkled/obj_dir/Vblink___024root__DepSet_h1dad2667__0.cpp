// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblink.h for the primary calling header

#include "verilated.h"

#include "Vblink___024root.h"

void Vblink___024root___eval_act(Vblink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vblink___024root___nba_sequent__TOP__0(Vblink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*20:0*/ __Vdly__blink__DOT__cnt;
    __Vdly__blink__DOT__cnt = 0;
    // Body
    __Vdly__blink__DOT__cnt = vlSelf->blink__DOT__cnt;
    __Vdly__blink__DOT__cnt = (0x1fffffU & ((IData)(1U) 
                                            + vlSelf->blink__DOT__cnt));
    vlSelf->led = (1U & (vlSelf->blink__DOT__cnt >> 0x14U));
    vlSelf->blink__DOT__cnt = __Vdly__blink__DOT__cnt;
}

void Vblink___024root___eval_nba(Vblink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vblink___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vblink___024root___eval_triggers__act(Vblink___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vblink___024root___dump_triggers__act(Vblink___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vblink___024root___dump_triggers__nba(Vblink___024root* vlSelf);
#endif  // VL_DEBUG

void Vblink___024root___eval(Vblink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vblink___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vblink___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("blink.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vblink___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vblink___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("blink.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vblink___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vblink___024root___eval_debug_assertions(Vblink___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vblink__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblink___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
