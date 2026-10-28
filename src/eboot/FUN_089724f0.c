/* LBPMATCH module=EBOOT.BIN start=0x089724f0 end=0x089725a4 symbol=FUN_089724f0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_reltable.h"

extern void FUN_088ec728();
extern int FUN_0891d6e4();
extern void *FUN_08971a00();

/* Fills out: FUN_088ec728(out, 0) when owner has no holder_a, otherwise FUN_08971a00 with the
   short* found at base + table[index + 1]. Returns out. */
void *FUN_089724f0(void *out, struct RelTableOwner *owner, int index, unsigned int arg4, void *arg5)
{
  int table;
  int base;

  if (owner->holder_a == 0) {
    FUN_088ec728(out, 0);
  }
  else {
    table = FUN_0891d6e4(owner->holder_a->table_ptr);
    base = FUN_0891d6e4(owner->holder_a->table_ptr);
    FUN_08971a00(out, owner, (short *)(base + ((int *)table)[index + 1]), arg4, arg5);
  }
  return out;
}
