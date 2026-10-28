/* LBPMATCH module=EBOOT.BIN start=0x0888da24 end=0x0888dab8 symbol=FUN_0888da24 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

#include "lbp/rbnode.h"

struct Tree0888da24 {
  char pad[4];
  struct RbNode header;         /* sentinel node: parent is the root */
  unsigned int node_count;
};

extern struct RbNode *FUN_0888d9a8(struct Tree0888da24 *tree, unsigned int *key);
extern void FUN_08b899e4(int insert_left, struct RbNode *node, struct RbNode *parent, struct RbNode *header);

/* Allocates a node for key and links it under parent (x, when non-null, forces a left insert), then counts it. */
struct RbNode *FUN_0888da24(struct Tree0888da24 *tree, int x, struct RbKeyNode *parent, unsigned int *key)
{
  struct RbNode *node;
  int insert_left;

  if ((x != 0) ||
     ((insert_left = 1, (struct RbNode *)parent != &tree->header &&
      (insert_left = 0, *key < parent->key)))) {
    insert_left = 1;
  }
  node = FUN_0888d9a8(tree, key);
  FUN_08b899e4(insert_left, node, (struct RbNode *)parent, &tree->header);
  tree->node_count = tree->node_count + 1;
  return node;
}
