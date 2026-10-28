/* LBPMATCH module=EBOOT.BIN start=0x088ae960 end=0x088ae980 symbol=FUN_088ae960 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_skipnode.h"

/* Advances the cursor to the next node, stepping over `end` when it is reached. */
void FUN_088ae960(struct Rd4cSkipCursor *cursor, struct Rd4cSkipNode *end)
{
  struct Rd4cSkipNode *next;

  next = cursor->node->next;
  cursor->node = next;
  if (next == end) {
    cursor->node = next->next;
  }
}
