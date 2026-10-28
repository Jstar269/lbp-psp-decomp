/* LBPMATCH module=EBOOT.BIN start=0x08a10d04 end=0x08a10d18 symbol=FUN_08a10d04 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Obj {
  char unk_00[0x94];
  unsigned char unk_94;
  unsigned char unk_95;
  unsigned char unk_96;
};

void FUN_08a10d04(struct Obj *self)
{
  self->unk_94 = 1;
  self->unk_96 = 0;
  self->unk_95 = 0;
  return;
}
