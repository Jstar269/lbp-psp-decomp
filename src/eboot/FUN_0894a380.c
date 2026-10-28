/* LBPMATCH module=EBOOT.BIN start=0x0894a380 end=0x0894a3e4 symbol=FUN_0894a380 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_sizedbuf.h"

extern void *FUN_08a9e4a4();   /* allocate(size, 0, 0); returns 0 on failure */

/* Allocates `size` bytes into the owner's SizedBuffer (recording size 0 when the allocation fails)
   and sets total_size to the recorded size plus 8. */
void FUN_0894a380(struct BufferOwner *self, int size)
{
  struct SizedBuffer *buf;
  struct SizedBuffer *buf_again;
  void *data;
  int recorded;

  buf = self->buffer;
  data = FUN_08a9e4a4(size, 0, 0);
  buf_again = self->buffer;
  if (data == 0) {
    size = 0;
  }
  buf->size = size;
  recorded = buf_again->size;
  buf->data = data;
  self->total_size = recorded + 8;
}
