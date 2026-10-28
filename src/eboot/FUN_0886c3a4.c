/* LBPMATCH module=EBOOT.BIN start=0x0886c3a4 end=0x0886c3b0 symbol=FUN_0886c3a4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0886c2dc (a sibling wrapper passes 0 first). */
extern void FUN_0886c2dc(int flag, unsigned int mask);

void FUN_0886c3a4(void)
{
  FUN_0886c2dc(1, 0xffff);
}
