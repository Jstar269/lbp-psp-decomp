/* LBPMATCH module=EBOOT.BIN start=0x089725a4 end=0x0897265c symbol=FUN_089725a4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_reltable.h"

#define INDEX_BIAS 0x266   /* the table word read is at byte offset index*4 - 0x998 */

extern void FUN_088ec728();
extern int FUN_0891d6e4();
extern void *FUN_08971a00();

/* Same as FUN_089724f0 but reads through holder_b and a biased index. The guard tests holder_a
   while the lookup uses holder_b, exactly as retail does. */
void *FUN_089725a4(void *out, struct RelTableOwner *owner, int index, unsigned int arg4, void *arg5)
{
  int table;
  int base;

  if (owner->holder_a == 0) {
    FUN_088ec728(out, 0);
  }
  else {
    table = FUN_0891d6e4(owner->holder_b->table_ptr);
    base = FUN_0891d6e4(owner->holder_b->table_ptr);
    FUN_08971a00(out, owner, (short *)(base + ((int *)table)[index - INDEX_BIAS]), arg4, arg5);
  }
  return out;
}
