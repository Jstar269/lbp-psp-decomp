/* LBPMATCH module=EBOOT.BIN start=0x08a9a974 end=0x08a9a9d0 symbol=FUN_08a9a974 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd2a_vector.h"

extern int FUN_08a9a924();

/* Removes the element at pos: shifts the tail down by one and shrinks the vector; returns pos. */
unsigned int * FUN_08a9a974(struct U32Vector *vec,unsigned int *pos)
{
  if (pos + 1 != vec->end) {
    FUN_08a9a924(pos + 1,vec->end,pos);
  }
  vec->end = vec->end + -1;
  return pos;
}
