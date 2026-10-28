/* LBPMATCH module=EBOOT.BIN start=0x0889b58c end=0x0889b5b4 symbol=FUN_0889b58c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
extern void FUN_0889b0e8();
extern void FUN_0889b3fc();

/* Calls two helpers on the same object, in this order. */
void FUN_0889b58c(void *self)
{
  FUN_0889b0e8(self);
  FUN_0889b3fc(self);
  return;
}
