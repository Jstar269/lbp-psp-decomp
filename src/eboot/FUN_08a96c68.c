/* LBPMATCH module=EBOOT.BIN start=0x08a96c68 end=0x08a96c90 symbol=FUN_08a96c68 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_unkcc.h"

extern void FUN_08a9493c();

void FUN_08a96c68(struct Rd4dObjCC *self, unsigned char (*block16)[16], unsigned char (*block64)[64])
{
  FUN_08a9493c(self, block16, block64);
  self->unk_cc = 0;
  return;
}
