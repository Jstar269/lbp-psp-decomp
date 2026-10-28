/* LBPMATCH module=EBOOT.BIN start=0x08b8ce48 end=0x08b8ceac symbol=FUN_08b8ce48 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd4a, Claude Sonnet) */

extern void FUN_08b989d4();
extern void FUN_08b9de04();

/* List node: next link at +0x10, payload starting at +0x30. */
struct Node {
  char unk_00[0x10];
  struct Node *next;
  char unk_14[0x1c];
  char payload[1];
};

struct List {
  struct Node *first;
};

void FUN_08b8ce48(struct List *list)
{
  struct Node *node;
  struct Node *next;

  if (list != (struct List *)0x0) {
    node = list->first;
    while (node != (struct Node *)0x0) {
      next = node->next;
      FUN_08b989d4(node->payload);
      node = next;
    }
    FUN_08b9de04(list);
    return;
  }
  return;
}
