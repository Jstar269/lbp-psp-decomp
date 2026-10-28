#ifndef LBP_RD4B_PTRLIST_H
#define LBP_RD4B_PTRLIST_H

/* The object behind the global DAT_08beee0c: two pointers at +0x1c / +0x20 that bound an array of object
   pointers (begin and one-past-the-end). Only the fields the callers read are described. */
struct PtrListHolder {
  char pad_00[0x1c];
  void **begin;   /* +0x1c */
  void **end;     /* +0x20 */
};

#endif
