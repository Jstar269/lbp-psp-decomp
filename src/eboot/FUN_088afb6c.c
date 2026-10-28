/* LBPMATCH module=EBOOT.BIN start=0x088afb6c end=0x088afc3c symbol=FUN_088afb6c lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* Pool-allocated list nodes; self is addressed as words because a struct view changes the register allocation.
   Layout: word 2 and word 9 hold handles; three circular lists have their sentinels (next, prev) inline at words 3,
   5 and 7 (byte offsets 0xc, 0x14, 0x1c). A node's first word points to the next node. */
extern void *DAT_08be84a0;      /* pool the list nodes are returned to */
extern void FUN_08a9e0c4(unsigned int handle);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Releases the two handles of self, then returns every node of its three lists to the pool (sizes 0x10, 0xc, 0xc). */
void FUN_088afb6c(unsigned int *self)
{
  unsigned int handle;
  unsigned int *next;
  unsigned int *node;

  if (self[2] != 0) {
    FUN_08a9e0c4(self[2]);
  }
  handle = self[9];
  if (handle != 0) {
    FUN_08a9e0c4(handle);
  }
  node = (unsigned int *)self[7];
  while (node != self + 7) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x10);
    node = next;
  }
  node = (unsigned int *)self[5];
  while (node != self + 5) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
  node = (unsigned int *)self[3];
  while (node != self + 3) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0xc);
    node = next;
  }
}
