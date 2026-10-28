/* LBPMATCH module=EBOOT.BIN start=0x089e06b0 end=0x089e0714 symbol=FUN_089e06b0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Pair {
  char unk_00[0xc];
  void *unk_0c;          /* +0xc: optional */
  void *unk_10;          /* +0x10: optional */
};

extern void FUN_0896aeec();

/* Applies FUN_0896aeec to each non-null member (+0x10 first, then +0xc) with the same argument. */
void FUN_089e06b0(struct Pair *self, int arg)
{
  if (self->unk_10 != 0) {
    FUN_0896aeec(self->unk_10, arg);
  }
  if (self->unk_0c != 0) {
    FUN_0896aeec(self->unk_0c, arg);
  }
}
