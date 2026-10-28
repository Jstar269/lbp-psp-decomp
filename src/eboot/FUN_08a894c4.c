/* LBPMATCH module=EBOOT.BIN start=0x08a894c4 end=0x08a89510 symbol=FUN_08a894c4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/obj180layout.h"

extern unsigned int *FUN_08a10f1c();
extern void FUN_08a115e0();
extern void FUN_08a892a0();
extern void FUN_08a99694();

void FUN_08a894c4(Obj180 *self)
{
  unsigned int *context;

  FUN_08a99694(self);
  FUN_08a892a0(self);
  context = FUN_08a10f1c();
  FUN_08a115e0(context, self->key_19c, self->key_1a0, self->unk_190, self, -1);
}
