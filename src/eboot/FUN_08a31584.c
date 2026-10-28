/* LBPMATCH module=EBOOT.BIN start=0x08a31584 end=0x08a315d4 symbol=FUN_08a31584 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08a9e0c4();
extern void FUN_08a9e0cc();

/* Block with a separately released pointer at +4. */
struct Block {
  unsigned int unk_00;
  unsigned int buffer;
};

struct BlockOwner {
  char unk_00[0xa8];
  struct Block *block;
};

void FUN_08a31584(struct BlockOwner *self)
{
  struct Block *block;

  block = self->block;
  if (block != (struct Block *)0x0) {
    if (block->buffer != 0) {
      FUN_08a9e0c4(block->buffer);
    }
    FUN_08a9e0cc(block);
  }
  self->block = 0;
  return;
}
