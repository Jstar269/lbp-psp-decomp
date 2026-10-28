/* LBPMATCH module=EBOOT.BIN start=0x089d7554 end=0x089d75a0 symbol=FUN_089d7554 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
extern void *FUN_089d3ad0(void *self, void *arg1, int arg2);
extern void FUN_089d7384(void *self, void *arg1, int arg2, void *found);

/* Passes the result of FUN_089d3ad0, together with the same arguments, on to FUN_089d7384. */
void FUN_089d7554(void *self, void *arg1, int arg2)
{
  void *found;

  found = FUN_089d3ad0(self, arg1, arg2);
  FUN_089d7384(self, arg1, arg2, found);
  return;
}
