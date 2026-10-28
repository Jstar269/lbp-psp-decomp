/* LBPMATCH module=EBOOT.BIN start=0x08a0b560 end=0x08a0b588 symbol=FUN_08a0b560 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_cleared88.h"

extern void FUN_08a0b368();

/* Delegates to FUN_08a0b368, then clears the word at +0x88. */
void FUN_08a0b560(struct Rd4cCleared88 *self, unsigned char (*block16)[16], unsigned char (*block64)[64])
{
  FUN_08a0b368(self, block16, block64);
  self->unk_88 = 0;
}
