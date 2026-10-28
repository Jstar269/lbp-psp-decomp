/* LBPMATCH module=EBOOT.BIN start=0x08913e60 end=0x08913e7c symbol=FUN_08913e60 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
extern int FUN_08a9e4a4();

/* Stores `value` through `out` when given, then passes it on to FUN_08a9e4a4. */
void FUN_08913e60(unsigned int value, unsigned int unused, unsigned int *out)
{
  if (out != 0) {
    *out = value;
  }
  FUN_08a9e4a4(value, 0, 0);
  return;
}
