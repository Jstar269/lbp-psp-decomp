#ifndef LBP_RD3B_STATEOBJ_H
#define LBP_RD3B_STATEOBJ_H

/* Object with a small state number at +0x44 and a helper pointer at +0x40, as FUN_088f3748 and FUN_088ea3b4
   use it (they may be different classes sharing this layout). Only the accessed fields are named. */
struct StateObj {
  char pad_00[0x40];
  void *unk_40;
  int state;
  int unk_48;
  char pad_4c[0x54];
  int unk_a0;
};

#endif
