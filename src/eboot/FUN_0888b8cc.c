/* LBPMATCH module=EBOOT.BIN start=0x0888b8cc end=0x0888b8d4 symbol=FUN_0888b8cc lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g12); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Passes the address of the sub-object at offset 0x10 of self to FUN_08ad2810. */
extern int FUN_08ad2810(int *member);

void FUN_0888b8cc(int self)
{
  FUN_08ad2810((int *)(self + 0x10));
}
