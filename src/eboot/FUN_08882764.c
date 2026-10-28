/* LBPMATCH module=EBOOT.BIN start=0x08882764 end=0x08882770 symbol=FUN_08882764 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Returns the address of the global object at 0x08bedfe0 (type unknown). */
extern unsigned char DAT_08bedfe0;

unsigned char *FUN_08882764(void)
{
  return &DAT_08bedfe0;
}
