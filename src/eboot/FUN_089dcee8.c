/* LBPMATCH module=EBOOT.BIN start=0x089dcee8 end=0x089dcf3c symbol=FUN_089dcee8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_chain.h"

extern void FUN_089dd21c();

/* Tells every entry's target whether it is the selected one (compared by target). */
void FUN_089dcee8(struct ChainOwner *owner, int selected)
{
  struct ChainNode *head = &owner->head;
  struct ChainNode *node;

  for (node = head->next; node != head; node = node->next) {
    FUN_089dd21c(node->target, node->target == selected);
  }
}
