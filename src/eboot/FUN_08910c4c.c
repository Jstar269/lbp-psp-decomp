/* LBPMATCH module=EBOOT.BIN start=0x08910c4c end=0x08910c58 symbol=FUN_08910c4c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0891096c (a sibling wrapper passes 1 first). */
extern void FUN_0891096c(int flag, unsigned int mask);

void FUN_08910c4c(void)
{
  FUN_0891096c(0, 0xffff);
}
