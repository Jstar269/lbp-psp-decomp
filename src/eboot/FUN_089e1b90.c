/* LBPMATCH module=EBOOT.BIN start=0x089e1b90 end=0x089e1b98 symbol=FUN_089e1b90 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_089e1a14 with no arguments. */
extern void FUN_089e1a14(void);

void FUN_089e1b90(void)
{
  FUN_089e1a14();
}
