/* LBPMATCH module=EBOOT.BIN start=0x08a33d7c end=0x08a33d88 symbol=FUN_08a33d7c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a33b20 (a sibling wrapper passes 0 first). */
extern void FUN_08a33b20(int flag, unsigned int mask);

void FUN_08a33d7c(void)
{
  FUN_08a33b20(1, 0xffff);
}
