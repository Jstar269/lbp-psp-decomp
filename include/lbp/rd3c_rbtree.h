#ifndef LBP_RD3C_RBTREE_H
#define LBP_RD3C_RBTREE_H

/* Bookkeeping block of a libstdc++-style red-black tree (std::set / std::map): one unused word, then the
   header node embedded at +4, which doubles as end(). header.parent is the root, header.left the leftmost
   node (begin) and header.right the rightmost; both are the header itself while the tree is empty. */
struct RbLinks {
  unsigned int color;
  struct RbLinks *parent;
  struct RbLinks *left;
  struct RbLinks *right;
};

struct RbTree {
  unsigned int unk_00;
  struct RbLinks header;       /* +4 */
  unsigned int count;          /* +0x14: number of nodes */
};

#endif
