/* LBPMATCH module=EBOOT.BIN start=0x089d2d74 end=0x089d2d90 symbol=FUN_089d2d74 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x20];
  int unk_20;
  int unk_24;
};

/* Stores `value` at +0x20 when `flag` is set, else at +0x24. */
void FUN_089d2d74(struct Obj *self, int value, unsigned char flag)
{
  if (flag != 0) {
    self->unk_20 = value;
    return;
  }
  self->unk_24 = value;
  return;
}
