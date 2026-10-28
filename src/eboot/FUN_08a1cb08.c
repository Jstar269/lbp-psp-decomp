/* LBPMATCH module=EBOOT.BIN start=0x08a1cb08 end=0x08a1cba0 symbol=FUN_08a1cb08 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_scratch.h"

extern void FUN_08921788();   /* construct a ScratchObject */
extern void FUN_089218fc();   /* (scratch, value, extra) */
extern void FUN_0892194c();
extern void FUN_08921a38();   /* destroy a ScratchObject */
extern void FUN_08a1c648();   /* (target, scratch) */

/* When `record` is set, builds a scratch object from (*value, extra), hands it to the target at +0xa8
   and marks the host as recorded; then always calls virtual slot 5 with the value. Returns 1. */
int FUN_08a1cb08(struct RecordingHost *self, int unused, int *value, int extra, unsigned char record)
{
  struct ScratchObject scratch;

  if (record != '\0') {
    FUN_08921788(&scratch);
    FUN_089218fc(&scratch, *value, extra);
    FUN_08a1c648(self->target, &scratch);
    FUN_0892194c(&scratch);
    self->recorded = 1;
    FUN_08921a38(&scratch);
  }
  (*self->vtable[5])(self, value);
  return 1;
}
