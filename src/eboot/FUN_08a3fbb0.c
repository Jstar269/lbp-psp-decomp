/* LBPMATCH module=EBOOT.BIN start=0x08a3fbb0 end=0x08a3fbf8 symbol=FUN_08a3fbb0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Calls FUN_08a34688 on the object, then passes the object's field +400 to FUN_08a11e24 together with the
   result of FUN_08a10f1c; returns the first call's result. */
extern unsigned int *FUN_08a10f1c();
extern void FUN_08a11e24();
extern unsigned int FUN_08a34688();

unsigned int FUN_08a3fbb0(int *self, unsigned char arg)
{
  unsigned int result;
  unsigned int *other;

  result = FUN_08a34688(self, arg);
  other = FUN_08a10f1c();
  FUN_08a11e24((int)other, self[100]);
  return result;
}
