#ifndef LBP_RD1C_RBTREE_H
#define LBP_RD1C_RBTREE_H

/* Red-black tree bookkeeping as the range-erase helpers see it. The header node is embedded
   at +4 and doubles as the end() sentinel; header.left is the leftmost node (begin). */
struct RbNode {
  unsigned int color;
  struct RbNode *parent;
  struct RbNode *left;
  struct RbNode *right;
};

struct RbTree {
  unsigned int unk_00;
  struct RbNode header;        /* +4 */
  unsigned int count;          /* +0x14: nodes in the tree */
};

#endif
