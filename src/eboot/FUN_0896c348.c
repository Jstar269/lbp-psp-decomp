/* LBPMATCH module=EBOOT.BIN start=0x0896c348 end=0x0896c398 symbol=FUN_0896c348 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd2a_list.h"

/* Walks the circular list headed by `head` and passes each node's payload (+8) and `arg` to FUN_0896aeec. */
extern void FUN_0896aeec();

void FUN_0896c348(struct ListNode *head, int arg)
{
  struct ListNode *node;

  for (node = head->next; node != head; node = node->next) {
    FUN_0896aeec(node->data, arg);
  }
  return;
}
