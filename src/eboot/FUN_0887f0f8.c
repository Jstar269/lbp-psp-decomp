/* LBPMATCH module=EBOOT.BIN start=0x0887f0f8 end=0x0887f120 symbol=FUN_0887f0f8 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Entry {
  unsigned char unk_00;
  char unk_01[0x33];
};

struct Table {
  char unk_00[0x28];
  unsigned char unk_28;
  char unk_29[0x57f];
  struct Entry entries_5a8[1];
};

/* Clears the first byte of entry `index` (entries are 0x34 bytes from +0x5a8) and the byte at +0x28; returns 1. */
int FUN_0887f0f8(struct Table *self, int index)
{
  self->entries_5a8[index].unk_00 = 0;
  self->unk_28 = 0;
  return 1;
}
