#ifndef LBP_RD3C_CHAIN_H
#define LBP_RD3C_CHAIN_H

/* Circular doubly-linked-list node as the owner-notification loops walk it (16 bytes). The list head is a
   node of the same shape embedded in the owner at +0xc and ends the walk when reached again. */
struct ChainNode {
  struct ChainNode *next;    /* +0 */
  struct ChainNode *unk_04;  /* +4: the other link, not read by these loops */
  unsigned int key;          /* +8 */
  unsigned int target;       /* +0xc: the value handed to the per-node callee */
};

struct ChainOwner {
  char pad[0xc];
  struct ChainNode head;     /* +0xc: sentinel */
};

#endif
