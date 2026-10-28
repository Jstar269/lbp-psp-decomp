/* LBPMATCH module=EBOOT.BIN start=0x08893568 end=0x088935d0 symbol=FUN_08893568 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd1c_rbtree.h"

/* A tree node whose key is a C string stored inline right after the node links. */
struct StringKeyNode {
  struct RbNode links;
  char key[1];             /* +0x10 */
};

extern int FUN_08ba0d98();   /* strcmp-style three-way compare of two C strings */

/* Upper-bound search in a string-keyed red-black tree: returns the first node whose key
   sorts after `key`, or the end() header (tree + 4) when there is none. */
struct RbNode *FUN_08893568(struct RbTree *tree, const char *key)
{
  struct RbNode *node = tree->header.parent;
  struct RbNode *result = &tree->header;

  while (node != 0) {
    if (FUN_08ba0d98(key, ((struct StringKeyNode *)node)->key) < 0) {
      result = node;
      node = node->left;
    }
    else {
      node = node->right;
    }
  }
  return result;
}
