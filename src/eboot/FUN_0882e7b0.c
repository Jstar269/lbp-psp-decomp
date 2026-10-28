/* LBPMATCH module=EBOOT.BIN start=0x0882e7b0 end=0x0882e830 symbol=FUN_0882e7b0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
/* Circular doubly linked list: the head is a sentinel node and next/prev sit at +0 / +4. */
struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  char unk_08[8];
  char payload[0x20];            /* +0x10 */
};

#define LIST_NODE_SIZE 0x30      /* size passed to the deallocator */

extern void *DAT_08be84a0;       /* allocator-like object that FUN_08adbc24 frees into */
extern int FUN_0882d9bc();       /* payload comparison, non-zero when they match */
extern void FUN_08adbc24();
extern void FUN_08b88fc8();      /* unlinks a node from its neighbours */

/* Unlinks and frees every node whose payload matches *value. */
void FUN_0882e7b0(struct ListNode *head, const void *value)
{
  struct ListNode *node;
  struct ListNode *next;

  for (node = head->next; node != head; node = next) {
    next = node->next;
    if (FUN_0882d9bc(node->payload, value) != 0) {
      FUN_08b88fc8(node);
      FUN_08adbc24(DAT_08be84a0, node, LIST_NODE_SIZE);
    }
  }
}
