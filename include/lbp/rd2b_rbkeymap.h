#ifndef LBP_RD2B_RBKEYMAP_H
#define LBP_RD2B_RBKEYMAP_H

/* Keyed red-black tree (std::map-like) as the upper-bound searches see it: a 4-byte word, then the
   header node at +4 which doubles as end(); header.parent is the root. A node is the 16-byte tree
   link block followed by the key at +0x10. Unsigned-key and signed-key variants differ only in the
   compare the callers emit. */
struct RbU32Node {
  unsigned int color;
  struct RbU32Node *parent;
  struct RbU32Node *left;
  struct RbU32Node *right;
  unsigned int key;           /* +0x10 */
};

struct RbU32Map {
  unsigned int unk_00;
  struct RbU32Node header;    /* +4: end() sentinel; header.parent is the root */
};

struct RbS32Node {
  unsigned int color;
  struct RbS32Node *parent;
  struct RbS32Node *left;
  struct RbS32Node *right;
  int key;                    /* +0x10 */
};

struct RbS32Map {
  unsigned int unk_00;
  struct RbS32Node header;    /* +4: end() sentinel; header.parent is the root */
};

#endif
