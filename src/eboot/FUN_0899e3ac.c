/* LBPMATCH module=EBOOT.BIN start=0x0899e3ac end=0x0899e3bc symbol=FUN_0899e3ac lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x14];
  int unk_14;
  int unk_18;
};

extern int *FUN_0899e2f4();

void FUN_0899e3ac(struct Obj *self, int value, int *arg)
{
  self->unk_14 = value;
  FUN_0899e2f4(&self->unk_18, arg);
  return;
}
