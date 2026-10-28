/* LBPMATCH module=EBOOT.BIN start=0x08897d34 end=0x08897d70 symbol=FUN_08897d34 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_rbtree.h"

extern void FUN_08897c5c();

/* Tree clear(): erase every node below the root, then reset the header to the empty state. */
void FUN_08897d34(struct RbTree *tree)
{
  FUN_08897c5c(tree, tree->header.parent);
  tree->header.right = &tree->header;
  tree->count = 0;
  tree->header.left = &tree->header;
  tree->header.parent = 0;
}
