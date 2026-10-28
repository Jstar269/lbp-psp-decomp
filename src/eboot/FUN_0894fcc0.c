/* LBPMATCH module=EBOOT.BIN start=0x0894fcc0 end=0x0894fccc symbol=FUN_0894fcc0 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[4];
  int unk_04;
  int unk_08;
};

/* Stores two words at +4 and +8. */
void FUN_0894fcc0(struct Obj *self, int first, int second)
{
  self->unk_08 = second;
  self->unk_04 = first;
  return;
}
