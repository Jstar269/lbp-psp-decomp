/* LBPMATCH module=EBOOT.BIN start=0x08b8ff10 end=0x08b8ff18 symbol=FUN_08b8ff10 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08b8fb5c with no arguments. */
extern void FUN_08b8fb5c(void);

void FUN_08b8ff10(void)
{
  FUN_08b8fb5c();
}
