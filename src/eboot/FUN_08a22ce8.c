/* LBPMATCH module=EBOOT.BIN start=0x08a22ce8 end=0x08a22cfc symbol=FUN_08a22ce8 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Quad {
  unsigned int unk_00;
  unsigned int unk_04;
  unsigned int unk_08;
  unsigned int unk_0c;
};

void FUN_08a22ce8(struct Quad *self, unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
  self->unk_0c = d;
  self->unk_00 = a;
  self->unk_04 = b;
  self->unk_08 = c;
}
