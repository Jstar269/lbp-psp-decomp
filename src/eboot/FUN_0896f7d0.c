/* LBPMATCH module=EBOOT.BIN start=0x0896f7d0 end=0x0896f800 symbol=FUN_0896f7d0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct SlotEntry {
  char pad_00[0xc];
  int value;
};

struct SlotTable {
  char pad_00[0x38];
  struct SlotEntry **entries;   /* indexed by `index` */
  short index;                  /* -1 = no entry selected */
};

int FUN_0896f7d0(struct SlotTable *self)
{
  struct SlotEntry *entry;
  int result;

  result = -1;
  if (self->index != -1 && (entry = self->entries[self->index], entry != 0)) {
    result = entry->value;
  }
  return result;
}
