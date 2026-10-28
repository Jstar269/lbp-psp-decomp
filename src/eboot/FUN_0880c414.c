/* LBPMATCH module=EBOOT.BIN start=0x0880c414 end=0x0880c450 symbol=FUN_0880c414 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd3a_flags298.h"

/* Returns 1 when the target exists, its flag_298 is clear and neither flag_6c nor flag_2b7 is set. */
unsigned int FUN_0880c414(struct FlagObj298Ref *self)
{
  struct FlagObj298 *target;
  unsigned int result;

  target = self->target;
  result = 0;
  if (target != 0 && target->flag_298 == 0) {
    result = 1;
    if (target->flag_6c != 0 || target->flag_2b7 != 0) {
      result = 0;
    }
  }
  return result;
}
