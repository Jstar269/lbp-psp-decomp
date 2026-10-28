/* LBPMATCH module=EBOOT.BIN start=0x08970cec end=0x08970d54 symbol=FUN_08970cec lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_holder.h"

extern int FUN_0891d6e4();

/* Returns the base value read through ref_2a4 plus a word looked up in the table at base+4 by index
   (0 when ref_2a4 is null). */
int FUN_08970cec(struct HolderOwner *self, int index)
{
  int result;
  int base;

  result = 0;
  if (self->ref_2a4 != 0) {
    base = FUN_0891d6e4(self->ref_2a4->base_cell);
    result = FUN_0891d6e4(self->ref_2a4->base_cell);
    result = result + *(int *)(index * 4 + base + 4);
  }
  return result;
}
