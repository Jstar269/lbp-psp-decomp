/* LBPMATCH module=EBOOT.BIN start=0x0898e428 end=0x0898e46c symbol=FUN_0898e428 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[4];
  int unk_04;
  int unk_08;
  char unk_0c[0x14];
  int unk_20;
  char unk_24[0x18];
  int unk_3c;
  char unk_40[0x18];
  int unk_58;
};

extern void FUN_08921858();
extern void FUN_08a9c6b0();

void FUN_0898e428(struct Obj *self)
{
  self->unk_58 = 0;
  FUN_08921858(&self->unk_20);
  FUN_08921858(&self->unk_3c);
  FUN_08a9c6b0(&self->unk_08, 1);
  self->unk_04 = 0;
  return;
}
