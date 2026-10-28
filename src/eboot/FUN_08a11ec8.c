/* LBPMATCH module=EBOOT.BIN start=0x08a11ec8 end=0x08a11f34 symbol=FUN_08a11ec8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Entry {
  char pad_00[0x5c];
  int unk_5c;
};

extern void FUN_08a11998(void *self, struct Entry *entry);
extern void FUN_08a11e24(void *self, struct Entry *entry);

/* Changes the word at +0x5c of `entry`, calling FUN_08a11998 before and FUN_08a11e24 after the change. */
void FUN_08a11ec8(void *self, struct Entry *entry, int new_value)
{
  if (entry->unk_5c != new_value) {
    FUN_08a11998(self, entry);
    entry->unk_5c = new_value;
    FUN_08a11e24(self, entry);
    return;
  }
  return;
}
