/* LBPMATCH module=EBOOT.BIN start=0x089ce33c end=0x089ce348 symbol=FUN_089ce33c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089ce314 (a sibling wrapper passes 0 first). */
extern void FUN_089ce314(int flag, unsigned int mask);

void FUN_089ce33c(void)
{
  FUN_089ce314(1, 0xffff);
}
