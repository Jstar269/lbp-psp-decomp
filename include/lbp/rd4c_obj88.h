#ifndef LBP_RD4C_OBJ88_H
#define LBP_RD4C_OBJ88_H

/* Object whose +0x88 word and +0x90 float are forwarded to FUN_0897f268 (FUN_0897f480 / FUN_0897f498). */
struct Rd4cObj88 {
  char unk_00[0x88];
  int *unk_88;       /* +0x88: passed through */
  char unk_8c[4];
  float unk_90;      /* +0x90: its address is passed through */
};

#endif
