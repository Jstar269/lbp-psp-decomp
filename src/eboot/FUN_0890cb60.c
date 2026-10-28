/* LBPMATCH module=EBOOT.BIN start=0x0890cb60 end=0x0890cb68 symbol=FUN_0890cb60 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_0890ca80 with no arguments. */
extern void FUN_0890ca80(void);

void FUN_0890cb60(void)
{
  FUN_0890ca80();
}
