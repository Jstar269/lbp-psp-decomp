/* LBPMATCH module=EBOOT.BIN start=0x0888bf64 end=0x0888bfe0 symbol=FUN_0888bf64 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11a, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: packed 20-byte struct assignment for the unaligned load. */
typedef struct { int w[5]; } __attribute__((packed)) W5;
struct Node { struct Node *prev; struct Node *next; };
struct Obj {
  int a;
  int count;
  struct Node head;
  int b;
  int c;
  W5 data;
};
extern const W5 *FUN_08882764(void);

void FUN_0888bf64(struct Obj *self)
{
  struct Node *h = &self->head;
  self->count = 0;
  h->prev = h;
  h->next = h;
  self->data = *FUN_08882764();
  self->a = 0;
  self->b = 0;
  self->c = 0;
}
