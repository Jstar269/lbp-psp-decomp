/* LBPMATCH module=EBOOT.BIN start=0x0887cb4c end=0x0887cb6c symbol=FUN_0887cb4c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
extern int FUN_0887c93c();

/* True when FUN_0887c93c returns non-zero. */
unsigned char FUN_0887cb4c(int first, int *second, int third)
{
  int result;

  result = FUN_0887c93c(first, second, third);
  return result != 0;
}
