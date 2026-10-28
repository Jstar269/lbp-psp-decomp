/* LBPMATCH module=EBOOT.BIN start=0x088b6084 end=0x088b6094 symbol=FUN_088b6084 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
extern unsigned char DAT_08bee541;   /* one-byte flag, set here and never cleared by this function */

/* Raises the DAT_08bee541 flag. */
void FUN_088b6084(void)
{
  DAT_08bee541 = 1;
}
