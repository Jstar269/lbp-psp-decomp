/* LBPMATCH module=EBOOT.BIN start=0x0899e610 end=0x0899e61c symbol=FUN_0899e610 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0899e5e8 (a sibling wrapper passes 0 first). */
extern void FUN_0899e5e8(int flag, unsigned int mask);

void FUN_0899e610(void)
{
  FUN_0899e5e8(1, 0xffff);
}
