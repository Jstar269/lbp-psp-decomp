/* LBPMATCH module=EBOOT.BIN start=0x08b8b858 end=0x08b8b8a0 symbol=FUN_08b8b858 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_cowstr.h"

extern void FUN_08b8b6d8();

/* Returns data + offset, first calling FUN_08b8b6d8 when the count at -4 is not negative. */
char *FUN_08b8b858(struct Rd4dCowStr *str, int offset)
{
  char *data;

  data = str->data;
  if (-1 < RD4D_COWSTR_REP(data)->refcount) {
    FUN_08b8b6d8(str);
    data = str->data;
  }
  return data + offset;
}
