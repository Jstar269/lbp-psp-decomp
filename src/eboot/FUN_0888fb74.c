/* LBPMATCH module=EBOOT.BIN start=0x0888fb74 end=0x0888fb80 symbol=FUN_0888fb74 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0888f6d8 (a sibling wrapper passes 1 first). */
extern void FUN_0888f6d8(int flag, unsigned int mask);

void FUN_0888fb74(void)
{
  FUN_0888f6d8(0, 0xffff);
}
