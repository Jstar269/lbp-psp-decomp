/* LBPMATCH module=EBOOT.BIN start=0x088ea3b4 end=0x088ea448 symbol=FUN_088ea3b4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_stateobj.h"

extern unsigned char FUN_0887f414();
extern void FUN_088e68a0();
extern void FUN_088ea1f0();

/* Only acts in state 0x17: moves to 0x18; with flag == 0 it also runs the two follow-up calls. */
void FUN_088ea3b4(struct StateObj *self, unsigned char flag)
{
  if (self->state == 0x17) {
    self->state = 0x18;
    FUN_0887f414(self->unk_40, 3);
    if (self->unk_a0 != 0) {
      self->unk_a0 = 0;
    }
    if (flag == 0) {
      FUN_088ea1f0(self, 0, 0x35);
      FUN_088e68a0(self, 1, 0x16);
    }
  }
}
