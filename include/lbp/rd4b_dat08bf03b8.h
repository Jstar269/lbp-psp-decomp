#ifndef LBP_RD4B_DAT08BF03B8_H
#define LBP_RD4B_DAT08BF03B8_H

/* The object the global DAT_08bf03b8 points to, as far as these sources see it: one flag byte at +0x8c
   (set by FUN_08989e18). FUN_0896491c only passes the pointer on. */
struct Dat08bf03b8 {
  char pad_00[0x8c];
  unsigned char unk_8c;   /* +0x8c */
};

#endif
