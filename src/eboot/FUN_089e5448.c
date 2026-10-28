/* LBPMATCH module=EBOOT.BIN start=0x089e5448 end=0x089e5450 symbol=FUN_089e5448 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08adb8a4 with no arguments. */
extern void FUN_08adb8a4(void);

void FUN_089e5448(void)
{
  FUN_08adb8a4();
}
