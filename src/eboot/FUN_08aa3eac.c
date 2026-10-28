/* LBPMATCH module=EBOOT.BIN start=0x08aa3eac end=0x08aa3eb4 symbol=FUN_08aa3eac lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g12); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Passes the address of the sub-object at offset 0x20 of self to FUN_08aa32c0. */
extern void FUN_08aa32c0(int *member);

void FUN_08aa3eac(int self)
{
  FUN_08aa32c0((int *)(self + 0x20));
}
