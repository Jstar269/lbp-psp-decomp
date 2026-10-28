/* LBPMATCH module=EBOOT.BIN start=0x08b8b78c end=0x08b8b7dc symbol=FUN_08b8b78c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_cowstring.h"

extern void FUN_08b8b6d8();

/* Stores the string's character pointer in *out, first calling FUN_08b8b6d8 when its reference
   count (data[-4]) is not negative. */
struct Rd4cCowString *FUN_08b8b78c(struct Rd4cCowString *out, struct Rd4cCowString *str)
{
  char *data;

  data = str->data;
  if (-1 < ((int *)data)[-1]) {
    FUN_08b8b6d8(str);
    data = str->data;
  }
  out->data = data;
  return out;
}
