/* LBPMATCH module=EBOOT.BIN start=0x08823750 end=0x0882378c symbol=FUN_08823750 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern int FUN_08823238();    /* erase [first, last) */
extern void FUN_08823500();   /* insert count copies of *fill at pos */

/* vector<u32>::resize(new_size, &fill): shrink by erasing the tail, grow by appending copies. */
void FUN_08823750(struct U32Vector *vec, unsigned int new_size, unsigned int *fill)
{
  unsigned int *end = vec->end;
  unsigned int size = end - vec->begin;

  if (new_size < size) {
    FUN_08823238(vec, vec->begin + new_size, end);
    return;
  }
  FUN_08823500(vec, end, new_size - size, fill);
}
