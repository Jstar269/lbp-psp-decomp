/* LBPMATCH module=EBOOT.BIN start=0x08a4d090 end=0x08a4d098 symbol=FUN_08a4d090 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08871a30.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Ignores the first argument and forwards the second to FUN_08a4cf2c. */
extern void FUN_08a4cf2c(int arg);

void FUN_08a4d090(unsigned int unused, int arg)
{
  FUN_08a4cf2c(arg);
}
