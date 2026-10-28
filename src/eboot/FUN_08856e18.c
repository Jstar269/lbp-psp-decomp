/* LBPMATCH module=EBOOT.BIN start=0x08856e18 end=0x08856e5c symbol=FUN_08856e18 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern int FUN_08878ea8();

/* Object with a state value at +0xc8. */
struct Stateful {
  char unk_00[0xc8];
  int unk_c8;
};

int FUN_08856e18(struct Stateful *self)
{
  int available;
  int result;

  available = FUN_08878ea8();
  result = 1;
  if ((available == 0) || (self->unk_c8 == 5)) {
    result = 0;
  }
  return result;
}
