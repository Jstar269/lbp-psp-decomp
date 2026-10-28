/* LBPMATCH module=EBOOT.BIN start=0x089da858 end=0x089da888 symbol=FUN_089da858 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Inner {
  char pad_00[0xa8];
  int unk_a8;
};

struct Obj {
  char pad_00[0x20];
  int unk_20;
  char pad_24[0x1c];
  struct Inner *unk_40;
};

extern int DAT_08bf03d8;
extern int FUN_089e3140();

/* Prefer the lookup through unk_20 when it is set; else read unk_a8 of unk_40 (0 when neither exists). */
int FUN_089da858(struct Obj *self)
{
  int result;

  result = 0;
  if (self->unk_20 != 0) {
    return FUN_089e3140(DAT_08bf03d8, self->unk_20);
  }
  if (self->unk_40 != 0) {
    result = self->unk_40->unk_a8;
  }
  return result;
}
