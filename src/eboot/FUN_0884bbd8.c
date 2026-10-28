/* LBPMATCH module=EBOOT.BIN start=0x0884bbd8 end=0x0884bc28 symbol=FUN_0884bbd8 lang=c99 cc=gcc171-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g3); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

#define ITEM_LIMIT 0x40

struct ItemSet {
  char pad_00[0xc8];
  int items[ITEM_LIMIT];     /* +0xc8: 4-byte items, initialised by FUN_0884bb28 */
  unsigned int count;        /* +0x1c8 */
  unsigned int unk_1cc;
};

extern int *FUN_0884bb28();

/* Append a copy of *src while fewer than ITEM_LIMIT items are stored; returns 1 if it was added. */
unsigned char FUN_0884bbd8(struct ItemSet *set, int *src)
{
  unsigned int count;

  count = set->count;
  if (count < ITEM_LIMIT) {
    set->unk_1cc = ITEM_LIMIT;
    set->count = count + 1;
    /* address of items[count], written as integer arithmetic because the operand order shows in the code */
    FUN_0884bb28((int *)(count * 4 + (unsigned int)set + 0xc8), src);
  }
  return count < ITEM_LIMIT;
}
