/* LBPMATCH module=EBOOT.BIN start=0x0891be44 end=0x0891be5c symbol=FUN_0891be44 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  int unk_00;
  unsigned char unk_04;
  unsigned char unk_05;
  char pad_06[2];
  int unk_08;
};

/* Initializer: stores `value` at +0, clears the two bytes at +4 and +5 and sets the word at +8 to -1. */
void FUN_0891be44(struct Obj *self, int value)
{
  self->unk_08 = -1;
  self->unk_00 = value;
  self->unk_04 = 0;
  self->unk_05 = 0;
  return;
}
