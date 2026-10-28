/* LBPMATCH module=EBOOT.BIN start=0x08a64d94 end=0x08a64d9c symbol=FUN_08a64d94 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a72930 with no arguments. */
extern void FUN_08a72930(void);

void FUN_08a64d94(void)
{
  FUN_08a72930();
}
