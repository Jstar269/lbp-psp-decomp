/* LBPMATCH module=EBOOT.BIN start=0x0884a9cc end=0x0884aabc symbol=FUN_0884a9cc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Ref { void **vtable; int count; } Ref;
typedef struct Queue {
  int pad0;
  unsigned cap;
  Ref **items;
  unsigned tail;
  unsigned head;
  unsigned char empty;
  unsigned char full;
} Queue;
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *);
extern void FUN_08ad2810(void *);
extern void FUN_0884a91c(Ref **, Ref **);

int FUN_0884a9cc(Queue *q, Ref **out)
{
  Ref *tmp;
  Ref *r;
  int c;
  unsigned next;

  if (q->empty != 0) return 0;
  FUN_0884a91c(out, &q->items[q->head]);
  tmp = 0;
  FUN_0884a91c(&q->items[q->head], &tmp);
  r = tmp;
  if (r != 0) {
    FUN_08ad3088(DAT_08bef8f4);
    c = --r->count;
    FUN_08ad2810(DAT_08bef8f4);
    if (c == 0) ((void (*)(Ref *))r->vtable[1])(r);
  }
  next = (q->head + 1) & (q->cap - 1);
  q->full = 0;
  q->head = next;
  q->empty = (next == q->tail);
  return 1;
}
