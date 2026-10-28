/* LBPMATCH module=EBOOT.BIN start=0x088a7f34 end=0x088a7f48 symbol=FUN_088a7f34 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Obj {
  char pad_00[0x14];
  int unk_14;
  int unk_18;
  int unk_1c;
  int unk_20;
};

/* Clears four words at +0x14..+0x20 (stored in this order). */
void FUN_088a7f34(struct Obj *self)
{
  self->unk_20 = 0;
  self->unk_14 = 0;
  self->unk_18 = 0;
  self->unk_1c = 0;
}
