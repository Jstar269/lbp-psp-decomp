/* LBPMATCH module=EBOOT.BIN start=0x0896fb74 end=0x0896fbd4 symbol=FUN_0896fb74 lang=c99 cc=gcc402t-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_refobj.h"

struct HandleConsumer {
  char unk_00[0x10];
  void *target;       /* +0x10: the object the handle is passed to */
};

extern int FUN_0896b420();      /* (target, &handle_copy) */
extern void FUN_08970b6c();     /* drops one reference */

/* Passes a counted copy of *handle to FUN_0896b420 on this->target and returns its result. */
int FUN_0896fb74(struct HandleConsumer *self, struct RefCounted **handle)
{
  int result;
  void *target;
  struct RefCounted *copy[4];

  copy[0] = *handle;
  target = self->target;
  if (copy[0] != 0) {
    copy[0]->ref_count = copy[0]->ref_count + 1;
  }
  result = FUN_0896b420(target, copy);
  if (copy[0] != 0) {
    FUN_08970b6c(copy[0]);
  }
  return result;
}
