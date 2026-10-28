/* LBPMATCH module=EBOOT.BIN start=0x08885bc4 end=0x08885c30 symbol=FUN_08885bc4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_locked.h"

extern int *FUN_08885aec();
extern void FUN_0888b8c4();
extern void FUN_0888b8cc();

/* Returns `out` after running FUN_08885aec between the +0x30 member's two bracketing calls. */
int *FUN_08885bc4(int *out, struct Rd4dLocked30 *self, int *arg)
{
  FUN_0888b8c4(&self->unk_30);
  FUN_08885aec(out, self, arg, 1);
  FUN_0888b8cc(&self->unk_30);
  return out;
}
