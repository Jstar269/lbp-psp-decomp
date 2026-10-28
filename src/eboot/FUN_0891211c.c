/* LBPMATCH module=EBOOT.BIN start=0x0891211c end=0x08912128 symbol=FUN_0891211c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08911ed0 (a sibling wrapper passes 1 first). */
extern void FUN_08911ed0(int flag, unsigned int mask);

void FUN_0891211c(void)
{
  FUN_08911ed0(0, 0xffff);
}
