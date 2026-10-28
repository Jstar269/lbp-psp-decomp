#ifndef LBP_RD4C_SKIPNODE_H
#define LBP_RD4C_SKIPNODE_H

/* Link node whose first word is the next node. FUN_088ae960 / FUN_088ae980 step over one special node
   (the "end" node they are given) when they reach it. */
struct Rd4cSkipNode {
  struct Rd4cSkipNode *next;   /* +0 */
};

/* Cursor over those nodes: just the current node. */
struct Rd4cSkipCursor {
  struct Rd4cSkipNode *node;   /* +0 */
};

#endif
