/* LBPMATCH module=EBOOT.BIN start=0x0896fbd4 end=0x0896fc44 symbol=FUN_0896fbd4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_refobj.h"

struct SlotOwner {
  char unk_00[0x2c];
  int slots[1];        /* +0x2c: array of objects handed to FUN_08978ef0 */
};

extern void FUN_08970b6c();     /* drops one reference */
extern void FUN_08978190();     /* (entry, &handle_copy) */
extern int FUN_08978ef0();      /* (slot object, index) -> entry */

/* Looks up entry `index` of slot `slot` and hands it a counted copy of *handle. */
void FUN_0896fbd4(struct SlotOwner *self, struct RefCounted **handle, int slot, int index)
{
  int entry;
  struct RefCounted *copy[4];

  entry = FUN_08978ef0(self->slots[slot], index);
  copy[0] = *handle;
  if (copy[0] != 0) {
    copy[0]->ref_count = copy[0]->ref_count + 1;
  }
  FUN_08978190(entry, copy);
  if (copy[0] != 0) {
    FUN_08970b6c(copy[0]);
  }
}
