/* LBPMATCH module=EBOOT.BIN start=0x0882eea0 end=0x0882ef50 symbol=FUN_0882eea0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd1c, Claude Sonnet) */
#include "lbp/rd1c_rbtree.h"

extern unsigned int DAT_08be84a0;
extern void FUN_0882ee28();
extern void FUN_08adbc24();
extern struct RbNode *FUN_08b89838();
extern struct RbNode *FUN_08b89b70();

/* Erases the nodes in [first, last). The full range [begin, end) is handed to FUN_0882ee28 instead;
   otherwise each node is unlinked and its 0x20 bytes returned to the pool at DAT_08be84a0. */
void FUN_0882eea0(struct RbTree *tree, struct RbNode *first, struct RbNode *last)
{
  struct RbNode *next;
  struct RbNode *unlinked;

  if ((first == tree->header.left) && (last == &tree->header)) {
    FUN_0882ee28(tree);
    return;
  }
  while (first != last) {
    next = FUN_08b89838(first);
    unlinked = FUN_08b89b70(first, &tree->header);
    FUN_08adbc24(DAT_08be84a0, unlinked, 0x20);
    tree->count = tree->count - 1;
    first = next;
  }
  return;
}
