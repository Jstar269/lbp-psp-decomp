/* LBPMATCH module=EBOOT.BIN start=0x089c8794 end=0x089c8804 symbol=FUN_089c8794 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_slotstack.h"

extern void FUN_088cc71c();
extern void FUN_0897633c();
extern void FUN_089d1dfc();
extern void FUN_089d299c();

void FUN_089c8794(struct SlotOwner *self, short *arg)
{
  struct Slot *slot;
  unsigned int tmp_a[2];
  int tmp_b[2];

  slot = self->set->slots[7 - self->set->used];
  FUN_0897633c(tmp_a, arg);
  FUN_089d1dfc(slot, tmp_a, 0);
  FUN_088cc71c(tmp_b);
  FUN_089d299c(slot, slot->unk_10, 0, 0);
}
