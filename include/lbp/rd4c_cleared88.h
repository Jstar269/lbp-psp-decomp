#ifndef LBP_RD4C_CLEARED88_H
#define LBP_RD4C_CLEARED88_H

/* Object whose word at +0x88 is cleared after the delegated call in FUN_08a0b560 / FUN_08a0b588. */
struct Rd4cCleared88 {
  char unk_00[0x88];
  unsigned int unk_88;   /* +0x88 */
};

#endif
