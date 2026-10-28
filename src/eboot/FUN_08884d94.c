/* LBPMATCH module=EBOOT.BIN start=0x08884d94 end=0x08884db0 symbol=FUN_08884d94 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
struct ClearedRec {
  unsigned char unk_00[0x4c];
  unsigned int unk_4c;
  unsigned int unk_50;
  unsigned int unk_54;
  unsigned int unk_58;
  unsigned int unk_5c;
  unsigned char unk_60;
};

/* Zeroes the fields at +0x4c..+0x60. */
void FUN_08884d94(struct ClearedRec *self)
{
  self->unk_60 = 0;
  self->unk_5c = 0;
  self->unk_54 = 0;
  self->unk_50 = 0;
  self->unk_4c = 0;
  self->unk_58 = 0;
}
