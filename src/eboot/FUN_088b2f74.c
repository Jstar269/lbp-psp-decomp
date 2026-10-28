/* LBPMATCH module=EBOOT.BIN start=0x088b2f74 end=0x088b2fb8 symbol=FUN_088b2f74 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_globals.h"

struct Flagged {
  char unk_00[0xc];
  unsigned int flags_0c;
};

extern struct Rd4dGlobals *FUN_089ecaa8();

/* When bit 0x10 of the flags is set and the global byte at +0x197 is set, sets the byte at +0x198. */
void FUN_088b2f74(unsigned int unused, struct Flagged **ref)
{
  struct Rd4dGlobals *globals;

  if (((((*ref)->flags_0c & 0x10) != 0) && (globals = FUN_089ecaa8(), globals->unk_197 != 0))) {
    globals->unk_198 = 1;
  }
  return;
}
