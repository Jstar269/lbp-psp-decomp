/* LBPMATCH module=EBOOT.BIN start=0x088565c4 end=0x0885663c symbol=FUN_088565c4 lang=c99 cc=gcc402t-Os rodata=0x08baf258 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g5); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_stateful.h"

extern void FUN_08855564();
extern void FUN_08855ee0();
extern void FUN_08856468();

/* Runs the handler for the current state (0, 1 or 2); returns 1 only for states 3 and 4. */
int FUN_088565c4(struct Stateful *self)
{
  int result;

  result = 0;
  switch (self->state) {
  case 0:
    FUN_08855564(self);
    result = 0;
    break;
  case 1:
    FUN_08856468(self);
    result = 0;
    break;
  case 2:
    FUN_08855ee0(self);
    result = 0;
    break;
  case 3:
  case 4:
    result = 1;
  }
  return result;
}
