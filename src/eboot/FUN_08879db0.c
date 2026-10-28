/* LBPMATCH module=EBOOT.BIN start=0x08879db0 end=0x08879e18 symbol=FUN_08879db0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_rbtree.h"

struct KeyedNode {
  struct RbNode links;          /* left/right child pointers at +8/+0xc */
  unsigned char key[1];         /* +0x10: NUL-terminated key */
};

extern int FUN_08ba0d98();      /* compares two NUL-terminated byte strings (strcmp-like) */

/* Descends from the root following the key order and returns the first node whose key is greater than
   key (or the header node when there is none): an upper-bound search. */
struct KeyedNode *FUN_08879db0(struct RbTree *tree, unsigned char *key)
{
  struct KeyedNode *next;
  struct KeyedNode *node;
  struct KeyedNode *result;
  int order;

  next = (struct KeyedNode *)tree->header.parent;
  result = (struct KeyedNode *)&tree->header;
  while (node = next, node != 0) {
    order = FUN_08ba0d98(key, node->key);
    if (order < 0) {
      next = (struct KeyedNode *)node->links.left;
      result = node;
    }
    else {
      next = (struct KeyedNode *)node->links.right;
    }
  }
  return result;
}
