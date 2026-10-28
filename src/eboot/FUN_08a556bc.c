/* LBPMATCH module=EBOOT.BIN start=0x08a556bc end=0x08a556e8 symbol=FUN_08a556bc lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Zeroes the record (field +0xc is left alone). */
struct Record {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  unsigned int unk_0c;
  unsigned int unk_10;
  unsigned int unk_14;
  unsigned int unk_18;
  unsigned int unk_1c;
  unsigned short unk_20;
  unsigned short unk_22;
  unsigned int unk_24;
};

void FUN_08a556bc(struct Record *self)
{
  self->unk_24 = 0;
  self->unk_00 = 0;
  self->unk_04 = 0;
  self->unk_08 = 0;
  self->unk_10 = 0;
  self->unk_14 = 0;
  self->unk_18 = 0;
  self->unk_1c = 0;
  self->unk_20 = 0;
  self->unk_22 = 0;
  return;
}
