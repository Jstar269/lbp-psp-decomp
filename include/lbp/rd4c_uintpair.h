#ifndef LBP_RD4C_UINTPAIR_H
#define LBP_RD4C_UINTPAIR_H

/* Two unsigned words compared lexicographically (first word, then second) by the "less than"
   helpers FUN_0899a3c4 and FUN_089e5b6c. */
struct Rd4cUIntPair {
  unsigned int first;    /* +0: compared first */
  unsigned int second;   /* +4: tie-break */
};

#endif
