/* LBPMATCH module=EBOOT.BIN start=0x08923500 end=0x0892350c symbol=FUN_08923500 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08923224 (a sibling wrapper passes 0 first). */
extern void FUN_08923224(int flag, unsigned int mask);

void FUN_08923500(void)
{
  FUN_08923224(1, 0xffff);
}
