/* LBPMATCH module=EBOOT.BIN start=0x0896f7a0 end=0x0896f7d0 symbol=FUN_0896f7a0 lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd3c, Claude Sonnet) */
struct Counted {
  char pad[6];
  short refs;               /* +6: incremented each time a handle to the object is copied out */
};

struct Table {
  char pad[0x14];
  struct Counted **items;   /* +0x14 */
};

/* Copies item index of the table into *out and adds a reference to it (when not null). */
struct Counted **FUN_0896f7a0(struct Counted **out, struct Table *table, int index)
{
  struct Counted *item;

  item = table->items[index];
  *out = item;
  if (item != 0) {
    item->refs = item->refs + 1;
  }
  return out;
}
