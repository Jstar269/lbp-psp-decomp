/* LBPMATCH module=EBOOT.BIN start=0x088a1954 end=0x088a19b4 symbol=FUN_088a1954 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd2a_object.h"

extern int FUN_0889ce7c();

/* Callback with five arguments of which only the last three matter: when FUN_0889ce7c reports nonzero,
   virtual slot 2 of the receiver is called with arg_c and arg_d. Always returns 0xc. */
unsigned int FUN_088a1954(int unused_a, int unused_b, int arg_c, int arg_d, struct VObject *receiver)
{
  int active;

  active = FUN_0889ce7c();
  if (active != 0) {
    (*receiver->vtable[2])(receiver, arg_c, arg_d);
  }
  return 0xc;
}
