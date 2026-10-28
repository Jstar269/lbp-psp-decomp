/* LBPMATCH module=EBOOT.BIN start=0x08a94484 end=0x08a944e0 symbol=FUN_08a94484 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_pair.h"

/* Returns 1 when FUN_08a09e30 accepts the pair and the summed element values are not zero, else 0. */
extern unsigned int FUN_08a09e30();

unsigned int FUN_08a94484(struct Rd3dPair *pair)
{
  int accepted;
  unsigned int result;

  accepted = FUN_08a09e30(pair);
  result = 1;
  if ((accepted == 0) || (pair->first->value_18 + pair->second->value_18 == 0.0f)) {
    result = 0;
  }
  return result;
}
