/* LBPMATCH module=EBOOT.BIN start=0x08894d6c end=0x08894d74 symbol=FUN_08894d6c lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08894cbc with no arguments. */
extern void FUN_08894cbc(void);

void FUN_08894d6c(void)
{
  FUN_08894cbc();
}
