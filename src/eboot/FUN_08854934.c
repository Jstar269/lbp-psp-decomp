/* LBPMATCH module=EBOOT.BIN start=0x08854934 end=0x08854970 symbol=FUN_08854934 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_rbtree.h"

extern void FUN_088547f4();

/* Tree clear(): erase every node below the root, then reset the header to the empty state. */
void FUN_08854934(struct RbTree *tree)
{
  FUN_088547f4(tree, tree->header.parent);
  tree->header.right = &tree->header;
  tree->count = 0;
  tree->header.left = &tree->header;
  tree->header.parent = 0;
}
