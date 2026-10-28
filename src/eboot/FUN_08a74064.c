/* LBPMATCH module=EBOOT.BIN start=0x08a74064 end=0x08a740d4 symbol=FUN_08a74064 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08a10024();
extern void FUN_08a10118();
extern void FUN_08a12208();

/* Object whose word at +0xa8 starts with a flags word. */
struct Flagged {
  unsigned int flags;
};

struct Updater {
  char unk_00[0x50];
  char block_50[0x54];
  int *unk_a4;
  struct Flagged *flagged;
};

void FUN_08a74064(struct Updater *self)
{
  FUN_08a12208(self->unk_a4,self->block_50);
  if ((self->flagged->flags & 0x40) != 0) {
    return;
  }
  FUN_08a10118(self->flagged,self->block_50);
  FUN_08a10024(self->flagged);
  return;
}
