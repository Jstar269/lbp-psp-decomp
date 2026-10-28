/* LBPMATCH module=EBOOT.BIN start=0x0889a630 end=0x0889a650 symbol=FUN_0889a630 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern int * FUN_0889bc4c();
extern void FUN_0889bd64();

void FUN_0889a630(void)
{
  int *obj;

  obj = FUN_0889bc4c();
  FUN_0889bd64(obj);
  return;
}
