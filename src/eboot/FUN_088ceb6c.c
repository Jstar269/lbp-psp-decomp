/* LBPMATCH module=EBOOT.BIN start=0x088ceb6c end=0x088ceb7c symbol=FUN_088ceb6c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
#include "lbp/rd4b_ptrlist.h"

extern struct PtrListHolder *DAT_08beee0c;
extern void FUN_088e70dc(struct PtrListHolder *target, int arg);

void FUN_088ceb6c(void)
{
  FUN_088e70dc(DAT_08beee0c, 0);
  return;
}
