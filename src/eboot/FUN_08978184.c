/* LBPMATCH module=EBOOT.BIN start=0x08978184 end=0x08978190 symbol=FUN_08978184 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4d, Claude Sonnet) */
#include "lbp/rd4d_intpair.h"

void FUN_08978184(struct Rd4dIntPair *pair, int first, int second)
{
  pair->second = second;
  pair->first = first;
  return;
}
