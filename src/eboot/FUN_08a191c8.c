/* LBPMATCH module=EBOOT.BIN start=0x08a191c8 end=0x08a191d0 symbol=FUN_08a191c8 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08aa3eac.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Passes the address of the sub-object at offset 0x20 of self to FUN_08aa3164. */
extern void FUN_08aa3164(int *member);

void FUN_08a191c8(int self)
{
  FUN_08aa3164((int *)(self + 0x20));
}
