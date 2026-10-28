/* LBPMATCH module=EBOOT.BIN start=0x088aea80 end=0x088aeafc symbol=FUN_088aea80 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_list.h"

extern unsigned int DAT_08be84a0;   /* the game heap */
extern void FUN_08adbc24();         /* heap free(heap, ptr, size) */
extern void FUN_08b88fc8();         /* unlink node from its list */

/* Erases the nodes from *first up to (not including) last: unlinks each and returns it to the heap.
   An iterator sitting on the header node is first moved past it. header and last are word pointers
   here because that is the pointer mix the original compare needs. */
void FUN_088aea80(unsigned int *header, struct ListNode **first, unsigned int *last)
{
  struct ListNode *node;
  struct ListNode *next;

  node = *first;
  if (node == header) {
    node = node->next;
  }
  while (node != last) {
    next = node->next;
    FUN_08b88fc8(node);
    FUN_08adbc24(DAT_08be84a0, node, LIST_NODE_SIZE);
    node = next;
    if (next == header) {
      node = next->next;
    }
  }
}
