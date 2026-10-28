/* LBPMATCH module=EBOOT.BIN start=0x08a34620 end=0x08a34678 symbol=FUN_08a34620 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd3b_vobject.h"

struct Obj {
  struct VObj base;
  char pad_04[0x2c];
  int unk_30;
};

extern int FUN_08a50fbc(void);
extern void FUN_08a54f2c(int arg0, struct Obj *self);
extern void FUN_08a6dda4(struct Obj *self);

void FUN_08a34620(struct Obj *self)
{
  int instance;

  self->unk_30 = 0;
  self->base.vtable[0xd4 / 4]();
  instance = FUN_08a50fbc();
  FUN_08a54f2c(instance, self);
  self->base.vtable[0xcc / 4](self);
  FUN_08a6dda4(self);
  return;
}
