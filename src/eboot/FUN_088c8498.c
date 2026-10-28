/* LBPMATCH module=EBOOT.BIN start=0x088c8498 end=0x088c84f4 symbol=FUN_088c8498 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review.; readability pass (lane rd3d, Claude Sonnet) */
/* Queues `item` on one of two lists of `owner` (+0x84 when the item's target has a zero word at +0x10, else
   +0x7c) and records which one in the state word at +0x60 (3 or 4). */
struct Target {
  char pad[0x10];
  int unk_10;
};

struct Item {
  struct Target *target;     /* +0 */
};

struct Owner {
  char pad[0x60];
  int state;                 /* +0x60 */
  char pad2[0x18];
  char list_7c[8];           /* +0x7c */
  char list_84[8];           /* +0x84 */
};

extern void FUN_088c8398();

void FUN_088c8498(struct Item *item, struct Owner *owner)
{
  int state;

  if (item->target->unk_10 == 0) {
    FUN_088c8398(owner->list_84, item);
    state = 3;
  }
  else {
    FUN_088c8398(owner->list_7c, item);
    state = 4;
  }
  owner->state = state;
  return;
}
