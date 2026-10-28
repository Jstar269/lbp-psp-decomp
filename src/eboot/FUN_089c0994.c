/* LBPMATCH module=EBOOT.BIN start=0x089c0994 end=0x089c09a0 symbol=FUN_089c0994 lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_089c0458 (a sibling wrapper passes 0 first). */
extern void FUN_089c0458(int flag, unsigned int mask);

void FUN_089c0994(void)
{
  FUN_089c0458(1, 0xffff);
}
