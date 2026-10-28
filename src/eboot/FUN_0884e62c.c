/* LBPMATCH module=EBOOT.BIN start=0x0884e62c end=0x0884e680 symbol=FUN_0884e62c lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_statuspair.h"

extern unsigned int FUN_0884e4a4();

/* Always accepts when pair->unk_00 is 0 (after calling FUN_0884e4a4); otherwise only the pair (2, 0x194). */
int FUN_0884e62c(struct IntPair *pair, unsigned int unused, struct PairPayload *payload)
{
  int result;

  if (pair->unk_00 == 0) {
    FUN_0884e4a4(payload->unk_0c, &payload->unk_10);
    result = 1;
  }
  else {
    result = 1;
    if (pair->unk_00 != 2 || pair->unk_04 != 0x194) {
      result = 0;
    }
  }
  return result;
}
