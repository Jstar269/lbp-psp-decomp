/* LBPMATCH module=EBOOT.BIN start=0x089dcfac end=0x089dd004 symbol=FUN_089dcfac lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_chain.h"

extern void FUN_089dd21c();

/* Same walk as FUN_089dcee8, but the selection is matched against each entry's key (+8). */
void FUN_089dcfac(struct ChainOwner *owner, int selected)
{
  struct ChainNode *head = &owner->head;
  struct ChainNode *node;

  for (node = head->next; node != head; node = node->next) {
    FUN_089dd21c(node->target, node->key == selected);
  }
}
