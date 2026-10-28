/* LBPMATCH module=EBOOT.BIN start=0x089029bc end=0x089029c8 symbol=FUN_089029bc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08902770 (a sibling wrapper passes 1 first). */
extern void FUN_08902770(int flag, unsigned int mask);

void FUN_089029bc(void)
{
  FUN_08902770(0, 0xffff);
}
