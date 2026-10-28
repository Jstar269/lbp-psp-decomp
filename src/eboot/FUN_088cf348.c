/* LBPMATCH module=EBOOT.BIN start=0x088cf348 end=0x088cf36c symbol=FUN_088cf348 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
extern void *DAT_08beee0c;   /* global object pointer, also passed by FUN_088d4d00 to its helpers */
extern void FUN_088cf2e0();
extern void FUN_088ea660();

void FUN_088cf348(void)
{
  FUN_088ea660(DAT_08beee0c);
  FUN_088cf2e0();
}
