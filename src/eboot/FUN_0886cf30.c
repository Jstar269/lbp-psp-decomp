/* LBPMATCH module=EBOOT.BIN start=0x0886cf30 end=0x0886cf3c symbol=FUN_0886cf30 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0886ce6c (a sibling wrapper passes 1 first). */
extern void FUN_0886ce6c(int flag, unsigned int mask);

void FUN_0886cf30(void)
{
  FUN_0886ce6c(0, 0xffff);
}
