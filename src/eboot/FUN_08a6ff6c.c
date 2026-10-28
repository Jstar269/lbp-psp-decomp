/* LBPMATCH module=EBOOT.BIN start=0x08a6ff6c end=0x08a6ff78 symbol=FUN_08a6ff6c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a6fc98 (a sibling wrapper passes 1 first). */
extern void FUN_08a6fc98(int flag, unsigned int mask);

void FUN_08a6ff6c(void)
{
  FUN_08a6fc98(0, 0xffff);
}
