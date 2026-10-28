/* LBPMATCH module=EBOOT.BIN start=0x08a3fc3c end=0x08a3fc9c symbol=FUN_08a3fc3c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_idpair_object.h"

extern void *FUN_08a50fbc();             /* returns a global pointer (DAT_08bf6e74) */
extern unsigned int FUN_08a52b38();      /* id -> value lookup in a tree held by its first argument */

/* Resolves the object's two ids (id_a, id_b) through the global FUN_08a50fbc() registry. */
void FUN_08a3fc3c(struct IdPairObject *self, unsigned int *out_a, unsigned int *out_b)
{
  void *registry;

  registry = FUN_08a50fbc();
  *out_a = FUN_08a52b38(registry, self->id_a);
  registry = FUN_08a50fbc();
  *out_b = FUN_08a52b38(registry, self->id_b);
}
