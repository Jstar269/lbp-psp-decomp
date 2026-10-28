/* LBPMATCH module=EBOOT.BIN start=0x08a3e1ec end=0x08a3e210 symbol=FUN_08a3e1ec lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_kindflags.h"

/* Sets flag bit 0 of the second object when the first one has kind 0x26. */
void FUN_08a3e1ec(unsigned int unused, struct Rd4dKindObj *kind_obj, struct Rd4dFlagsObj *flags_obj)
{
  if (kind_obj->kind_44 == RD4D_KIND_26) {
    flags_obj->flags_ac = flags_obj->flags_ac | 1;
    return;
  }
  return;
}
