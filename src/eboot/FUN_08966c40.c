/* LBPMATCH module=EBOOT.BIN start=0x08966c40 end=0x08966ca0 symbol=FUN_08966c40 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_vobject.h"

extern int DAT_08be85f8;

struct Owner {
  char pad[0x2c];
  struct VObject *unk_2c;
  char pad2[0x10];
  struct VObject *unk_40;
};

/* Calls virtual slot 1 on each owned object (when set) and clears the global DAT_08be85f8. */
void FUN_08966c40(struct Owner *self)
{
  struct VObject *obj;

  obj = self->unk_2c;
  if (obj != 0) {
    ((void (*)(struct VObject *))obj->vtable[1])(obj);
  }
  obj = self->unk_40;
  if (obj != 0) {
    ((void (*)(struct VObject *))obj->vtable[1])(obj);
  }
  DAT_08be85f8 = 0;
}
