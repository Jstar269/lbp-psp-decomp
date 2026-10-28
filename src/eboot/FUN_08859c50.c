/* LBPMATCH module=EBOOT.BIN start=0x08859c50 end=0x08859c80 symbol=FUN_08859c50 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x19c];
  unsigned char unk_19c;
  unsigned char unk_19d;
  unsigned char unk_19e;
};

/* 0 only when all three flags at +0x19c..+0x19e are set. */
unsigned int FUN_08859c50(struct Obj *self)
{
  unsigned int all_set;

  all_set = 0;
  if ((self->unk_19c != 0) && ((all_set = 1, self->unk_19d == 0 || (self->unk_19e == 0)))) {
    all_set = 0;
  }
  return all_set ^ 1;
}
