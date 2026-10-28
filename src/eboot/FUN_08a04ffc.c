/* LBPMATCH module=EBOOT.BIN start=0x08a04ffc end=0x08a05040 symbol=FUN_08a04ffc lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct Entry {
  char pad_00[0xd8];
  int unk_d8;
};

struct EntryNode {
  struct EntryNode *next;
  void *unk_04;
  struct Entry *entry;
};

struct Owner {
  char pad_00[0x54];
  struct EntryNode list;   /* circular list header embedded at +0x54 */
};

/* 1 when any entry in the list has unk_d8 == 10. */
int FUN_08a04ffc(struct Owner *self)
{
  struct EntryNode *node;
  struct Entry *entry;

  node = self->list.next;
  if (node == &self->list) {
    return 0;
  }
  entry = node->entry;
  while (1) {
    if (entry->unk_d8 == 10) {
      return 1;
    }
    node = node->next;
    if (&self->list == node) {
      break;
    }
    entry = node->entry;
  }
  return 0;
}
