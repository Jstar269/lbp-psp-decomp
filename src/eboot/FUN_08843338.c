/* LBPMATCH module=EBOOT.BIN start=0x08843338 end=0x08843354 symbol=FUN_08843338 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g1); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
/* Intrusive doubly linked node embedded at +0x1c of an object. */
struct LinkedObject {
  char unk_00[0x1c];
  struct LinkedObject *prev;   /* +0x1c */
  struct LinkedObject *next;   /* +0x20 */
};

/* Inserts `node` into the ring just before `pos`. */
void FUN_08843338(struct LinkedObject *pos, struct LinkedObject *node)
{
  struct LinkedObject *before = pos->prev;

  node->next = pos;
  node->prev = before;
  before = pos->prev;
  pos->prev = node;
  before->next = node;
}
