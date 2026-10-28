/* LBPMATCH module=EBOOT.BIN start=0x08a81344 end=0x08a8134c symbol=FUN_08a81344 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a6aecc with no arguments. */
extern void FUN_08a6aecc(void);

void FUN_08a81344(void)
{
  FUN_08a6aecc();
}
