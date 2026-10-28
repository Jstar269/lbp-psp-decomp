/* LBPMATCH module=EBOOT.BIN start=0x08a89440 end=0x08a894c4 symbol=FUN_08a89440 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_linkedpair.h"

extern void *FUN_08a10f1c();
extern void FUN_08a12ec0();
extern int FUN_08a50fbc();
extern int FUN_08a52b38();
extern void FUN_08a892a0();
extern void FUN_08a99694();

/* Runs two helpers on self, then looks up the objects for id_a and id_b and passes them with unk_190 to FUN_08a12ec0. */
void FUN_08a89440(struct LinkedPairObject *self)
{
  int *found_a;
  int *found_b;
  void *target;
  int holder;

  FUN_08a99694(self);
  FUN_08a892a0(self);
  holder = FUN_08a50fbc();
  found_a = (int *)FUN_08a52b38(holder, self->id_a);
  holder = FUN_08a50fbc();
  found_b = (int *)FUN_08a52b38(holder, self->id_b);
  target = FUN_08a10f1c();
  FUN_08a12ec0(target, found_a, found_b, self->unk_190, self, -1);
  return;
}
