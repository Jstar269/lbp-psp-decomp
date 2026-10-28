/* LBPMATCH module=EBOOT.BIN start=0x08854970 end=0x08854a00 symbol=FUN_08854970 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd1c_rbtree.h"

extern void FUN_08850008();
extern void FUN_08854934();
extern struct RbNode *FUN_08b89838();

/* Erase the node range [first, last): the whole tree in one call, otherwise node by node (the successor is
   fetched before each erase). */
void FUN_08854970(struct RbTree *tree, struct RbNode *first, struct RbNode *last)
{
  struct RbNode *next;

  if (first == tree->header.left && last == &tree->header) {
    FUN_08854934(tree);
    return;
  }
  while (first != last) {
    next = FUN_08b89838(first);
    FUN_08850008(tree, first);
    first = next;
  }
}
