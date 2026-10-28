/* LBPMATCH module=EBOOT.BIN start=0x08aa3e9c end=0x08aa3ea4 symbol=FUN_08aa3e9c lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08aa3eac.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Passes the address of the sub-object at offset 0x20 of self to FUN_08aa30d4. */
extern void FUN_08aa30d4(int *member);

void FUN_08aa3e9c(int self)
{
  FUN_08aa30d4((int *)(self + 0x20));
}
