/* LBPMATCH module=EBOOT.BIN start=0x08a9e0cc end=0x08a9e0d4 symbol=FUN_08a9e0cc lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a9df6c with no arguments. */
extern void FUN_08a9df6c(void);

void FUN_08a9e0cc(void)
{
  FUN_08a9df6c();
}
