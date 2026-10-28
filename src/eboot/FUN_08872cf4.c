/* LBPMATCH module=EBOOT.BIN start=0x08872cf4 end=0x08872d14 symbol=FUN_08872cf4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_list.h"

extern void FUN_08872ad8();

/* Initialise `self` as an empty circular list, then pass FUN_08872ad8 the range from other->next to `other`. */
void FUN_08872cf4(struct ListLink *self, struct ListLink *other)
{
  struct ListLink *first;

  self->next = self;
  first = other->next;
  self->prev = self;
  FUN_08872ad8(self, self, first, other);
}
