/* LBPMATCH module=EBOOT.BIN start=0x08b8b818 end=0x08b8b858 symbol=FUN_08b8b818 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_cowstr.h"

extern void FUN_08b8b6d8();

/* Returns data + length (one past the last character), after the same unshare step as FUN_08b8b858. */
char *FUN_08b8b818(struct Rd4dCowStr *str)
{
  char *data;

  data = str->data;
  if (-1 < RD4D_COWSTR_REP(data)->refcount) {
    FUN_08b8b6d8(str);
    data = str->data;
  }
  return data + RD4D_COWSTR_REP(data)->length;
}
