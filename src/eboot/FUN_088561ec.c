/* LBPMATCH module=EBOOT.BIN start=0x088561ec end=0x08856228 symbol=FUN_088561ec lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_rbtree.h"

extern void FUN_08856114();

/* Tree clear(): erase every node below the root, then reset the header to the empty state. */
void FUN_088561ec(struct RbTree *tree)
{
  FUN_08856114(tree, tree->header.parent);
  tree->header.right = &tree->header;
  tree->count = 0;
  tree->header.left = &tree->header;
  tree->header.parent = 0;
}
