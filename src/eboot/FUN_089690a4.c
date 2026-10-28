/* LBPMATCH module=EBOOT.BIN start=0x089690a4 end=0x089690c8 symbol=FUN_089690a4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd4a_gecmd.h"

/* Appends a PRIM (triangle strip) command word to the command list. */
void FUN_089690a4(struct PrimEmitter *self)
{
  unsigned int count;
  unsigned int *cursor;

  count = self->count;
  cursor = self->list->cursor;
  self->list->cursor = cursor + 1;
  *cursor = count | GE_CMD_PRIM_TRIANGLE_STRIP;
  return;
}
