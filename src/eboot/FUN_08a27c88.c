/* LBPMATCH module=EBOOT.BIN start=0x08a27c88 end=0x08a27cc0 symbol=FUN_08a27c88 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Clears the fields of an object (offsets 4..0x30 and 0x80); the rest is not touched. */
struct Obj08a27c88 {
  char pad_00[4];
  unsigned int unk_04;
  unsigned int unk_08;
  unsigned int unk_0c;
  unsigned int unk_10;
  unsigned int unk_14;
  unsigned int unk_18;
  unsigned int unk_1c;
  unsigned int unk_20;
  unsigned int unk_24;
  unsigned int unk_28;
  unsigned int unk_2c;
  unsigned int unk_30;
  char pad_34[0x4c];
  unsigned int unk_80;
};

void FUN_08a27c88(struct Obj08a27c88 *self)
{
  self->unk_80 = 0;
  self->unk_04 = 0;
  self->unk_08 = 0;
  self->unk_0c = 0;
  self->unk_10 = 0;
  self->unk_14 = 0;
  self->unk_18 = 0;
  self->unk_1c = 0;
  self->unk_20 = 0;
  self->unk_24 = 0;
  self->unk_28 = 0;
  self->unk_2c = 0;
  self->unk_30 = 0;
}
