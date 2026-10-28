/* LBPMATCH module=EBOOT.BIN start=0x08a61fa4 end=0x08a62004 symbol=FUN_08a61fa4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Finds the node of the list at +0x234 whose payload (+8) equals `key` and returns it to the node pool (0xc bytes).
   Node links: +0 reaches the last node from the sentinel, +4 is the forward link. */
struct Node {
  struct Node *last;         /* +0 */
  struct Node *next;         /* +4 */
  int payload;               /* +8 */
};

struct Owner {
  char pad[0x234];
  struct Node list;          /* +0x234: sentinel */
};

extern unsigned int DAT_08be84a0;   /* node pool */
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

void FUN_08a61fa4(struct Owner *self, int key)
{
  struct Node *node;

  node = &self->list;
  do {
    if (node == self->list.last) {
      return;
    }
    node = node->next;
  } while (node->payload != key);
  FUN_08b88fc8(node);
  FUN_08adbc24(DAT_08be84a0, (unsigned int)node, 0xc);
  return;
}
