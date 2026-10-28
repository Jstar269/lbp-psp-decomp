/* LBPMATCH module=EBOOT.BIN start=0x08974ab8 end=0x08974ad4 symbol=FUN_08974ab8 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4b, Claude Sonnet) */
struct Owner;

struct Node {
  char pad_00[8];
  struct Owner *owner;   /* +8 */
  int index;             /* +0xc: slot of this node in the owner's table */
};

struct Owner {
  char pad_00[0xc];
  struct Node **slots;   /* +0xc */
};

/* Records `node` in the owner's slot table at its own index and points it back at the owner. */
void FUN_08974ab8(struct Owner *owner, struct Node *node)
{
  struct Node **slots;

  slots = owner->slots;
  node->owner = owner;
  slots[node->index] = node;
  return;
}
