/* LBPMATCH module=EBOOT.BIN start=0x0888b860 end=0x0888b898 symbol=FUN_0888b860 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x10];
  int unk_10;
};

extern void FUN_08ad27d0();
extern void FUN_08ad27f4();
extern void FUN_08ad2b0c();

void FUN_0888b860(struct Obj *self)
{
  FUN_08ad27d0(self);
  FUN_08ad27f4(self, 2);
  FUN_08ad2b0c(&self->unk_10, self);
  return;
}
