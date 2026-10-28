/* LBPMATCH module=EBOOT.BIN start=0x0886c860 end=0x0886c86c symbol=FUN_0886c860 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0886c79c (a sibling wrapper passes 1 first). */
extern void FUN_0886c79c(int flag, unsigned int mask);

void FUN_0886c860(void)
{
  FUN_0886c79c(0, 0xffff);
}
