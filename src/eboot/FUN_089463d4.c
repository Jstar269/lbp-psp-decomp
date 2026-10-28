/* LBPMATCH module=EBOOT.BIN start=0x089463d4 end=0x08946420 symbol=FUN_089463d4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x6b0];
  unsigned char unk_6b0;
  unsigned char unk_6b1;
  char pad_6b2[2];
  char unk_6b4[0x20];
  char unk_6d4[0x20];
  unsigned char unk_6f4;
};

extern void *memset(void *dst, int value, unsigned int count);

void FUN_089463d4(struct Obj *self)
{
  self->unk_6f4 = 1;
  self->unk_6b0 = 0;
  self->unk_6b1 = 0;
  memset(self->unk_6b4, 0, 0x20);
  memset(self->unk_6d4, 0, 0x20);
  return;
}
