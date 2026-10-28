/* LBPMATCH module=EBOOT.BIN start=0x089e5b6c end=0x089e5b94 symbol=FUN_089e5b6c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_uintpair.h"

/* Lexicographic "a < b" on two (first, second) word pairs. */
_Bool FUN_089e5b6c(struct Rd4cUIntPair *a, struct Rd4cUIntPair *b)
{
  _Bool less;

  less = a->first < b->first;
  if (a->first == b->first) {
    less = a->second < b->second;
  }
  return less;
}
