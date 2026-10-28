/* LBPMATCH module=EBOOT.BIN start=0x08a2e71c end=0x08a2e738 symbol=FUN_08a2e71c lang=c99 cc=gcc410-Os */
/* Mechanical translation of Ghidra pseudocode (lbpgen.py tag g2); exact match verified; names and types await human review.; readability pass (lane rd4c, Claude Sonnet) */

struct IndexFreeList {
  char unk_00[4];
  int *links;            /* +4: links[i] holds the index that follows i */
  int head;              /* +8: first free index */
};

/* Pushes `index` onto the free list: links[index] = head; head = index. */
void FUN_08a2e71c(struct IndexFreeList *list, int index)
{
  list->links[index] = list->head;
  list->head = index;
}
