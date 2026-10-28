/* LBPMATCH module=EBOOT.BIN start=0x088630a4 end=0x088630f4 symbol=FUN_088630a4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_stateful.h"

extern void FUN_08862da4();

/* State 1: nothing to do (returns 1). State 2: runs FUN_08862da4, falls back to state 0 and returns 1. Others: 0. */
int FUN_088630a4(struct Stateful *self)
{
  int result;

  result = 1;
  if ((self->state != 1) && (result = 0, self->state == 2)) {
    FUN_08862da4(self);
    self->state = 0;
    result = 1;
  }
  return result;
}
