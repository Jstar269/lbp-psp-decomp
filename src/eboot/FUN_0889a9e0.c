/* LBPMATCH module=EBOOT.BIN start=0x0889a9e0 end=0x0889aa54 symbol=FUN_0889a9e0 lang=c99 cc=gcc404xs-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g14); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_vector.h"

extern int FUN_0889a918();   /* erase [first, last) */

/* Calls virtual slot 1 (vtable + 4) on every non-null element except `keep`, then erases the whole array. */
void FUN_0889a9e0(struct PtrVector *vec, struct VObject *keep)
{
  struct VObject **it = vec->begin;

  while (it != vec->end) {
    struct VObject *obj = *it;
    it++;
    if (obj != 0 && keep != obj) {
      (*obj->vtable[1])(obj);
    }
  }
  FUN_0889a918(vec, vec->begin, it);
}
