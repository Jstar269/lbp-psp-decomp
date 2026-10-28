/* LBPMATCH module=EBOOT.BIN start=0x08958348 end=0x08958388 symbol=FUN_08958348 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_owned_a8.h"

/* Release the owned object (virtual slot 1) and clear the pointer. */
void FUN_08958348(struct Rd4cOwnedA8Holder *self)
{
  struct Rd4cVirtualObject *owned;

  owned = self->owned;
  if (owned != 0) {
    owned->vtable[1](owned);
    self->owned = 0;
  }
}
