/* LBPMATCH module=EBOOT.BIN start=0x08874b9c end=0x08874ba8 symbol=FUN_08874b9c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_088747dc (a sibling wrapper passes 0 first). */
extern void FUN_088747dc(int flag, unsigned int mask);

void FUN_08874b9c(void)
{
  FUN_088747dc(1, 0xffff);
}
