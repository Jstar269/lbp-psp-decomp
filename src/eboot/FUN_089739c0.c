/* LBPMATCH module=EBOOT.BIN start=0x089739c0 end=0x08973a04 symbol=FUN_089739c0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd3b_vobject.h"

struct Obj {
  char pad_00[0x18];
  struct VObj *sub_object;   /* +0x18 */
};

extern void FUN_089737c8(struct Obj *self);

/* Runs FUN_089737c8, releases the sub-object through virtual slot 1 (if any) and clears the pointer. */
void FUN_089739c0(struct Obj *self)
{
  struct VObj *sub;

  FUN_089737c8(self);
  sub = self->sub_object;
  if (sub != 0) {
    sub->vtable[1](sub);
  }
  self->sub_object = 0;
  return;
}
