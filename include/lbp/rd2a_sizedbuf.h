#ifndef LBP_RD2A_SIZEDBUF_H
#define LBP_RD2A_SIZEDBUF_H

/* A heap buffer and its size in bytes. */
struct SizedBuffer {
  void *data;    /* +0: allocation, or 0 when it failed */
  int size;      /* +4 */
};

/* Object that owns a SizedBuffer through a pointer at +0xa8 and keeps a derived size at +0xac. */
struct BufferOwner {
  char unk_00[0xa8];
  struct SizedBuffer *buffer;   /* +0xa8 */
  int total_size;               /* +0xac: buffer size + 8 */
};

#endif
