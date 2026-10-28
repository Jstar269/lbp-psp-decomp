/* LBPMATCH module=EBOOT.BIN start=0x0889a3a4 end=0x0889a3b0 symbol=FUN_0889a3a4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0889a168 (a sibling wrapper passes 1 first). */
extern void FUN_0889a168(int flag, unsigned int mask);

void FUN_0889a3a4(void)
{
  FUN_0889a168(0, 0xffff);
}
