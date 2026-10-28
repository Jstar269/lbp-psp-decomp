/* LBPMATCH module=EBOOT.BIN start=0x0888c19c end=0x0888c1a8 symbol=FUN_0888c19c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0888c0d4 (a sibling wrapper passes 0 first). */
extern void FUN_0888c0d4(int flag, unsigned int mask);

void FUN_0888c19c(void)
{
  FUN_0888c0d4(1, 0xffff);
}
