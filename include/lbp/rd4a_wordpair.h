#ifndef LBP_RD4A_WORDPAIR_H
#define LBP_RD4A_WORDPAIR_H

/* An object with two 32-bit values stored back to back at +4 and +8 (setter pairs, one per class). */
struct PairHolder {
  unsigned int unk_00;
  unsigned int first;    /* +4 */
  unsigned int second;   /* +8 */
};

#endif
