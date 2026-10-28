/* LBPMATCH module=EBOOT.BIN start=0x08979324 end=0x0897935c symbol=FUN_08979324 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_rbkeymap.h"

/* Upper-bound search in a tree with signed keys: the first node whose key is greater than *key,
   or the end() header when there is none. */
struct RbS32Node *FUN_08979324(struct RbS32Map *map, const int *key)
{
  struct RbS32Node *result;
  struct RbS32Node *node;

  result = &map->header;
  node = map->header.parent;
  while (node != 0) {
    if (*key < node->key) {
      result = node;
      node = node->left;
    }
    else {
      node = node->right;
    }
  }
  return result;
}
