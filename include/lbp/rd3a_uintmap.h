#ifndef LBP_RD3A_UINTMAP_H
#define LBP_RD3A_UINTMAP_H

/* Node of a tree-based map keyed by unsigned int (shape of a libstdc++ red-black tree node):
   four link words, then the key, then the mapped value at +0x14. */
struct UIntMapNode {
  unsigned int links[4];   /* +0: colour, parent, left, right */
  unsigned int key;        /* +0x10 */
  /* mapped value follows at +0x14 */
};

/* Node variant whose mapped value is one 32-bit word. */
struct UIntMapNode32 {
  struct UIntMapNode node;
  unsigned int value;      /* +0x14 */
};

/* The map object: one word, then the embedded end() sentinel node. */
struct UIntMap {
  unsigned int unk_00;
  struct UIntMapNode end_node;   /* +4 */
};

/* Key/value pair handed to the insert helper; only the first words are initialised. */
struct UIntMapPair {
  unsigned int key;
  unsigned int value[3];
};

#define UINTMAP_VALUE_OFFSET 0x14

#endif
