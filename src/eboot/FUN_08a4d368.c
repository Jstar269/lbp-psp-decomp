/* LBPMATCH module=EBOOT.BIN start=0x08a4d368 end=0x08a4d370 symbol=FUN_08a4d368 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08871a30.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Ignores the first argument and forwards the second to FUN_08a4d204. */
extern void FUN_08a4d204(int arg);

void FUN_08a4d368(unsigned int unused, int arg)
{
  FUN_08a4d204(arg);
}
