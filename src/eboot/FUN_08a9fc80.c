/* LBPMATCH module=EBOOT.BIN start=0x08a9fc80 end=0x08a9fd24 symbol=FUN_08a9fc80 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd1c_rbtree.h"

extern void FUN_08a9e0cc();                /* free a tree node */
extern void FUN_08a9fc14();                /* clear the whole tree */
extern struct RbNode *FUN_08b89838();      /* in-order successor */
extern struct RbNode *FUN_08b89b70();      /* unlink a node and rebalance; returns the node to free */

/* Erases the nodes in [first, last). When the range is the whole tree (begin..end) it clears
   it in one go; otherwise each node is unlinked and freed and the count is decremented. */
void FUN_08a9fc80(struct RbTree *tree, struct RbNode *first, struct RbNode *last)
{
  struct RbNode *next;
  struct RbNode *removed;

  if (first == tree->header.left && last == &tree->header) {
    FUN_08a9fc14(tree);
    return;
  }
  while (first != last) {
    next = FUN_08b89838(first);
    removed = FUN_08b89b70(first, &tree->header);
    FUN_08a9e0cc(removed);
    tree->count = tree->count - 1;
    first = next;
  }
}
