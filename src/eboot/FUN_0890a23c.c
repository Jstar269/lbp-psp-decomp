/* LBPMATCH module=EBOOT.BIN start=0x0890a23c end=0x0890a2a4 symbol=FUN_0890a23c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_vobject.h"

struct Owner {
  int (**vtable)();
  char pad_04[0x54];
  struct VObj *unk_58;
};

/* If the owner's unk_58 object answers non-zero to vtable slot 0x5c, release the owner (vtable slot 1) and
   clear *slot. */
void FUN_0890a23c(struct Owner **slot)
{
  struct VObj *sub;
  struct Owner *owner;

  sub = (*slot)->unk_58;
  if (sub != 0 && sub->vtable[0x5c / 4](sub) != 0) {
    owner = *slot;
    if (owner != 0) {
      owner->vtable[1](owner);
    }
    *slot = 0;
  }
}
