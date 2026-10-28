/* LBPMATCH module=EBOOT.BIN start=0x089234f4 end=0x08923500 symbol=FUN_089234f4 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08923224 (a sibling wrapper passes 1 first). */
extern void FUN_08923224(int flag, unsigned int mask);

void FUN_089234f4(void)
{
  FUN_08923224(0, 0xffff);
}
