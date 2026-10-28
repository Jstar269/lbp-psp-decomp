/* Node of a red-black tree as used by the rotation and insertion helpers (FUN_08b89924, FUN_08b89984,
   FUN_0888da24). The shape (parent, left, right at +4/+8/+0xc, key after them) matches a libstdc++ style tree. */
#ifndef LBP_RBNODE_H
#define LBP_RBNODE_H

struct RbNode {
  unsigned int unk_00;          /* colour in a standard red-black node */
  struct RbNode *parent;
  struct RbNode *left;
  struct RbNode *right;
};

/* A node of the tree whose key is stored right after the links. */
struct RbKeyNode {
  struct RbNode links;
  unsigned int key;
};

#endif
