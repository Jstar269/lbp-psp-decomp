/* LBPMATCH module=EBOOT.BIN start=0x08804770 end=0x0880477c symbol=FUN_08804770 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08804508 (a sibling wrapper passes 0 first). */
extern void FUN_08804508(int flag, unsigned int mask);

void FUN_08804770(void)
{
  FUN_08804508(1, 0xffff);
}
