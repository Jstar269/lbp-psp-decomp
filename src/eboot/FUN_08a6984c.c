/* LBPMATCH module=EBOOT.BIN start=0x08a6984c end=0x08a69858 symbol=FUN_08a6984c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804764.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (0, 0xffff) to FUN_08a695b0 (a sibling wrapper passes 1 first). */
extern void FUN_08a695b0(int flag, unsigned int mask);

void FUN_08a6984c(void)
{
  FUN_08a695b0(0, 0xffff);
}
