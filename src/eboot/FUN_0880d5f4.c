/* LBPMATCH module=EBOOT.BIN start=0x0880d5f4 end=0x0880d62c symbol=FUN_0880d5f4 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_rbkeymap.h"

/* Upper-bound search in a keyed red-black tree: the first node whose key is greater than *key,
   or the end() header when there is none. */
struct RbU32Node *FUN_0880d5f4(struct RbU32Map *map, const unsigned int *key)
{
  struct RbU32Node *result;
  struct RbU32Node *node;

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
