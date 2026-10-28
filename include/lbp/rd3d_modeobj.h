#ifndef LBP_RD3D_MODEOBJ_H
#define LBP_RD3D_MODEOBJ_H

/* An object with a target object pointer at +0xc (whose byte at +0x70 is a flag) and a mode word at +0x1a0. */
struct Rd3dModeTarget {
  char unk_00[0x70];
  unsigned char flag_70;           /* +0x70 */
};

struct Rd3dModeOwner {
  char unk_00[0xc];
  struct Rd3dModeTarget *target;   /* +0xc */
  char unk_10[0x190];
  int mode;                        /* +0x1a0 */
  int unk_1a4;
  unsigned int value_1a8;
  unsigned int value_1ac;
};

enum Rd3dMode {
  RD3D_MODE_1 = 1,
  RD3D_MODE_2 = 2,
  RD3D_MODE_3 = 3,
  RD3D_MODE_9 = 9
};

#endif
