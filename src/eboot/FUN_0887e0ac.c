/* LBPMATCH module=EBOOT.BIN start=0x0887e0ac end=0x0887e0cc symbol=FUN_0887e0ac lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x14];
  int unk_14;
  int unk_18;
};

extern void FUN_08891788();

void FUN_0887e0ac(struct Obj *self)
{
  self->unk_14 = 0;
  self->unk_18 = 0;
  FUN_08891788(self);
  return;
}
