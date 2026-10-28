/* LBPMATCH module=EBOOT.BIN start=0x08a9e830 end=0x08a9e838 symbol=FUN_08a9e830 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a9e4a4 with no arguments. */
extern void FUN_08a9e4a4(void);

void FUN_08a9e830(void)
{
  FUN_08a9e4a4();
}
