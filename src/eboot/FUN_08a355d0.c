/* LBPMATCH module=EBOOT.BIN start=0x08a355d0 end=0x08a35614 symbol=FUN_08a355d0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08a555ec();
extern void FUN_08a6aed4();

struct Copyable {
  char unk_00[0x250];
  char block_250[0xa0];
  int unk_2f0;
};

void FUN_08a355d0(struct Copyable *dst,struct Copyable *src)
{
  FUN_08a6aed4(dst,src);
  FUN_08a555ec(src->block_250,dst->block_250);
  dst->unk_2f0 = src->unk_2f0;
  return;
}
