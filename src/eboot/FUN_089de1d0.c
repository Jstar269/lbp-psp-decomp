/* LBPMATCH module=EBOOT.BIN start=0x089de1d0 end=0x089de1e0 symbol=FUN_089de1d0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
/* Same as FUN_089de1c0 with the two output pointers swapped in the argument list. */
void FUN_089de1d0(int first, int second, int *out_negated, int *out_copy)
{
  *out_copy = second;
  *out_negated = -first;
  return;
}
