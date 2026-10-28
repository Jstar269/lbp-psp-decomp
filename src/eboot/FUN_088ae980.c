/* LBPMATCH module=EBOOT.BIN start=0x088ae980 end=0x088ae998 symbol=FUN_088ae980 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_skipnode.h"

/* The node after the cursor's, stepping over `end` when it is reached; the cursor does not move. */
struct Rd4cSkipNode *FUN_088ae980(struct Rd4cSkipCursor *cursor, struct Rd4cSkipNode *end)
{
  struct Rd4cSkipNode *next;

  next = cursor->node->next;
  if (next == end) {
    next = next->next;
  }
  return next;
}
