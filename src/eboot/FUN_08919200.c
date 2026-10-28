/* LBPMATCH module=EBOOT.BIN start=0x08919200 end=0x0891927c symbol=FUN_08919200 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#include "lbp/rd3b_list.h"

extern int DAT_08be84a0;
extern void FUN_08adbc24();
extern void FUN_08b88fc8();

/* Unlink and free (12 bytes each) every node of the circular list whose key equals *key. */
void FUN_08919200(struct KeyNode *head, int *key)
{
  struct KeyNode *node;
  struct KeyNode *next;

  node = head->next;
  while (node != head) {
    next = node->next;
    if (node->key == *key) {
      FUN_08b88fc8(node);
      FUN_08adbc24(DAT_08be84a0, node, 0xc);
    }
    node = next;
  }
}
