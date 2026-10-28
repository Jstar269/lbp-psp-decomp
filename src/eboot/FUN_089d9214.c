/* LBPMATCH module=EBOOT.BIN start=0x089d9214 end=0x089d9260 symbol=FUN_089d9214 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#define FLAG_400 0x400

struct Obj {
  char unk_00[4];
  unsigned int flags_04;
  char unk_08[0x10];
  char unk_18;
  char unk_19[7];
  char *unk_20;
  char unk_24[0x90];
  char unk_b4;
};

extern void FUN_0896da10();
extern void FUN_089d91d4();

void FUN_089d9214(struct Obj *self)
{
  FUN_0896da10(&self->unk_b4);
  if (self->unk_20 == &self->unk_18) {
    FUN_089d91d4(self);
  }
  self->flags_04 = self->flags_04 | FLAG_400;
  return;
}
