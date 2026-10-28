/* LBPMATCH module=EBOOT.BIN start=0x0898abbc end=0x0898abc8 symbol=FUN_0898abbc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0898ab94 (a sibling wrapper passes 0 first). */
extern void FUN_0898ab94(int flag, unsigned int mask);

void FUN_0898abbc(void)
{
  FUN_0898ab94(1, 0xffff);
}
