/* LBPMATCH module=EBOOT.BIN start=0x0891c820 end=0x0891c82c symbol=FUN_0891c820 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0891c754 (a sibling wrapper passes 1 first). */
extern void FUN_0891c754(int flag, unsigned int mask);

void FUN_0891c820(void)
{
  FUN_0891c754(0, 0xffff);
}
