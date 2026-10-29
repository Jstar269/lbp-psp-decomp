/* LBPMATCH module=EBOOT.BIN start=0x08a0694c end=0x08a06a5c symbol=FUN_08a0694c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node {
  struct Node *next;
  struct Node *prev;
  int value;
};
extern void *DAT_08be84a0;
extern struct Node *FUN_08adbb84(void *pool, int size);
extern void FUN_08adbc24(void *pool, struct Node *p, int size);
extern void FUN_08b88fc8(struct Node *n);
extern void FUN_08b88fac(struct Node *n, struct Node *pos);

struct Node *FUN_08a0694c(struct Node *list, struct Node *other)
{
  struct Node *first1, *first2;
  int v;
  if (list != other) {
    first1 = list->next;
    first2 = other->next;
    if (first1 != list && first2 != other) {
      v = first2->value;
      while (1) {
        first2 = first2->next;
        first1->value = v;
        first1 = first1->next;
        if (list == first1)
          break;
        if (other == first2)
          goto erase;
        v = first2->value;
      }
    }
    if (other != first2) {
      do {
        struct Node *n = FUN_08adbb84(DAT_08be84a0, 12);
        if (&n->value != 0)
          n->value = first2->value;
        FUN_08b88fac(n, list);
        first2 = first2->next;
      } while (first2 != other);
      return list;
    }
erase:
    while (list != first1) {
      struct Node *next = first1->next;
      FUN_08b88fc8(first1);
      FUN_08adbc24(DAT_08be84a0, first1, 12);
      first1 = next;
    }
  }
  return list;
}
// NEAR (60+ words at Os and O2): std::list::operator= with ghidra goto structure; retail register assignment (s2=list,s1=other) and loop rotation not reproduced.
// near miss from lane lbp9b (unreviewed)
