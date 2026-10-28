/* LBPMATCH module=EBOOT.BIN start=0x08954ca4 end=0x08954cc4 symbol=FUN_08954ca4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
struct CountedRec {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  int count;             /* +0xc: bumped on every call */
  unsigned int value;    /* +0x10 */
  unsigned int unk_14;
};

/* Stores a new value, bumps the counter, copies unk_04 into unk_08 and clears unk_14. */
void FUN_08954ca4(struct CountedRec *self, unsigned int value)
{
  self->value = value;
  self->count = self->count + 1;
  self->unk_08 = self->unk_04;
  self->unk_14 = 0;
}
