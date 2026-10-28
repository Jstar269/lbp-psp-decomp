/* LBPMATCH module=EBOOT.BIN start=0x089e53a0 end=0x089e53c8 symbol=FUN_089e53a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_slottable.h"

/* Passes the record in slot `slot_index` and `arg` to FUN_0898e190, or returns -1 when the slot is empty. */
extern int FUN_0898e190();

int FUN_089e53a0(struct Rd3dSlotTable *self, int slot_index, unsigned int arg)
{
  struct Rd3dSlotRecord *record;
  int result;

  record = self->slots[slot_index].record;
  if (record != (struct Rd3dSlotRecord *)0x0) {
    result = FUN_0898e190(record, arg);
    return result;
  }
  return -1;
}
