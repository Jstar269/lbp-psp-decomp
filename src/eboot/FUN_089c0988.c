/* LBPMATCH module=EBOOT.BIN start=0x089c0988 end=0x089c0994 symbol=FUN_089c0988 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_089c0458 (a sibling wrapper passes 1 first). */
extern void FUN_089c0458(int flag, unsigned int mask);

void FUN_089c0988(void)
{
  FUN_089c0458(0, 0xffff);
}
