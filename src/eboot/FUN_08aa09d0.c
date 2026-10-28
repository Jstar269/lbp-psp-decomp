/* LBPMATCH module=EBOOT.BIN start=0x08aa09d0 end=0x08aa09d8 symbol=FUN_08aa09d0 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08baa19c with no arguments. */
extern void FUN_08baa19c(void);

void FUN_08aa09d0(void)
{
  FUN_08baa19c();
}
