/* LBPMATCH module=EBOOT.BIN start=0x0899d2bc end=0x0899d2c8 symbol=FUN_0899d2bc lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_0899cbd0 (a sibling wrapper passes 1 first). */
extern void FUN_0899cbd0(int flag, unsigned int mask);

void FUN_0899d2bc(void)
{
  FUN_0899cbd0(0, 0xffff);
}
