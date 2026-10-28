/* LBPMATCH module=EBOOT.BIN start=0x0899335c end=0x0899338c symbol=FUN_0899335c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_unk1c.h"

extern int FUN_08974660(struct Unk1cObject *self, int arg);

/* Forwards to FUN_08974660 only while the word at +0x1c is zero; otherwise returns 0. */
int FUN_0899335c(struct Unk1cObject *self, int arg)
{
  int result;

  result = 0;
  if (self->unk_1c == 0) {
    result = FUN_08974660(self, arg);
  }
  return result;
}
