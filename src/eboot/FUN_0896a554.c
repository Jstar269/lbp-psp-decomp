/* LBPMATCH module=EBOOT.BIN start=0x0896a554 end=0x0896a560 symbol=FUN_0896a554 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_0896a52c (a sibling wrapper passes 0 first). */
extern void FUN_0896a52c(int flag, unsigned int mask);

void FUN_0896a554(void)
{
  FUN_0896a52c(1, 0xffff);
}
