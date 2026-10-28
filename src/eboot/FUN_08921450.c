/* LBPMATCH module=EBOOT.BIN start=0x08921450 end=0x0892145c symbol=FUN_08921450 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0892138c (a sibling wrapper passes 1 first). */
extern void FUN_0892138c(int flag, unsigned int mask);

void FUN_08921450(void)
{
  FUN_0892138c(0, 0xffff);
}
