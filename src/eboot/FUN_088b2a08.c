/* LBPMATCH module=EBOOT.BIN start=0x088b2a08 end=0x088b2a30 symbol=FUN_088b2a08 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_globals.h"

struct Obj {
  char unk_00[8];
  unsigned char unk_08;
};

extern void FUN_0883fb18();
extern struct Rd4dGlobals *FUN_089ecaa8();

void FUN_088b2a08(struct Obj *self)
{
  struct Rd4dGlobals *globals;

  self->unk_08 = 1;
  globals = FUN_089ecaa8();
  FUN_0883fb18(globals->unk_1b4, 0);
  return;
}
