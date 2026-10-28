/* LBPMATCH module=EBOOT.BIN start=0x08914484 end=0x08914514 symbol=FUN_08914484 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd2a_list.h"

extern void *DAT_08be84a0;
extern void FUN_088050b8();
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

/* Walks the circular list headed by head and removes every node whose payload equals *target:
   unlinks it (FUN_08b88fc8), frees the payload (FUN_088050b8) and frees the node (FUN_08adbc24). */
void FUN_08914484(struct ListNode *head, void **target)
{
  struct ListNode *node;
  struct ListNode *next;

  next = head->next;
  while (node = next, node != head) {
    next = node->next;
    if (node->data == *target) {
      FUN_08b88fc8(node);
      if (node->data != 0) {
        FUN_088050b8(node->data);
      }
      FUN_08adbc24(DAT_08be84a0, node, LIST_NODE_SIZE);
    }
  }
}
