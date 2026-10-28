/* LBPMATCH module=EBOOT.BIN start=0x08a02df8 end=0x08a02e4c symbol=FUN_08a02df8 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Bounds check: true when base + index is below the limit (halfwords at +0x10 and +0x12) and FUN_08a16730
   accepts the object at +8 for `index`. */
struct Ranged {
  char pad[8];
  int *object;               /* +8 */
  char pad2[4];
  unsigned short base;       /* +0x10 */
  unsigned short limit;      /* +0x12 */
};

extern int FUN_08a16730();

unsigned int FUN_08a02df8(struct Ranged *self, int index)
{
  int accepted;

  if (((unsigned int)self->base + index < (unsigned int)self->limit) &&
     (accepted = FUN_08a16730(self->object, index), accepted != 0)) {
    return 1;
  }
  return 0;
}
