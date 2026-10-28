/* LBPMATCH module=EBOOT.BIN start=0x08b8cc14 end=0x08b8cc1c symbol=FUN_08b8cc14 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08b8cbbc with no arguments. */
extern void FUN_08b8cbbc(void);

void FUN_08b8cc14(void)
{
  FUN_08b8cbbc();
}
