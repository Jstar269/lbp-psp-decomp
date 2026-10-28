#ifndef LBP_RD4C_SERIAL_OWNER_H
#define LBP_RD4C_SERIAL_OWNER_H

/* Object that two serialisation routines (FUN_08a6a22c and FUN_08a86a38) walk the same way: a tagged header
   via FUN_08a34774, then the part at +0xbc (FUN_08a56ec8) and the part at +0x250 (FUN_08a56b48). */
struct Rd4cSerialOwner {
  char unk_00[0xbc];
  char part_bc[0x194];    /* +0xbc: handed to FUN_08a56ec8 */
  char part_250[1];       /* +0x250: handed to FUN_08a56b48; size not known */
};

#endif
