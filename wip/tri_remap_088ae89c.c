/* LBPMATCH module=EBOOT.BIN start=0x088ae89c end=0x088ae960 symbol=FUN_088ae89c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp6c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Tri { struct Tri *next; struct Tri *prev; unsigned short v[3]; };
extern void *DAT_08be84a0;
extern void FUN_08b88fc8(struct Tri *t);
extern void FUN_08adbc24(void *pool, void *p, int size);

void FUN_088ae89c(struct Tri *head, unsigned short from, unsigned short to)
{
  struct Tri *t = head->next;
  while (t != head) {
    unsigned short *q = t->v;
    int i = 0;
    unsigned short *p = q;
    do {
      i++;
      if (*p == from) *p = to;
      p++;
    } while (i != 3);
    if (t->v[0] == q[1] || q[1] == q[2] || q[2] == t->v[0]) {
      struct Tri *next = t->next;
      FUN_08b88fc8(t);
      FUN_08adbc24(DAT_08be84a0, t, 16);
      t = next;
    } else {
      t = t->next;
    }
  }
}
// NEAR 3: three setup words in the inner-loop preheader are ordered 'move v1,a0; move a1,zero; li a2,3' vs retail 'move a1,zero; li a2,3; move v1,a0'. Tried declaration order, for/do-while, count-down.
// near miss from lane lbp6c (unreviewed)
