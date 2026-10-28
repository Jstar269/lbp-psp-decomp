/* LBPMATCH module=EBOOT.BIN start=0x0896fc44 end=0x0896fcb8 symbol=FUN_0896fc44 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_refobj.h"
#include "lbp/rd2a_entrytable.h"


extern void FUN_08970b6c();     /* drops one reference */
extern void FUN_08978190();     /* (entry, &handle_copy) */

/* If an entry is selected and non-null, hands it a counted copy of *handle. */
void FUN_0896fc44(struct EntryTable *self, struct RefCounted **handle)
{
  int entry;
  struct RefCounted *copy[4];

  if (self->current != -1 && (entry = self->entries[self->current]) != 0) {
    copy[0] = *handle;
    if (copy[0] != 0) {
      copy[0]->ref_count = copy[0]->ref_count + 1;
    }
    FUN_08978190(entry, copy);
    if (copy[0] != 0) {
      FUN_08970b6c(copy[0]);
    }
  }
}
