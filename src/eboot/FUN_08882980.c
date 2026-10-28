/* LBPMATCH module=EBOOT.BIN start=0x08882980 end=0x088829a0 symbol=FUN_08882980 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern void *DAT_08bee030;
extern void FUN_0888a4d0(void *arg);

/* Calls FUN_0888a4d0 on DAT_08bee030 when it is set. */
void FUN_08882980(void)
{
  if (DAT_08bee030 != 0) {
    FUN_0888a4d0(DAT_08bee030);
    return;
  }
  return;
}
