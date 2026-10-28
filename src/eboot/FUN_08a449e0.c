/* LBPMATCH module=EBOOT.BIN start=0x08a449e0 end=0x08a44a3c symbol=FUN_08a449e0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_wordvec.h"

extern unsigned int *FUN_08b9e8cc();  /* (dest, src, byte count): moves the tail down */

/* Erases the element at pos by moving the tail down one slot; returns pos. */
unsigned int *FUN_08a449e0(struct WordVec *vec, unsigned int *pos)
{
  unsigned int *next;
  unsigned int *end;

  next = pos + 1;
  end = vec->end;
  if (next != end) {
    FUN_08b9e8cc(pos, next, (int)end - (int)next);
    end = vec->end;
  }
  vec->end = end - 1;
  return pos;
}
