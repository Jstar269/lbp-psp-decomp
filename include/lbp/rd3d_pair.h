#ifndef LBP_RD3D_PAIR_H
#define LBP_RD3D_PAIR_H

/* An object holding two element pointers (+4, +8) whose float at +0x18 is summed, plus a cached reciprocal
   of that sum at +0xf0. */
struct Rd3dPairElem {
  char unk_00[0x18];
  float value_18;
};

struct Rd3dPair {
  int unk_00;
  struct Rd3dPairElem *first;      /* +4 */
  struct Rd3dPairElem *second;     /* +8 */
  char unk_0c[0xe4];
  float reciprocal_sum;            /* +0xf0: 1 / (first->value_18 + second->value_18) */
};

#endif
