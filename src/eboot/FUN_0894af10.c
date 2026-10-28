/* LBPMATCH module=EBOOT.BIN start=0x0894af10 end=0x0894af44 symbol=FUN_0894af10 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern int FUN_0894a878();    /* erase [first, last) */
extern void FUN_0894ad08();   /* insert count copies of *fill at pos */

/* vector<u8>::resize(new_size, &fill): shrink by erasing the tail, grow by appending copies. */
void FUN_0894af10(struct U8Vector *vec, unsigned int new_size, unsigned char *fill)
{
  unsigned char *end = vec->end;
  unsigned int size = end - vec->begin;

  if (new_size < size) {
    FUN_0894a878(vec, vec->begin + new_size, end);
    return;
  }
  FUN_0894ad08(vec, end, new_size - size, fill);
}
