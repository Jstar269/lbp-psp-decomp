/* LBPMATCH module=EBOOT.BIN start=0x08a3ad3c end=0x08a3ad48 symbol=FUN_08a3ad3c lang=c99 cc=gcc410-Os */
/* Clone of src/eboot/FUN_08804770.c (lbpclone.py tag r-rd1a-b): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: forwards fixed arguments (1, 0xffff) to FUN_08a3aa30 (a sibling wrapper passes 0 first). */
extern void FUN_08a3aa30(int flag, unsigned int mask);

void FUN_08a3ad3c(void)
{
  FUN_08a3aa30(1, 0xffff);
}
