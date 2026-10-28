/* LBPMATCH module=EBOOT.BIN start=0x08994b94 end=0x08994bc4 symbol=FUN_08994b94 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_unk1c.h"

extern int FUN_08974660(struct Unk1cObject *self, int arg);

/* Forwards to FUN_08974660 only while the word at +0x1c is zero; otherwise returns 0. */
int FUN_08994b94(struct Unk1cObject *self, int arg)
{
  int result;

  result = 0;
  if (self->unk_1c == 0) {
    result = FUN_08974660(self, arg);
  }
  return result;
}
