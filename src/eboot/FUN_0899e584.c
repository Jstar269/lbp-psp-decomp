/* LBPMATCH module=EBOOT.BIN start=0x0899e584 end=0x0899e590 symbol=FUN_0899e584 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0899e55c (a sibling wrapper passes 0 first). */
extern void FUN_0899e55c(int flag, unsigned int mask);

void FUN_0899e584(void)
{
  FUN_0899e55c(1, 0xffff);
}
