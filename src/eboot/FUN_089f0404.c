/* LBPMATCH module=EBOOT.BIN start=0x089f0404 end=0x089f045c symbol=FUN_089f0404 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_vobject.h"

struct Context {
  char pad[0x28];
  struct VObject *target;   /* +0x28 */
};

extern int FUN_089f19c0();
extern void FUN_089f1a64();

/* Calls virtual slot 4 of the context's target, bracketed by the FUN_089f1a64 / FUN_089f19c0 pair (both given 0x1b). */
int FUN_089f0404(void *unused, int arg, struct Context *ctx)
{
  int result;

  FUN_089f1a64(0x1b);
  result = ((int (*)(struct VObject *, int))ctx->target->vtable[4])(ctx->target, arg);
  FUN_089f19c0(27);
  return result;
}
