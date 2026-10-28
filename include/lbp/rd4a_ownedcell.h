#ifndef LBP_RD4A_OWNEDCELL_H
#define LBP_RD4A_OWNEDCELL_H

/* An object that owns one heap block through the pointer at +0xa8 and clears it when it lets go. */
struct ImplOwner {
  char unk_00[0xa8];
  void *impl;              /* +0xa8 */
};

/* Two-word block: a handle that is released first, then a second word cleared. */
struct HandleCell {
  unsigned int handle;     /* +0 */
  unsigned int unk_04;     /* +4 */
};

struct CellOwner {
  char unk_00[0xa8];
  struct HandleCell *cell; /* +0xa8 */
};

#endif
