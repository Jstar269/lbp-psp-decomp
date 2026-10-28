#ifndef LBP_RD4C_OWNED_A8_H
#define LBP_RD4C_OWNED_A8_H

/* Any polymorphic object: the first word points at its table of virtual functions (slot signatures differ
   per class; the first argument is the object). Slot 1 (vtable + 4) is how these callers release it. */
struct Rd4cVirtualObject {
  void (**vtable)();
};

/* Object that owns a polymorphic object through the pointer at +0xa8
   (FUN_08957e48 and FUN_08958348 release it through slot 1 and clear the pointer). */
struct Rd4cOwnedA8Holder {
  char unk_00[0xa8];
  struct Rd4cVirtualObject *owned;   /* +0xa8 */
};

#endif
