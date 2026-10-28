#ifndef LBP_RD4D_ZEROINIT_H
#define LBP_RD4D_ZEROINIT_H

/* Record reset to zero: three words, then two bytes at +0xc and +0xd. */
struct Rd4dZeroInitRec {
  int unk_00;
  int unk_04;
  int unk_08;
  unsigned char unk_0c;
  unsigned char unk_0d;
};

#endif
