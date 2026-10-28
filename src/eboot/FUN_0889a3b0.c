/* LBPMATCH module=EBOOT.BIN start=0x0889a3b0 end=0x0889a3bc symbol=FUN_0889a3b0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0889a168 (a sibling wrapper passes 0 first). */
extern void FUN_0889a168(int flag, unsigned int mask);

void FUN_0889a3b0(void)
{
  FUN_0889a168(1, 0xffff);
}
