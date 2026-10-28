/* LBPMATCH module=EBOOT.BIN start=0x089f62cc end=0x089f6314 symbol=FUN_089f62cc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_0897f480();
extern void FUN_08a9bff8();
extern int *FUN_08a9d390();

struct Resetter {
  char unk_00[0x14];
  unsigned char flag_14;
  char unk_15[0xf];
  int unk_24;
  int unk_28;
};

void FUN_089f62cc(struct Resetter *self)
{
  int scratch [8];

  self->flag_14 = 0;
  FUN_08a9d390(scratch,0xffffffff);
  FUN_08a9bff8(scratch);
  self->unk_24 = 0xffffffff;
  FUN_0897f480(self->unk_28);
  return;
}
