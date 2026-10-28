/* LBPMATCH module=EBOOT.BIN start=0x088d34e4 end=0x088d3510 symbol=FUN_088d34e4 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  unsigned int flags_00;
  char unk_04[0x34];
  unsigned int unk_38;
};

/* 1 unless one of the bits in 0xc00 is set or the word at +0x38 is below 0x1f5. */
int FUN_088d34e4(struct Obj *self)
{
  int result;

  result = 1;
  if (((self->flags_00 & 0xc00) != 0) || (self->unk_38 < 0x1f5)) {
    result = 0;
  }
  return result;
}
