/* LBPMATCH module=EBOOT.BIN start=0x089f50d0 end=0x089f50dc symbol=FUN_089f50d0 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089f4d44 (a sibling wrapper passes 0 first). */
extern void FUN_089f4d44(int flag, unsigned int mask);

void FUN_089f50d0(void)
{
  FUN_089f4d44(1, 0xffff);
}
