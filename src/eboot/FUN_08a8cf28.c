/* LBPMATCH module=EBOOT.BIN start=0x08a8cf28 end=0x08a8cf30 symbol=FUN_08a8cf28 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a9a10c with no arguments. */
extern void FUN_08a9a10c(void);

void FUN_08a8cf28(void)
{
  FUN_08a9a10c();
}
