/* LBPMATCH module=EBOOT.BIN start=0x08898558 end=0x088985c4 symbol=FUN_08898558 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_locked.h"

extern void FUN_0888b8c4();
extern void FUN_0888b8cc();
extern int *FUN_08898480();

/* Returns `out` after running FUN_08898480 between the +0x2c member's two bracketing calls. */
int *FUN_08898558(int *out, struct Rd4dLocked2c *self, int *arg)
{
  FUN_0888b8c4(&self->unk_2c);
  FUN_08898480(out, self, arg, 1);
  FUN_0888b8cc(&self->unk_2c);
  return out;
}
