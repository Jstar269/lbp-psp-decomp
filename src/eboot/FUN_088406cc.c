/* LBPMATCH module=EBOOT.BIN start=0x088406cc end=0x0884072c symbol=FUN_088406cc lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
#include "lbp/rd2b_bufowner.h"

extern void FUN_088050b8();   /* release of the sub-object at +0x10 */
extern void FUN_08a9e11c();   /* release of the buffer at +4 */

/* Releases the sub-object and the buffer. With skip_buffer_free set the buffer pointer is
   just forgotten (cleared) instead of being released. */
void FUN_088406cc(struct BufferOwner *self, unsigned char skip_buffer_free)
{
  void *owned;

  owned = self->owned;
  if (owned != 0) {
    self->owned = 0;
    FUN_088050b8(owned);
  }
  if (skip_buffer_free != 0) {
    self->buffer = 0;
  }
  if (self->buffer != 0) {
    FUN_08a9e11c(self->buffer);
    self->buffer = 0;
  }
}
