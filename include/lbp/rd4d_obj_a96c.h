#ifndef LBP_RD4D_OBJ_A96C_H
#define LBP_RD4D_OBJ_A96C_H

/* Object returned by FUN_0895a96c(); two flag bytes at +0x50 / +0x51 are tested by callers. */
struct Rd4dObjA96c {
  char unk_00[0x50];
  unsigned char unk_50;
  unsigned char unk_51;
};

#endif
