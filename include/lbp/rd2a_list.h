#ifndef LBP_RD2A_LIST_H
#define LBP_RD2A_LIST_H

/* Node of the game's circular linked list (12 bytes, allocated from the game heap). The list header
   is itself a node of this shape, embedded in the owning object, and ends iteration (end()). */
struct ListNode {
  struct ListNode *next;   /* +0 */
  void *unk_04;            /* +4: the other link (never read by these helpers) */
  void *data;              /* +8: the payload pointer */
};

#define LIST_NODE_SIZE 0xc

#endif
