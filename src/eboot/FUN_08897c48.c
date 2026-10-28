/* LBPMATCH module=EBOOT.BIN start=0x08897c48 end=0x08897c54 symbol=FUN_08897c48 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

#include "lbp/rd4a_wordpair.h"

void FUN_08897c48(struct PairHolder *self,unsigned int first,unsigned int second)
{
  self->second = second;
  self->first = first;
  return;
}
