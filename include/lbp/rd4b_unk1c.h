#ifndef LBP_RD4B_UNK1C_H
#define LBP_RD4B_UNK1C_H

/* Object whose word at +0x1c gates a call to FUN_08974660 (FUN_0899335c and FUN_08994b94 skip it when the
   word is non-zero). */
struct Unk1cObject {
  char pad_00[0x1c];
  int unk_1c;   /* +0x1c */
};

#endif
