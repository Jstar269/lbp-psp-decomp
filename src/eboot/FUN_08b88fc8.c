/* LBPMATCH module=EBOOT.BIN start=0x08b88fc8 end=0x08b88fdc symbol=FUN_08b88fc8 lang=c99 cc=gcc402x-O1 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g13); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

#include "lbp/rd3b_list.h"

/* Unlinks `node` from its circular doubly linked list: next->prev = prev; prev->next = next. */
void FUN_08b88fc8(struct ListLink *node)
{
  struct ListLink *prev;
  struct ListLink *next;

  prev = node->prev;
  next = node->next;
  next->prev = prev;
  prev->next = next;
}
