/* LBPMATCH module=EBOOT.BIN start=0x088e0738 end=0x088e07f0 symbol=FUN_088e0738 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* self is addressed as words (a struct view changes the register allocation). Layout: word 6 is a handle; three
   circular lists have inline sentinels at words 4, 2 and 0 (a node's first word is the next link); their nodes are
   0x10, 0x1c and 0x10 bytes. */
extern void *DAT_08be84a0;      /* pool the nodes are returned to */
extern void FUN_08a9e0c4(unsigned int handle);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Releases the handle in word 6, then returns every node of the three lists to the pool. */
void FUN_088e0738(unsigned int *self)
{
  unsigned int *node;
  unsigned int *next;

  if (self[6] != 0) {
    FUN_08a9e0c4(self[6]);
  }
  node = (unsigned int *)self[4];
  while (node != self + 4) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x10);
    node = next;
  }
  node = (unsigned int *)self[2];
  while (node != self + 2) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x1c);
    node = next;
  }
  node = (unsigned int *)*self;
  while (node != self) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x10);
    node = next;
  }
}
