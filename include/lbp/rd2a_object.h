#ifndef LBP_RD2A_OBJECT_H
#define LBP_RD2A_OBJECT_H

/* An object whose first word is a pointer to its table of virtual functions. */
struct VObject {
  void (**vtable)();   /* slot signatures differ per class; the first argument is the object */
};

#endif
