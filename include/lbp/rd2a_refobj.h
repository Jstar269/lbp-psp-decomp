#ifndef LBP_RD2A_REFOBJ_H
#define LBP_RD2A_REFOBJ_H

/* Reference-counted object as the handle-copy helpers see it: a 16-bit count at +6. A handle is a
   pointer to one of these; copying a handle bumps the count and FUN_08970b6c(obj) drops it again. */
struct RefCounted {
  char unk_00[6];
  short ref_count;   /* +6 */
};

#endif
