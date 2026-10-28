/* LBPMATCH module=EBOOT.BIN start=0x08a4ad7c end=0x08a4ae0c symbol=FUN_08a4ad7c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g4); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet); readability pass (lane rd1b, Claude Sonnet) */

#include "lbp/obj180layout.h"

extern int * FUN_08a10f1c();
extern void FUN_08a12ec0();
extern int FUN_08a50fbc();
extern int * FUN_08a52b38();
extern void FUN_08a4ab9c();
extern void FUN_08a9a5c8();

void FUN_08a4ad7c(Obj180 *self)
{
  int manager;
  int *found_a;
  int *found_b;
  int *result;

  FUN_08a9a5c8(self);
  FUN_08a4ab9c(&self->unk_180,&self->unk_184,&self->unk_188,&self->unk_18c);
  manager = FUN_08a50fbc();
  found_a = FUN_08a52b38(manager,self->key_19c);
  manager = FUN_08a50fbc();
  found_b = FUN_08a52b38(manager,self->key_1a0);
  result = FUN_08a10f1c();
  FUN_08a12ec0(result,found_a,found_b,self->unk_190,self,-1);
  return;
}
