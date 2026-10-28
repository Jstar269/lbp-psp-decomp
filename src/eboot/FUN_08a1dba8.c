/* LBPMATCH module=EBOOT.BIN start=0x08a1dba8 end=0x08a1dbf0 symbol=FUN_08a1dba8 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd4a_ownedcell.h"

extern void FUN_08a1d8d0();
extern void FUN_08a9e0cc();

void FUN_08a1dba8(struct ImplOwner *self)
{
  void *impl;

  impl = self->impl;
  if (impl != (void *)0x0) {
    FUN_08a1d8d0(impl);
    FUN_08a9e0cc(impl);
    self->impl = 0;
  }
  return;
}
