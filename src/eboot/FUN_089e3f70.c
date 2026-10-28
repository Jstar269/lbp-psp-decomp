/* LBPMATCH module=EBOOT.BIN start=0x089e3f70 end=0x089e3ff8 symbol=FUN_089e3f70 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2a, Claude Sonnet) */
#include "lbp/rd2a_list.h"

struct ListedItem {
  char unk_000[0x35c];
  void *unk_35c;            /* compared against the address of DAT_08bf31c4 */
  char unk_360[8];
  unsigned int flags;       /* +0x368: bit 2 selects the item too */
};

extern int DAT_08bf31c0;    /* bumped on every pass */
extern char DAT_08bf31c4;
extern void FUN_089e3d90();

/* Walks the list embedded at +0x8c of `owner` and calls FUN_089e3d90(owner, item) for each item that
   is tagged with DAT_08bf31c4 or has flag bit 2 set. The next node is read before the call. */
void FUN_089e3f70(char *owner)
{
  struct ListNode *header = (struct ListNode *)(owner + 0x8c);
  struct ListNode *node = header->next;
  struct ListedItem *item;

  DAT_08bf31c0 = DAT_08bf31c0 + 1;
  while (node != header) {
    item = node->data;
    node = node->next;
    if (item->unk_35c == &DAT_08bf31c4 || (item->flags & 4) != 0) {
      FUN_089e3d90(owner, item);
    }
  }
}
