/* LBPMATCH module=EBOOT.BIN start=0x088c0b10 end=0x088c0b70 symbol=FUN_088c0b10 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd3b_vobject.h"

/* 12-byte record of a table that ends at the first record whose first word is 0. */
struct Entry {
  int unk_00;
  int unk_04;
  int unk_08;
};

/* Calls virtual slot 0x48 / 4 of `self` once per table entry, passing the entry's three words and a trailing 0. */
void FUN_088c0b10(struct VObj *self, struct Entry *table)
{
  struct Entry *entry;

  for (entry = table; (entry != 0 && (entry->unk_00 != 0)); entry = entry + 1) {
    self->vtable[0x48 / 4](self, entry->unk_00, entry->unk_04, entry->unk_08, 0);
  }
  return;
}
