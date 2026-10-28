#ifndef LBP_RD2B_BUFOWNER_H
#define LBP_RD2B_BUFOWNER_H

/* Object with a buffer pointer at +4 and an owned sub-object pointer at +0x10, as the two
   teardown routines FUN_088406cc / FUN_08840ae8 see it (everything else is untouched there). */
struct BufferOwner {
  char unk_00[4];
  void *buffer;       /* +4: released with FUN_08a9e11c, then cleared */
  char unk_08[8];
  void *owned;        /* +0x10: released with FUN_088050b8, then cleared */
};

#endif
