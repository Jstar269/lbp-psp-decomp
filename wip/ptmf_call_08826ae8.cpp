/* LBPMATCH module=EBOOT.BIN start=0x08826ae8 end=0x08826b24 symbol=FUN_08826ae8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Target { virtual void f0(); };
typedef void (Target::*Pmf)();
struct Holder { int pad; Target *obj; Pmf pmf; };
extern "C" void FUN_08826ae8(Holder *h)
{
    (h->obj->*h->pmf)();
}
// NEAR 7 words (register allocation only: ours fn in v1, delta in a1/a2; retail fn a2, delta v1/a3).
// Tried: -O2 (worse), local copies, inline helper (d2 14 words, different shape), member func, int return, struct copy.
// near miss from lane lbp12c (unreviewed)
