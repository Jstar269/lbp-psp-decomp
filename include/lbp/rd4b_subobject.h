#ifndef LBP_RD4B_SUBOBJECT_H
#define LBP_RD4B_SUBOBJECT_H

#include "lbp/rd3b_vobject.h"

/* An object that owns one polymorphic sub-object through a pointer at +0xa8. The release routines call its
   virtual slot 1 (vtable + 4) on the sub-object and clear the pointer. Everything else in the owner is untouched
   by them. */
struct SubObjectOwner {
  char pad_00[0xa8];
  struct VObj *sub_object;   /* +0xa8 */
};

#endif
