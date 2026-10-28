/* LBPMATCH module=EBOOT.BIN start=0x08954574 end=0x089545b4 symbol=FUN_08954574 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_subobject.h"

/* Releases the sub-object at +0xa8 through virtual slot 1 and clears the pointer. */
void FUN_08954574(struct SubObjectOwner *self)
{
  struct VObj *sub;

  sub = self->sub_object;
  if (sub != 0) {
    sub->vtable[1](sub);
    self->sub_object = 0;
  }
  return;
}
