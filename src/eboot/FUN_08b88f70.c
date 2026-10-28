/* LBPMATCH module=EBOOT.BIN start=0x08b88f70 end=0x08b88fac symbol=FUN_08b88f70 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

/* Doubly linked list node: `next` is the first word, `prev` the second; `prev` points at the previous node's first word. */
typedef struct ListNode {
  struct ListNode *next;
  struct ListNode **prev;
} ListNode;

/* Three-way node exchange: a takes c's place, c takes b's place and b takes a's place in their lists. */
void FUN_08b88f70(ListNode *a, ListNode *b, ListNode *c)
{
  struct ListNode **a_prev;
  struct ListNode **b_prev;
  struct ListNode **c_prev;
  struct ListNode **tmp;

  if (a != c) {
    c_prev = c->prev;
    b_prev = b->prev;
    a_prev = a->prev;
    a->prev = c_prev;
    tmp = b->prev;
    *c_prev = (ListNode *)a;
    c->prev = tmp;
    *b_prev = (ListNode *)c;
    b->prev = a_prev;
    *a_prev = (ListNode *)b;
  }
  return;
}
