/* LBPMATCH module=EBOOT.BIN start=0x0897f480 end=0x0897f498 symbol=FUN_0897f480 lang=c99 cc=gcc410-Os rodata=0x08bab59c */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_obj88.h"

extern void FUN_0897f268(float scale, void *self, char flag, int *unk_88, float *unk_90);

/* Calls FUN_0897f268 with scale 1.0 and flag 0 (FUN_0897f498 is the same with flag 1). */
void FUN_0897f480(struct Rd4cObj88 *self)
{
  FUN_0897f268(1.0f, self, 0, self->unk_88, &self->unk_90);
}
