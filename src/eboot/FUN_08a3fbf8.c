/* LBPMATCH module=EBOOT.BIN start=0x08a3fbf8 end=0x08a3fc3c symbol=FUN_08a3fbf8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_000[0x190];
  int unk_190;
};

extern void *FUN_08a10f1c();
extern void FUN_08a11998();
extern void FUN_08a346e0();

void FUN_08a3fbf8(struct Obj *self, unsigned char flag)
{
  void *other;

  other = FUN_08a10f1c();
  FUN_08a11998(other, self->unk_190);
  FUN_08a346e0(self, flag);
  return;
}
