/* LBPMATCH module=EBOOT.BIN start=0x089e5380 end=0x089e53a0 symbol=FUN_089e5380 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_slottable.h"

/* Returns the value field of the record in slot `slot_index`, or -1 when the slot is empty. */
unsigned int FUN_089e5380(struct Rd3dSlotTable *self, int slot_index)
{
  struct Rd3dSlotRecord *record;
  unsigned int result;

  record = self->slots[slot_index].record;
  result = 0xffffffff;
  if (record != (struct Rd3dSlotRecord *)0x0) {
    result = record->value;
  }
  return result;
}
