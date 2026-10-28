/* LBPMATCH module=EBOOT.BIN start=0x088c4d44 end=0x088c4d88 symbol=FUN_088c4d44 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_obj_a96c.h"

extern void FUN_088b2a08();
extern void FUN_089595fc();
extern struct Rd4dObjA96c *FUN_0895a96c();

void FUN_088c4d44(void *self)
{
  struct Rd4dObjA96c *obj;

  FUN_088b2a08(self);
  obj = FUN_0895a96c();
  if (obj->unk_50 != 0) {
    obj = FUN_0895a96c();
    FUN_089595fc(obj);
    return;
  }
  return;
}
