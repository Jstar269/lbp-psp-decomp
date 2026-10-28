/* LBPMATCH module=EBOOT.BIN start=0x0889eb88 end=0x0889ebc4 symbol=FUN_0889eb88 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern void FUN_0889d4d4();   /* erase [first, last) */
extern void FUN_0889e908();   /* insert count copies of *fill at pos */

/* vector<u32>::resize(new_size, &fill): shrink by erasing the tail, grow by appending copies. */
void FUN_0889eb88(struct U32Vector *vec, unsigned int new_size, unsigned int *fill)
{
  unsigned int *end = vec->end;
  unsigned int size = end - vec->begin;

  if (new_size < size) {
    FUN_0889d4d4(vec, vec->begin + new_size, end);
    return;
  }
  FUN_0889e908(vec, end, new_size - size, fill);
}
