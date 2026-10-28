/* LBPMATCH module=EBOOT.BIN start=0x08a0bbc4 end=0x08a0bc24 symbol=FUN_08a0bbc4 lang=c99 cc=gcc402x-O2 rodata=0x08bab59c */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
#include "lbp/rd3d_pair.h"

/* Runs two setup calls on the pair, then caches the reciprocal of the summed element values when positive. */
extern void FUN_08a0b680();
extern void FUN_08a0bacc();

void FUN_08a0bbc4(struct Rd3dPair *pair, unsigned char (*block)[64])
{
  float sum;

  FUN_08a0b680(pair, block);
  FUN_08a0bacc(pair);
  sum = pair->first->value_18 + pair->second->value_18;
  if (0.0f < sum) {
    pair->reciprocal_sum = 1.0f / sum;
  }
  return;
}
