/* LBPMATCH module=EBOOT.BIN start=0x08b8c4a0 end=0x08b8c4ac symbol=FUN_08b8c4a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_cowstring.h"

extern int *FUN_08b8c17c();

/* Forwards the other string's characters and length (word at data - 12) to FUN_08b8c17c. */
void FUN_08b8c4a0(struct Rd4cCowString *str, unsigned int pos, unsigned int count, struct Rd4cCowString *src)
{
  FUN_08b8c17c(str, pos, count, src->data, ((unsigned int *)src->data)[-3]);
}
