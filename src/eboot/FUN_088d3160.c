/* LBPMATCH module=EBOOT.BIN start=0x088d3160 end=0x088d3174 symbol=FUN_088d3160 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Rec {
  unsigned char unk_00;
  unsigned char unk_01;
  unsigned short unk_02;
  int unk_04;
};

void FUN_088d3160(struct Rec *rec)
{
  rec->unk_04 = 0;
  rec->unk_00 = 0;
  rec->unk_01 = 0;
  rec->unk_02 = 0;
  return;
}
