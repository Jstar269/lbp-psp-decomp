/* LBPMATCH module=EBOOT.BIN start=0x08b8f6a4 end=0x08b8f6e8 symbol=FUN_08b8f6a4 lang=c99 cc=gcc402x-O2 */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g8); exact match verified; names and types await human review.; readability pass (lane rd3b, Claude Sonnet) */

struct PtrStack {
  char pad_00[0x1c];
  void **items;              /* +0x1c */
  int count;                 /* +0x20 */
  int capacity;              /* +0x24 */
};

/* Append item (non-null) when there is room; returns 1 on success, 0 otherwise. */
int FUN_08b8f6a4(struct PtrStack *stack, void *item)
{
  int count;

  if (item != 0) {
    count = stack->count;
    if (count < stack->capacity) {
      stack->count = count + 1;
      stack->items[count] = item;
      return 1;
    }
  }
  return 0;
}
