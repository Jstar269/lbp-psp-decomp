/* LBPMATCH module=EBOOT.BIN start=0x088b119c end=0x088b11a4 symbol=FUN_088b119c lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08af0d18 with no arguments. */
extern void FUN_08af0d18(void);

void FUN_088b119c(void)
{
  FUN_08af0d18();
}
