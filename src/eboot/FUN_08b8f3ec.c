/* LBPMATCH module=EBOOT.BIN start=0x08b8f3ec end=0x08b8f440 symbol=FUN_08b8f3ec lang=c99 cc=gcc402x-O2 rodata=0x08bd9c74 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
/* Tree-like node: kind code at +0, wrapper nodes (kinds 1 and 2) point at their operand at +8. */
struct Node {
  unsigned int kind;
  unsigned int unk_04;
  struct Node *operand;
};

/* Looks through kind 1/2 wrappers; returns 1 when the innermost node is of kind 6, 7 or 0x29, else 0. */
int FUN_08b8f3ec(struct Node *node)
{
  while (node != 0) {
    switch (node->kind) {
    case 1:
    case 2:
      node = node->operand;
      break;
    case 6:
    case 7:
    case 0x29:
      return 1;
    default:
      return 0;
    }
  }
  return 0;
}
