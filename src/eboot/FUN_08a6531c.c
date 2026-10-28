/* LBPMATCH module=EBOOT.BIN start=0x08a6531c end=0x08a65360 symbol=FUN_08a6531c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

extern void *FUN_08a68fd4();
extern void FUN_08a691d0();
extern void FUN_08a70db4();

void FUN_08a6531c(void *obj, unsigned char flag)
{
  void *helper;

  helper = FUN_08a68fd4();
  FUN_08a691d0(helper, obj);
  FUN_08a70db4(obj, flag);
}
