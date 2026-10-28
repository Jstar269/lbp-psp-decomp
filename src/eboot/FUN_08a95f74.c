/* LBPMATCH module=EBOOT.BIN start=0x08a95f74 end=0x08a95f7c symbol=FUN_08a95f74 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08849cc0.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Thin wrapper: calls FUN_08a0b558 with no arguments. */
extern void FUN_08a0b558(void);

void FUN_08a95f74(void)
{
  FUN_08a0b558();
}
