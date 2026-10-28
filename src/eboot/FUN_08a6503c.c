/* LBPMATCH module=EBOOT.BIN start=0x08a6503c end=0x08a65048 symbol=FUN_08a6503c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a64de0 (a sibling wrapper passes 0 first). */
extern void FUN_08a64de0(int flag, unsigned int mask);

void FUN_08a6503c(void)
{
  FUN_08a64de0(1, 0xffff);
}
