#ifndef LBP_RD3C_VOBJECT_H
#define LBP_RD3C_VOBJECT_H

/* Any polymorphic object of the game: the first word is the pointer to its table of virtual functions
   (indexed by slot, each entry is a code address). Only the slot numbers the callers use are known. */
struct VObject {
  void **vtable;
};

#endif
