/* LBPMATCH module=EBOOT.BIN start=0x08b8b220 end=0x08b8b234 symbol=FUN_08b8b220 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd4c_cowstring.h"

extern int *FUN_08b8b160();

/* Range form of FUN_08b8b160: the two pointers into the string's characters become (offset, length). */
void FUN_08b8b220(struct Rd4cCowString *str, char *first, char *last, unsigned int count, char fill)
{
  FUN_08b8b160(str, first - str->data, last - first, count, fill);
}
