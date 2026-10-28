/* LBPMATCH module=EBOOT.BIN start=0x08aa3e8c end=0x08aa3e94 symbol=FUN_08aa3e8c lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_08aa3eac.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Passes the address of the sub-object at offset 0x20 of self to FUN_08aa3040. */
extern void FUN_08aa3040(int *member);

void FUN_08aa3e8c(int self)
{
  FUN_08aa3040((int *)(self + 0x20));
}
