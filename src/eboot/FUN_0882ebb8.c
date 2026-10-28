/* LBPMATCH module=EBOOT.BIN start=0x0882ebb8 end=0x0882ec70 symbol=FUN_0882ebb8 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1a, Claude Sonnet) */

/* self is addressed as words (a struct view changes the register allocation). Layout: word 2 is the head of a singly
   linked chain of 0x1c-byte nodes (next at node word 2, a value at node word 3); two circular lists of 0x30-byte
   nodes have inline sentinels at words 10 (byte 0x28) and 12 (byte 0x30). A node's first word is the next link. */
extern void *DAT_08be84a0;      /* pool the nodes are returned to */
extern void FUN_0882e830(unsigned int *self, unsigned int value);
extern void FUN_0882eb08(unsigned int *self);
extern void FUN_08adbc24(void *pool, void *node, unsigned int size);

/* Runs FUN_0882eb08 on self, then frees both circular lists and walks the chain, calling FUN_0882e830 per node. */
void FUN_0882ebb8(unsigned int *self)
{
  unsigned int *next;
  unsigned int *node;
  unsigned int *chain_next;
  unsigned int *chain_node;

  FUN_0882eb08(self);
  node = (unsigned int *)self[12];
  while (node != self + 12) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x30);
    node = next;
  }
  node = (unsigned int *)self[10];
  while (node != self + 10) {
    next = (unsigned int *)*node;
    FUN_08adbc24(DAT_08be84a0, node, 0x30);
    node = next;
  }
  chain_node = (unsigned int *)self[2];
  while (chain_node != 0) {
    FUN_0882e830(self, chain_node[3]);
    chain_next = (unsigned int *)chain_node[2];
    FUN_08adbc24(DAT_08be84a0, chain_node, 0x1c);
    chain_node = chain_next;
  }
}
