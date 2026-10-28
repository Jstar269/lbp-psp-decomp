/* LBPMATCH module=EBOOT.BIN start=0x0891cf30 end=0x0891cf3c symbol=FUN_0891cf30 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0891cf08 (a sibling wrapper passes 0 first). */
extern void FUN_0891cf08(int flag, unsigned int mask);

void FUN_0891cf30(void)
{
  FUN_0891cf08(1, 0xffff);
}
