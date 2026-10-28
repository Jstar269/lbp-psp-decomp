#ifndef LBP_RD2A_VECTOR_H
#define LBP_RD2A_VECTOR_H

#include "lbp/rd2a_object.h"

/* Growable arrays as the resize/erase helpers see them: a begin pointer at +0 and a one-past-the-end
   pointer at +4 (size = end - begin). Further fields (if any) are not touched by these helpers. */
struct U32Vector {
  unsigned int *begin;
  unsigned int *end;
};

struct U8Vector {
  unsigned char *begin;
  unsigned char *end;
};

/* Array of object pointers. */
struct PtrVector {
  struct VObject **begin;
  struct VObject **end;
};

#endif
