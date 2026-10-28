/* LBPMATCH module=EBOOT.BIN start=0x0896ed78 end=0x0896eda4 symbol=FUN_0896ed78 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Slots {
  char pad[0x20];
  int unk_20[3];
  int unk_2c[3];
};

/* Returns 1 when entry index is set in both of the two parallel arrays (+0x20 and +0x2c). */
int FUN_0896ed78(struct Slots *self, int index)
{
  int result;

  result = 1;
  if ((self->unk_20[index] == 0) || (self->unk_2c[index] == 0)) {
    result = 0;
  }
  return result;
}
