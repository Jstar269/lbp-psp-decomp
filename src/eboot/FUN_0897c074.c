/* LBPMATCH module=EBOOT.BIN start=0x0897c074 end=0x0897c0d8 symbol=FUN_0897c074 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern int FUN_0897c010();

/* Calls virtual slot 1 (the +4 entry) of every non-null object pointer in the
   array, then hands the storage to FUN_0897c010. */
void FUN_0897c074(struct PtrVector *vec)
{
  struct VObject *obj;
  struct VObject **cursor;

  cursor = vec->begin;
  while (cursor != vec->end) {
    obj = *cursor;
    cursor = cursor + 1;
    if (obj != 0) {
      (*obj->vtable[1])(obj);
    }
  }
  FUN_0897c010(vec, vec->begin, cursor);
}
