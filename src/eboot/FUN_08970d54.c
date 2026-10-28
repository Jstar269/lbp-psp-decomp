/* LBPMATCH module=EBOOT.BIN start=0x08970d54 end=0x08970dbc symbol=FUN_08970d54 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_holder.h"

extern int FUN_0891d6e4();

/* Same as FUN_08970cec but through ref_2a8, and the table word is at base - 0x998 + index*4. */
int FUN_08970d54(struct HolderOwner *self, int index)
{
  int result;
  int base;

  result = 0;
  if (self->ref_2a8 != 0) {
    base = FUN_0891d6e4(self->ref_2a8->base_cell);
    result = FUN_0891d6e4(self->ref_2a8->base_cell);
    result = result + *(int *)(index * 4 + base - 0x998);
  }
  return result;
}
