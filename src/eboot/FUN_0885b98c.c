/* LBPMATCH module=EBOOT.BIN start=0x0885b98c end=0x0885b9d0 symbol=FUN_0885b98c lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int FUN_08878ea8();

/* Object with a state value at +0xc8. */
struct Stateful {
  char unk_00[0xc8];
  int unk_c8;
};

int FUN_0885b98c(struct Stateful *self)
{
  int available;
  int result;

  available = FUN_08878ea8();
  result = 1;
  if ((available == 0) || (self->unk_c8 == 1)) {
    result = 0;
  }
  return result;
}
