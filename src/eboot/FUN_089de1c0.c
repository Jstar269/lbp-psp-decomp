/* LBPMATCH module=EBOOT.BIN start=0x089de1c0 end=0x089de1d0 symbol=FUN_089de1c0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
/* Stores `second` through out_copy and the negation of `first` through out_negated. */
void FUN_089de1c0(int first, int second, int *out_copy, int *out_negated)
{
  *out_negated = -first;
  *out_copy = second;
  return;
}
