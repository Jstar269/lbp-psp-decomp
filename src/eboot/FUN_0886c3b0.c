/* LBPMATCH module=EBOOT.BIN start=0x0886c3b0 end=0x0886c3bc symbol=FUN_0886c3b0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0886c2dc (a sibling wrapper passes 1 first). */
extern void FUN_0886c2dc(int flag, unsigned int mask);

void FUN_0886c3b0(void)
{
  FUN_0886c2dc(0, 0xffff);
}
