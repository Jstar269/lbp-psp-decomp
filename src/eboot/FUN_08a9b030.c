/* LBPMATCH module=EBOOT.BIN start=0x08a9b030 end=0x08a9b0c8 symbol=FUN_08a9b030 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd1b, Claude Sonnet) */

extern unsigned int DAT_08bf7ddc;

typedef struct Msg {
  int key_a;
  int key_b;
} Msg;

typedef struct Target Target;
typedef struct TargetVtable {
  void (*slot_00)(Target *self, Msg *msg);
} TargetVtable;
struct Target {
  TargetVtable *vtable;
};

/* Circular list: head is a sentinel; each node points at a Target. */
typedef struct ListNode {
  struct ListNode *next;
  int unk_04;
  Target *target;
} ListNode;

typedef struct Filter {
  int key_a;
  int key_b;
  ListNode *head;
} Filter;

/* Deliver msg to every target on the filter's list when its keys match (key_a == DAT_08bf7ddc matches any filter;
   key_b == 0 matches any filter). */
void FUN_08a9b030(Filter *filter, Msg *msg)
{
  ListNode *node;

  if ((msg->key_a == DAT_08bf7ddc) || (msg->key_a == filter->key_a)) {
    if (msg->key_b == 0) {
      node = filter->head;
    }
    else {
      if (msg->key_b != filter->key_b) {
        return;
      }
      node = filter->head;
    }
    for (node = node->next; node != filter->head; node = node->next) {
      (*node->target->vtable->slot_00)(node->target,msg);
    }
  }
  return;
}
