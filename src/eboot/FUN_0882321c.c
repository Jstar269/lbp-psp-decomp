/* LBPMATCH module=EBOOT.BIN start=0x0882321c end=0x08823238 symbol=FUN_0882321c lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct CounterSet {
  char unk_00[0xc];
  int *values;           /* +0xc */
};

/* values[index] += delta */
void FUN_0882321c(struct CounterSet *self, int index, int delta)
{
  int *slot;

  slot = &self->values[index];
  *slot = *slot + delta;
}
