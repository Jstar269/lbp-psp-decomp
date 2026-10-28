/* LBPMATCH module=EBOOT.BIN start=0x088f3748 end=0x088f37d0 symbol=FUN_088f3748 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_stateobj.h"

extern int FUN_08881018();
extern void FUN_08881bf8();
extern void FUN_088ed040();

/* Unless the state is already 0x12..0x14, run the sequence below and enter state 0x12. */
void FUN_088f3748(struct StateObj *self, unsigned int *arg1)
{
  if (2 < (unsigned int)(self->state - 0x12)) {
    FUN_08881bf8(self->unk_40, 4);
    self->unk_48 = 1;
    FUN_08881018(self->unk_40, 4, arg1, 0);
    self->state = 0x12;
    FUN_088ed040(self, 1);
  }
}
