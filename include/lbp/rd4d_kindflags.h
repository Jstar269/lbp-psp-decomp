#ifndef LBP_RD4D_KINDFLAGS_H
#define LBP_RD4D_KINDFLAGS_H

/* Kind word at +0x44 of one object, flag word at +0xac of another. */
#define RD4D_KIND_26 0x26

struct Rd4dKindObj {
  char unk_00[0x44];
  int kind_44;
};

struct Rd4dFlagsObj {
  char unk_00[0xac];
  unsigned int flags_ac;
};

#endif
