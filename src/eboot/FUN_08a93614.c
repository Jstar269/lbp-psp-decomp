/* LBPMATCH module=EBOOT.BIN start=0x08a93614 end=0x08a93648 symbol=FUN_08a93614 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
/* Two floats at +0xc4 / +0xc8: result is 1 when the one at +0xc8 is non-zero and the one at +0xc4 is positive. */
struct FloatObj {
  char unk_00[0xc4];
  float unk_c4;
  float unk_c8;
};

int FUN_08a93614(struct FloatObj *self)
{
  int result;

  result = 0;
  if ((self->unk_c8 != 0.0f) && (0.0f < self->unk_c4)) {
    result = 1;
  }
  return result;
}
