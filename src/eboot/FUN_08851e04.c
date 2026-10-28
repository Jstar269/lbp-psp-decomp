/* LBPMATCH module=EBOOT.BIN start=0x08851e04 end=0x08851e40 symbol=FUN_08851e04 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
#include "lbp/rd3c_rbtree.h"

extern void FUN_08851cd0();

/* Tree clear(): erase every node below the root, then reset the header to the empty state. */
void FUN_08851e04(struct RbTree *tree)
{
  FUN_08851cd0(tree, tree->header.parent);
  tree->header.right = &tree->header;
  tree->count = 0;
  tree->header.left = &tree->header;
  tree->header.parent = 0;
}
