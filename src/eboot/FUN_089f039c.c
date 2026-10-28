/* LBPMATCH module=EBOOT.BIN start=0x089f039c end=0x089f0404 symbol=FUN_089f039c lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd2a_object.h"

extern void FUN_08804f3c();
extern struct ServiceObj *FUN_089ecaa8();

/* Object returned by FUN_089ecaa8; a sub-object with virtual functions sits at +0x9c. */
struct ServiceObj {
  unsigned char unk_00[0x9c];
  struct VObject sub_9c;   /* +0x9c */
};

/* Asks sub_9c (virtual slot 14) for a 16-byte result, calls its target's virtual slot 13 with the two
   arguments and the constant 2, then releases the result through FUN_08804f3c. */
void FUN_089f039c(int arg_a, int arg_b)
{
  struct ServiceObj *service;
  struct VObject *result[4];

  service = FUN_089ecaa8();
  (*service->sub_9c.vtable[0x38 / 4])(result, &service->sub_9c);
  (*result[0]->vtable[0x34 / 4])(result[0], arg_a, arg_b, 2);
  FUN_08804f3c(result);
}
