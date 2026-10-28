/* LBPMATCH module=EBOOT.BIN start=0x088aeafc end=0x088aeb2c symbol=FUN_088aeafc lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Moves the cursor `*cursor` forward by `steps` links of a circular list, hopping over the sentinel node. */
struct LinkNode {
  struct LinkNode *next;     /* +0 */
};

void FUN_088aeafc(struct LinkNode **cursor, int steps, struct LinkNode *sentinel)
{
  struct LinkNode *next;

  while (0 < steps) {
    steps = steps + -1;
    next = (*cursor)->next;
    *cursor = next;
    if (next == sentinel) {
      *cursor = sentinel->next;
    }
  }
  return;
}
