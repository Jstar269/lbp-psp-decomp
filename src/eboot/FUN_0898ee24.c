/* LBPMATCH module=EBOOT.BIN start=0x0898ee24 end=0x0898eeac symbol=FUN_0898ee24 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
/* A blob that starts with its own byte size; words 13..16 hold pointers into the blob. */
struct Blob {
  unsigned int size;           /* +0 (replaced by 8 in the copy) */
  unsigned int unk_04[12];
  unsigned int inner[4];       /* +0x34: absolute pointers into the blob */
};

extern struct Blob *FUN_08a9e4a4();   /* allocate(size, 0, 0) */
extern void *FUN_08b9e7a8();          /* memcpy(dst, src, count) */

/* Copies a blob and turns the four inner pointers of the copy into offsets from the original's
   address (pointer minus original base). */
struct Blob *FUN_0898ee24(struct Blob *blob)
{
  struct Blob *copy;

  copy = FUN_08a9e4a4(blob->size, 0, 0);
  FUN_08b9e7a8(copy, blob, blob->size);
  copy->size = 8;
  copy->inner[0] = copy->inner[0] - (int)blob;
  copy->inner[1] = copy->inner[1] - (int)blob;
  copy->inner[2] = copy->inner[2] - (int)blob;
  copy->inner[3] = copy->inner[3] - (int)blob;
  return copy;
}
