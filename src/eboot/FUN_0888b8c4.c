/* LBPMATCH module=EBOOT.BIN start=0x0888b8c4 end=0x0888b8cc symbol=FUN_0888b8c4 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_0888b8cc.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Passes the address of the sub-object at offset 0x10 of self to FUN_08ad3088. */
extern int FUN_08ad3088(int *member);

void FUN_0888b8c4(int self)
{
  FUN_08ad3088((int *)(self + 0x10));
}
