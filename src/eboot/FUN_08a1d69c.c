/* LBPMATCH module=EBOOT.BIN start=0x08a1d69c end=0x08a1d6d0 symbol=FUN_08a1d69c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0xa8];
  void *unk_a8;
  int unk_ac;
};

extern int FUN_08a1d514(void *arg0, unsigned char arg1);

int FUN_08a1d69c(struct Obj *self, unsigned char arg)
{
  int base;
  int extra;

  base = self->unk_ac;
  extra = FUN_08a1d514(self->unk_a8, arg);
  return base + extra;
}
