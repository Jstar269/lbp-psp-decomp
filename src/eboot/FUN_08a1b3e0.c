/* LBPMATCH module=EBOOT.BIN start=0x08a1b3e0 end=0x08a1b424 symbol=FUN_08a1b3e0 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct Block {
  int *data;             /* +0: result of the allocation call */
  unsigned int unk_04;
  unsigned int size;     /* +8 */
  unsigned int unk_0c;
};

extern int *FUN_08a9ecb8();

/* Allocates `size` bytes (the 0x40 and the two zeros are passed through unchanged) and resets the other words. */
void FUN_08a1b3e0(struct Block *block, unsigned int size)
{
  int *data;

  block->size = size;
  block->unk_0c = 0;
  data = FUN_08a9ecb8(size, 0x40, 0, 0);
  block->data = data;
  block->unk_04 = 0;
}
