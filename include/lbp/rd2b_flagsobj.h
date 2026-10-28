#ifndef LBP_RD2B_FLAGSOBJ_H
#define LBP_RD2B_FLAGSOBJ_H

/* The global object returned by FUN_0895a96c() (a function-local static accessor). Callers
   here only test two byte flags at +0x50 and +0x51; their meaning is not established. */
struct FlagsObject {
  char unk_00[0x50];
  unsigned char unk_50;
  unsigned char unk_51;
};

#endif
