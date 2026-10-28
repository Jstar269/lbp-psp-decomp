/* LBPMATCH module=EBOOT.BIN start=0x08b94ae8 end=0x08b94b18 symbol=FUN_08b94ae8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern unsigned int **FUN_08b8cf80();

unsigned int FUN_08b94ae8(void)
{
  unsigned int **slot;
  unsigned int value;

  slot = FUN_08b8cf80();
  value = 0;
  if (*slot != (unsigned int *)0x0) {
    value = **slot;
  }
  return value;
}
