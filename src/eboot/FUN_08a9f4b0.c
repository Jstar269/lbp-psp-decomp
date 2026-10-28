/* LBPMATCH module=EBOOT.BIN start=0x08a9f4b0 end=0x08a9f544 symbol=FUN_08a9f4b0 lang=c99 cc=gcc402x-Os */
/* Clone of src/eboot/FUN_0888da24.c (lbpclone.py tag r-rd1a): addresses substituted; exact match verified; names and types await human review. */

#include "lbp/rbnode.h"

struct Tree08a9f4b0 {
  char pad[4];
  struct RbNode header;         /* sentinel node: parent is the root */
  unsigned int node_count;
};

extern struct RbNode *FUN_08a9f3fc(struct Tree08a9f4b0 *tree, unsigned int *key);
extern void FUN_08b899e4(int insert_left, struct RbNode *node, struct RbNode *parent, struct RbNode *header);

/* Allocates a node for key and links it under parent (x, when non-null, forces a left insert), then counts it. */
struct RbNode *FUN_08a9f4b0(struct Tree08a9f4b0 *tree, int x, struct RbKeyNode *parent, unsigned int *key)
{
  struct RbNode *node;
  int insert_left;

  if ((x != 0) ||
     ((insert_left = 1, (struct RbNode *)parent != &tree->header &&
      (insert_left = 0, *key < parent->key)))) {
    insert_left = 1;
  }
  node = FUN_08a9f3fc(tree, key);
  FUN_08b899e4(insert_left, node, (struct RbNode *)parent, &tree->header);
  tree->node_count = tree->node_count + 1;
  return node;
}
