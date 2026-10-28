/* LBPMATCH module=EBOOT.BIN start=0x0891a5f4 end=0x0891a6c0 symbol=FUN_0891a5f4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* self is addressed as words (a struct view changes the register allocation). Layout: word 4 is a handle; three
   circular lists have inline sentinels at words 0x44, 2 and 0 (a node's first word is the next link, the nodes of the
   first list carry an owned object at node word 2). Nodes are 0xc bytes. */
extern void *DAT_08be84a0;      /* pool the nodes are returned to */
extern void FUN_088050b8(void *owned);
extern void FUN_08a9e0cc(unsigned int handle);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Releases the handle in word 4, then destroys the owned objects and frees the nodes of the three lists. */
void FUN_0891a5f4(unsigned int *self)
{
  unsigned int *node;
  unsigned int *next;

  FUN_08a9e0cc(self[4]);
  node = (unsigned int *)self[0x44];
  while (node != self + 0x44) {
    next = (unsigned int *)*node;
    if ((void *)node[2] != 0) {
      FUN_088050b8((void *)node[2]);
    }
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
