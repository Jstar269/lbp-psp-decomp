/* LBPMATCH module=EBOOT.BIN start=0x08b8b6b8 end=0x08b8b6c4 symbol=FUN_08b8b6b8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_cowstr.h"

extern void FUN_08b8b470();

void FUN_08b8b6b8(int *dest, unsigned int pos, struct Rd4dCowStr *src)
{
  FUN_08b8b470(dest, pos, src->data, RD4D_COWSTR_REP(src->data)->length);
  return;
}
