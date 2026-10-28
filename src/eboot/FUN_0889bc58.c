/* LBPMATCH module=EBOOT.BIN start=0x0889bc58 end=0x0889bca4 symbol=FUN_0889bc58 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd3b_vobject.h"

struct Obj {
  struct VObj base;
  int unk_04;
};

extern int DAT_08bee224;
extern void FUN_0889ada8(int arg0, struct Obj *self);
extern void FUN_0889d09c(void *instance);
extern void *FUN_0889d194(void);

void FUN_0889bc58(struct Obj *self)
{
  void *instance;

  self->unk_04 = 0;
  instance = FUN_0889d194();
  FUN_0889d09c(instance);
  self->base.vtable[0x14 / 4](self);
  FUN_0889ada8(DAT_08bee224, self);
  return;
}
