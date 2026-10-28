/* LBPMATCH module=EBOOT.BIN start=0x089e0844 end=0x089e0850 symbol=FUN_089e0844 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089e081c (a sibling wrapper passes 0 first). */
extern void FUN_089e081c(int flag, unsigned int mask);

void FUN_089e0844(void)
{
  FUN_089e081c(1, 0xffff);
}
