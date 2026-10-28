/* LBPMATCH module=EBOOT.BIN start=0x088e7e94 end=0x088e7f64 symbol=FUN_088e7e94 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Pool-allocated list nodes; self is addressed as words because a struct view changes the register allocation.
   Layout: four circular lists whose sentinels (next, prev) sit inline in self at words 0, 2, 4 and 6. Each sentinel's
   first word points to the first node; a node's first word points to the next node. */
extern void *DAT_08be84a0;      /* pool the list nodes are returned to */
extern void FUN_088f87ec(unsigned int *self);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Runs FUN_088f87ec on self, then returns every 0xc-byte node of its four lists (last to first) to the pool. */
void FUN_088e7e94(unsigned int *self)
{
  unsigned int *next;
  unsigned int *node;

  FUN_088f87ec(self);
  node = (unsigned int *)self[6];
  while (node != self + 6) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
  node = (unsigned int *)self[4];
  while (node != self + 4) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
  node = (unsigned int *)self[2];
  while (node != self + 2) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
  node = (unsigned int *)*self;
  while (node != self) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
}
