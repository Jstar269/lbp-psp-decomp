/* LBPMATCH module=EBOOT.BIN start=0x0896f800 end=0x0896f828 symbol=FUN_0896f800 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Entry whose word at +0x10 is returned. */
struct Entry {
  char unk_00[0x10];
  unsigned int unk_10;
};

/* Object with a table of entry pointers at +0x38 and a signed index (-1 = none) at +0x3c. */
struct IndexedTable {
  char unk_00[0x38];
  struct Entry **entries;
  short index;
};

unsigned int FUN_0896f800(struct IndexedTable *self)
{
  struct Entry *entry;

  entry = (struct Entry *)0;
  if (self->index != -1) {
    entry = self->entries[self->index];
  }
  return entry->unk_10;
}
