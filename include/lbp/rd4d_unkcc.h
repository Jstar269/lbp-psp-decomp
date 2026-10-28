#ifndef LBP_RD4D_UNKCC_H
#define LBP_RD4D_UNKCC_H

/* Object whose word at +0xcc is cleared after a helper has run on it. */
struct Rd4dObjCC {
  char unk_00[0xcc];
  int unk_cc;
};

#endif
