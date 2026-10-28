/* LBPMATCH module=EBOOT.BIN start=0x0881a520 end=0x0881a530 symbol=FUN_0881a520 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_modeobj.h"

/* Stores the two words at +0x1a8 and +0x1ac, then calls FUN_0881a260 with 0. */
extern void FUN_0881a260();

void FUN_0881a520(struct Rd3dModeOwner *self, unsigned int value_a, unsigned int value_b)
{
  self->value_1a8 = value_a;
  self->value_1ac = value_b;
  FUN_0881a260(self, '\0');
  return;
}
