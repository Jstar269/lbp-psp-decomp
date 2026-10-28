#ifndef LBP_RD3B_VOBJECT_H
#define LBP_RD3B_VOBJECT_H

/* An object whose first word is a pointer to its table of virtual functions; slot signatures differ per class
   and the first argument is the object. Slot 1 (vtable + 4) is what these callers use to release an object. */
struct VObj {
  int (**vtable)();
};

/* Object with two owned sub-objects at +0x88 and +0x8c (FUN_0886f568 releases the first, FUN_0886f630 the second). */
struct TwoRefs {
  char pad_00[0x88];
  struct VObj *unk_88;
  struct VObj *unk_8c;
};

#endif
