/* LBPMATCH module=EBOOT.BIN start=0x0899e9a8 end=0x0899e9b8 symbol=FUN_0899e9a8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

extern void FUN_0899e898();

/* Forwards to FUN_0899e898 with an extra 0 argument before the flag. */
void FUN_0899e9a8(int a, int b, unsigned int c, int d, unsigned char flag)
{
  FUN_0899e898(a, b, c, d, 0, flag);
}
