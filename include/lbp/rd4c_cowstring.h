#ifndef LBP_RD4C_COWSTRING_H
#define LBP_RD4C_COWSTRING_H

/* String object whose only member is a pointer to the characters. The bookkeeping sits in the words just before
   them, as in libstdc++'s copy-on-write string: length at data - 12, reference count at data - 4. */
struct Rd4cCowString {
  char *data;   /* +0 */
};

#endif
