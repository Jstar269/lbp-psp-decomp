/* LBPMATCH module=EBOOT.BIN start=0x08898420 end=0x08898480 symbol=FUN_08898420 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_locked.h"

extern void FUN_0888b8c4();
extern void FUN_0888b8cc();
extern void FUN_08898378();

void FUN_08898420(struct Rd4dLocked2c *self, int *arg1, unsigned int arg2)
{
  FUN_0888b8c4(&self->unk_2c);
  FUN_08898378(self, arg1, arg2);
  FUN_0888b8cc(&self->unk_2c);
  return;
}
