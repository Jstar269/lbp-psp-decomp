#ifndef LBP_RD4D_COWSTR_H
#define LBP_RD4D_COWSTR_H

/* Reference-counted string handle: one pointer to the character data, with a 12-byte header just below it
   (length at -0xc, capacity at -8, reference count at -4; a negative count marks unshared data). */
struct Rd4dCowStrRep {
  int length;
  int capacity;
  int refcount;
};

struct Rd4dCowStr {
  char *data;
};

/* Header of the character data `data` points at. */
#define RD4D_COWSTR_REP(data) ((struct Rd4dCowStrRep *)(data) - 1)

#endif
