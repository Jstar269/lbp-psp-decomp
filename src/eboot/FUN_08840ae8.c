/* LBPMATCH module=EBOOT.BIN start=0x08840ae8 end=0x08840b50 symbol=FUN_08840ae8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_bufowner.h"

extern void FUN_088050b8();   /* release of the sub-object at +0x10 */
extern void FUN_08a9e11c();   /* release of the buffer at +4 */

/* Releases the sub-object, then the buffer, then the sub-object pointer again if it is set once more
   (retail re-reads it after the second call). */
void FUN_08840ae8(struct BufferOwner *self)
{
  void *owned;

  owned = self->owned;
  if (owned != 0) {
    self->owned = 0;
    FUN_088050b8(owned);
  }
  if (self->buffer != 0) {
    FUN_08a9e11c(self->buffer);
    self->buffer = 0;
  }
  if (self->owned != 0) {
    FUN_088050b8(self->owned);
    return;
  }
}
