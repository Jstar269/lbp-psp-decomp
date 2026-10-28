#ifndef LBP_RD3B_SLOTSTACK_H
#define LBP_RD3B_SLOTSTACK_H

/* Shapes used by FUN_089bbd1c and FUN_089c8794 (identical code): an object whose +0x14 member holds a pointer
   table and a short used as 7 - used to pick the entry. Only the accessed fields are named. */
struct Slot {
  char pad_00[0x10];
  short unk_10;
};

struct SlotSet {
  char pad_00[0x30];
  struct Slot **slots;       /* +0x30: table of slot pointers */
  short used;                /* +0x34: entry picked is slots[7 - used] */
};

struct SlotOwner {
  char pad_00[0x14];
  struct SlotSet *set;       /* +0x14 */
};

#endif
