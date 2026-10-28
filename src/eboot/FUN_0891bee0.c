/* LBPMATCH module=EBOOT.BIN start=0x0891bee0 end=0x0891bf1c symbol=FUN_0891bee0 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_freebuf.h"

extern void FUN_08a9df6c();

/* Releases the buffer (when there is one) and clears the pointer and the size. */
void FUN_0891bee0(struct Rd4cFreeBuf *self)
{
  if (self->data != 0) {
    FUN_08a9df6c(self->data);
    self->data = 0;
  }
  self->size = 0;
}
