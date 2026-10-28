#ifndef LBP_RD3D_SLOTTABLE_H
#define LBP_RD3D_SLOTTABLE_H

/* A table of 0x20-byte slots at +0xa8 of its owner; each slot starts with a pointer to a record (0 when empty). */
struct Rd3dSlotRecord {
  int unk_00;
  unsigned int value;        /* +4 */
};

struct Rd3dSlotEntry {
  struct Rd3dSlotRecord *record;   /* +0 */
  char unk_04[0x1c];
};

struct Rd3dSlotTable {
  char unk_00[0xa8];
  struct Rd3dSlotEntry slots[1];   /* +0xa8, indexed by slot number */
};

#endif
