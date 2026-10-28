/* LBPMATCH module=EBOOT.BIN start=0x08a60b6c end=0x08a60b90 symbol=FUN_08a60b6c lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_kindflags.h"

/* Same as FUN_08a3e1ec. */
void FUN_08a60b6c(unsigned int unused, struct Rd4dKindObj *kind_obj, struct Rd4dFlagsObj *flags_obj)
{
  if (kind_obj->kind_44 == RD4D_KIND_26) {
    flags_obj->flags_ac = flags_obj->flags_ac | 1;
    return;
  }
  return;
}
