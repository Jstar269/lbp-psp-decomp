/* LBPMATCH module=EBOOT.BIN start=0x0898d8b4 end=0x0898d940 symbol=FUN_0898d8b4 lang=c99 cc=gcc402x-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g6); exact match verified; names and types await human review; readability pass (lane rd2b, Claude Sonnet) */
struct Element4c {
  char unk_00[0x4c];
};

/* Dynamic array of 0x4c-byte elements: a count at +4 and the element storage at +8. */
struct Array4c {
  unsigned int unk_00;
  unsigned int count;
  struct Element4c *items;
};

extern void FUN_08adbe84();   /* forward byte copy: (dest, src, byte_count) */

/* Removes items[index] by shifting the elements after it down one slot. */
void FUN_0898d8b4(struct Array4c *array, int index)
{
  unsigned int next;

  next = index + 1;
  if (next < array->count) {
    FUN_08adbe84(&array->items[index], &array->items[next], (array->count - next) * sizeof(struct Element4c));
  }
  array->count--;
}
