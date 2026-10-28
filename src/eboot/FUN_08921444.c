/* LBPMATCH module=EBOOT.BIN start=0x08921444 end=0x08921450 symbol=FUN_08921444 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0892138c (a sibling wrapper passes 0 first). */
extern void FUN_0892138c(int flag, unsigned int mask);

void FUN_08921444(void)
{
  FUN_0892138c(1, 0xffff);
}
