/* LBPMATCH module=EBOOT.BIN start=0x0889addc end=0x0889ae38 symbol=FUN_0889addc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern unsigned int *FUN_08b9e8cc();   /* memmove(dst, src, byte_count) */

/* vector<u32>::erase(pos): close the gap by moving the tail down one element; returns pos. */
unsigned int *FUN_0889addc(struct U32Vector *vec, unsigned int *pos)
{
  unsigned int *next = pos + 1;

  if (next != vec->end) {
    FUN_08b9e8cc(pos, next, (char *)vec->end - (char *)next);
  }
  vec->end = vec->end - 1;
  return pos;
}
