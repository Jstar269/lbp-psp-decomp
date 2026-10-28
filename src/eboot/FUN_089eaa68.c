/* LBPMATCH module=EBOOT.BIN start=0x089eaa68 end=0x089eaa70 symbol=FUN_089eaa68 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08baa19c with no arguments. */
extern void FUN_08baa19c(void);

void FUN_089eaa68(void)
{
  FUN_08baa19c();
}
