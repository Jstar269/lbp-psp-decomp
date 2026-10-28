/* LBPMATCH module=EBOOT.BIN start=0x089e190c end=0x089e19e0 symbol=FUN_089e190c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* self is addressed as words (a struct view changes the register allocation). Layout: three circular lists with inline
   sentinels at words 5 (byte 0x14), 3 (0xc) and 1 (4); a node's first word is the next link, and nodes of the first
   list carry an owned object pointer at node word 2. */
extern void *DAT_08be84a0;      /* pool the nodes are returned to */
extern unsigned int DAT_08bf0380;
extern void FUN_088050b8(void *owned);
extern void FUN_089e17dc(unsigned int *self);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Runs FUN_089e17dc on self, destroys the owned objects and frees the nodes of the three lists, then clears DAT_08bf0380. */
void FUN_089e190c(unsigned int *self)
{
  unsigned int *node;
  unsigned int *next;
  unsigned int *other;
  unsigned int *other_next;

  FUN_089e17dc(self);
  node = (unsigned int *)self[5];
  while (node != self + 5) {
    next = (unsigned int *)*node;
    if ((void *)node[2] != 0) {
      FUN_088050b8((void *)node[2]);
    }
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
  other = (unsigned int *)self[3];
  while (other != self + 3) {
    other_next = (unsigned int *)*other;
    FUN_08adbc24(DAT_08be84a0, other, 0xc);
    other = other_next;
  }
  other = (unsigned int *)self[1];
  while (other != self + 1) {
    other_next = (unsigned int *)*other;
    FUN_08adbc24(DAT_08be84a0, other, 0xc);
    other = other_next;
  }
  DAT_08bf0380 = 0;
}
