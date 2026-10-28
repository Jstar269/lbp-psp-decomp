#ifndef LBP_RD4C_FREEBUF_H
#define LBP_RD4C_FREEBUF_H

/* Object with a heap pointer at +4 and a size word at +8; FUN_0891bee0 and FUN_0894fb20 release the
   allocation (FUN_08a9df6c) and clear both. */
struct Rd4cFreeBuf {
  char unk_00[4];
  void *data;            /* +4: released, then cleared */
  unsigned int size;     /* +8: cleared */
};

#endif
