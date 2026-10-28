/* LBPMATCH module=EBOOT.BIN start=0x08989e18 end=0x08989e8c symbol=FUN_08989e18 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_dat08bf03b8.h"

struct Obj {
  char pad_00[0x20];
  int unk_20;
  unsigned char unk_24;
};

extern void *DAT_08be8510;
extern struct Dat08bf03b8 *DAT_08bf03b8;
extern void FUN_0880b148(void *target, int arg);
extern void FUN_088157d4(void *target);
extern void FUN_0881b3cc(void *target);

void FUN_08989e18(struct Obj *self)
{
  void *target;

  target = DAT_08be8510;
  FUN_0880b148(DAT_08be8510, 1);
  self->unk_20 = 0;
  if (self->unk_24 == 0) {
    FUN_0881b3cc(target);
  }
  else {
    FUN_088157d4(target);
  }
  DAT_08bf03b8->unk_8c = 1;
  return;
}
