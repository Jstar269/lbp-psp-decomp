/* LBPMATCH module=EBOOT.BIN start=0x088a0604 end=0x088a062c symbol=FUN_088a0604 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Initialises the record: fields +4 and +8 to -1, the others to 0, and stores `param` at +0x1c. */
struct Record {
  unsigned int unk_00;
  int unk_04;
  int unk_08;
  unsigned int unk_0c;
  unsigned int unk_10;
  unsigned int unk_14;
  unsigned char unk_18;
  char pad[3];
  unsigned int param;        /* +0x1c */
};

void FUN_088a0604(struct Record *self, unsigned int param)
{
  self->unk_04 = -1;
  self->param = param;
  self->unk_0c = 0;
  self->unk_10 = 0;
  self->unk_08 = -1;
  self->unk_00 = 0;
  self->unk_14 = 0;
  self->unk_18 = 0;
  return;
}
