/* LBPMATCH module=EBOOT.BIN start=0x0891d188 end=0x0891d194 symbol=FUN_0891d188 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0891d0c4 (a sibling wrapper passes 1 first). */
extern void FUN_0891d0c4(int flag, unsigned int mask);

void FUN_0891d188(void)
{
  FUN_0891d0c4(0, 0xffff);
}
