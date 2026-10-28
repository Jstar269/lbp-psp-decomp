/* LBPMATCH module=EBOOT.BIN start=0x089432b8 end=0x089432c0 symbol=FUN_089432b8 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_0888b8cc.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

/* Passes the address of the sub-object at offset 0x10 of self to FUN_089431d8. */
extern int FUN_089431d8(int *member);

void FUN_089432b8(int self)
{
  FUN_089431d8((int *)(self + 0x10));
}
