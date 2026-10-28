/* LBPMATCH module=EBOOT.BIN start=0x08a4ae0c end=0x08a4ae64 symbol=FUN_08a4ae0c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_idpair_object.h"

extern void *FUN_08a10f1c();   /* returns the address of a global object (DAT_08bf3bf0) */
extern void FUN_08a115e0();
extern void FUN_08a4ab9c();
extern void FUN_08a9a5c8();

/* Base-class setup, class-specific fields at +0x180..+0x18c, then the object and its ids are
   handed to the global object (the last argument, -1, is passed through unchanged). */
void FUN_08a4ae0c(struct IdPairObject *self)
{
  void *global_obj;

  FUN_08a9a5c8(self);
  FUN_08a4ab9c(&self->unk_180, &self->unk_184, &self->unk_188, &self->unk_18c);
  global_obj = FUN_08a10f1c();
  FUN_08a115e0(global_obj, self->id_a, self->id_b, self->unk_190, self, 0xffffffff);
}
