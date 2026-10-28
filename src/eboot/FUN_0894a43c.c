/* LBPMATCH module=EBOOT.BIN start=0x0894a43c end=0x0894a488 symbol=FUN_0894a43c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd2a_sizedbuf.h"

extern void FUN_08a9df6c(void *data);

/* Frees the owner's buffer (data and size are cleared) and sets the float *out to 0. */
void FUN_0894a43c(struct BufferOwner *owner, float *out)
{
  struct SizedBuffer *buffer;

  buffer = owner->buffer;
  if (buffer->data != 0) {
    FUN_08a9df6c(buffer->data);
    buffer->data = 0;
  }
  buffer->size = 0;
  *out = 0;
  return;
}
