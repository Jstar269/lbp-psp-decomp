/* LBPMATCH module=EBOOT.BIN start=0x08906d5c end=0x08906d68 symbol=FUN_08906d5c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08906be8 (a sibling wrapper passes 1 first). */
extern void FUN_08906be8(int flag, unsigned int mask);

void FUN_08906d5c(void)
{
  FUN_08906be8(0, 0xffff);
}
