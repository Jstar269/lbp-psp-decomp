/* LBPMATCH module=EBOOT.BIN start=0x088a09a0 end=0x088a09c8 symbol=FUN_088a09a0 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Returns 1 when `*ref` is non-null and its words at +0x10 and +0xc are equal, else 0. */
struct TwoWords {
  char pad[0xc];
  int unk_0c;
  int unk_10;
};

unsigned int FUN_088a09a0(struct TwoWords **ref)
{
  struct TwoWords *target;
  unsigned int result;

  target = *ref;
  result = 1;
  if ((target == (struct TwoWords *)0) || (target->unk_10 != target->unk_0c)) {
    result = 0;
  }
  return result;
}
