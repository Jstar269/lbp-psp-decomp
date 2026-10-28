/* LBPMATCH module=EBOOT.BIN start=0x089f50c4 end=0x089f50d0 symbol=FUN_089f50c4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089f4d44 (a sibling wrapper passes 1 first). */
extern void FUN_089f4d44(int flag, unsigned int mask);

void FUN_089f50c4(void)
{
  FUN_089f4d44(0, 0xffff);
}
