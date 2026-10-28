/* LBPMATCH module=EBOOT.BIN start=0x08982298 end=0x089822c0 symbol=FUN_08982298 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
struct Rec {
  int unk_00;
  int unk_04;
  int unk_08;
  int unk_0c;
  int unk_10;
  int unk_14;
  int unk_18;
  int unk_1c;
};

/* Words 6 and 7 are set to -1, the rest to 0. */
void FUN_08982298(struct Rec *rec)
{
  rec->unk_1c = -1;
  rec->unk_00 = 0;
  rec->unk_04 = 0;
  rec->unk_08 = 0;
  rec->unk_0c = 0;
  rec->unk_10 = 0;
  rec->unk_14 = 0;
  rec->unk_18 = -1;
  return;
}
