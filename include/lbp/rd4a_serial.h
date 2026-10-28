#ifndef LBP_RD4A_SERIAL_H
#define LBP_RD4A_SERIAL_H

/* Four ASCII characters packed so the first character is the most significant byte (the chunk tags below read as
   text in a hex dump of the constant). */
#define FOURCC(a, b, c, d) \
  (((unsigned int)(a) << 24) | ((unsigned int)(b) << 16) | ((unsigned int)(c) << 8) | (unsigned int)(d))

/* Object shared by the tagged "write chunk" routines: a tag-and-stream header call, then fixed sub-blocks that
   are handed on by address. Only the sub-block addresses are used; sizes follow from the offsets. */
struct SerialObject {
  char unk_000[0x19c];
  char block_19c[0xc];     /* +0x19c */
  char block_1a8[0xc];     /* +0x1a8 */
  char block_1b4[0x28];    /* +0x1b4 */
  char block_1dc[1];       /* +0x1dc: first byte of the tail block */
};

#endif
