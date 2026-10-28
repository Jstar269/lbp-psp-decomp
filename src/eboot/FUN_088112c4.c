/* LBPMATCH module=EBOOT.BIN start=0x088112c4 end=0x088112d8 symbol=FUN_088112c4 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

/* Four words at +0xc0..+0xcc, cleared together. */
struct FourWords {
  char unk_00[0xc0];
  unsigned int unk_c0;
  unsigned int unk_c4;
  unsigned int unk_c8;
  unsigned int unk_cc;
};

void FUN_088112c4(struct FourWords *self)
{
  self->unk_cc = 0;
  self->unk_c0 = 0;
  self->unk_c4 = 0;
  self->unk_c8 = 0;
  return;
}
