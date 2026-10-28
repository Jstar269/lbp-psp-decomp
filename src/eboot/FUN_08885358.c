/* LBPMATCH module=EBOOT.BIN start=0x08885358 end=0x08885394 symbol=FUN_08885358 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_rbtree.h"

extern void FUN_08885280();

/* Tree clear(): erase every node below the root, then reset the header to the empty state. */
void FUN_08885358(struct RbTree *tree)
{
  FUN_08885280(tree, tree->header.parent);
  tree->header.right = &tree->header;
  tree->count = 0;
  tree->header.left = &tree->header;
  tree->header.parent = 0;
}
