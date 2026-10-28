/* LBPMATCH module=EBOOT.BIN start=0x0886f630 end=0x0886f680 symbol=FUN_0886f630 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_vobject.h"

/* Release the object in unk_8c (vtable slot 1) and clear it and *out. */
void FUN_0886f630(unsigned int unused, unsigned int *out, struct TwoRefs *self)
{
  struct VObj *obj;

  obj = self->unk_8c;
  if (obj != 0) {
    obj->vtable[1](obj);
  }
  self->unk_8c = 0;
  *out = 0;
}
