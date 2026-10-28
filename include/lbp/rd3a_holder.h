#ifndef LBP_RD3A_HOLDER_H
#define LBP_RD3A_HOLDER_H

/* Object whose +0xa8 word points at the cell FUN_0891d6e4 reads (it returns *cell). */
struct HolderRef {
  unsigned char unk_00[0xa8];
  int *base_cell;              /* +0xa8 */
};

/* Owner with two HolderRef pointers, at +0x2a4 and +0x2a8 (either may be null). */
struct HolderOwner {
  unsigned char unk_00[0x2a4];
  struct HolderRef *ref_2a4;   /* +0x2a4 */
  struct HolderRef *ref_2a8;   /* +0x2a8 */
};

#endif
