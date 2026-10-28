/* LBPMATCH module=EBOOT.BIN start=0x08a3505c end=0x08a35068 symbol=FUN_08a3505c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a34e0c (a sibling wrapper passes 1 first). */
extern void FUN_08a34e0c(int flag, unsigned int mask);

void FUN_08a3505c(void)
{
  FUN_08a34e0c(0, 0xffff);
}
