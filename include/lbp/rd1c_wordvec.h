#ifndef LBP_RD1C_WORDVEC_H
#define LBP_RD1C_WORDVEC_H

/* Growable array of 4-byte elements as the erase-one-element helpers see it:
   only the end pointer at +4 is used there. */
struct WordVec {
  unsigned int *unk_00;
  unsigned int *end;     /* one past the last element in use */
};

#endif
