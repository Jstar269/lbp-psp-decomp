/* LBPMATCH module=EBOOT.BIN start=0x088e1a18 end=0x088e1a80 symbol=FUN_088e1a18 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Picks the block at +0 or, when the FUN_088dc4b4 object's word at +4 is 2, the block at +0x1c; when that
   block's circular list (sentinel at +0x14) is empty, calls FUN_088e68a0 with 1 and 0x18. */
struct ListHead {
  struct ListHead *next;     /* +0 */
  struct ListHead *prev;     /* +4 */
};

struct Block {
  char pad[0x14];
  struct ListHead list;      /* +0x14: sentinel */
};

struct TwoBlocks {
  struct Block first;        /* +0 */
  struct Block second;       /* +0x1c */
};

struct Mode {
  int unk_00;
  int mode;                  /* +4 */
};

extern unsigned int DAT_08beed14;
extern unsigned int DAT_08beee0c;
extern struct Mode *FUN_088dc4b4();
extern void FUN_088e68a0();

void FUN_088e1a18(struct TwoBlocks *self)
{
  struct Mode *mode;
  struct Block *block;

  mode = FUN_088dc4b4(DAT_08beed14);
  block = &self->second;
  if (mode->mode != 2) {
    block = &self->first;
  }
  if (block->list.next == &block->list) {
    FUN_088e68a0(DAT_08beee0c, '\x01', 0x18);
    return;
  }
  return;
}
