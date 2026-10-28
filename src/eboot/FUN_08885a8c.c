/* LBPMATCH module=EBOOT.BIN start=0x08885a8c end=0x08885aec symbol=FUN_08885a8c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_locked.h"

extern void FUN_088859e4();
extern void FUN_0888b8c4();
extern void FUN_0888b8cc();

void FUN_08885a8c(struct Rd4dLocked30 *self, int *arg1, unsigned int arg2)
{
  FUN_0888b8c4(&self->unk_30);
  FUN_088859e4(self, arg1, arg2);
  FUN_0888b8cc(&self->unk_30);
  return;
}
