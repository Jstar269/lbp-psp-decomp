/* LBPMATCH module=EBOOT.BIN start=0x08812668 end=0x088126d0 symbol=FUN_08812668 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_list.h"

extern int FUN_0880b634();
extern void FUN_08812530();

/* For every node in the list embedded at +0x9c of `owner`: look its payload up in `table`
   (FUN_0880b634 fills in a result) and, when found, pass the result to FUN_08812530. */
void FUN_08812668(int table, char *owner)
{
  struct ListNode *header = (struct ListNode *)(owner + 0x9c);
  struct ListNode *node;
  int *found[4];

  for (node = header->next; node != header; node = node->next) {
    found[0] = 0;
    if (FUN_0880b634(table, node->data, found) != 0) {
      FUN_08812530(table, found[0]);
    }
  }
}
