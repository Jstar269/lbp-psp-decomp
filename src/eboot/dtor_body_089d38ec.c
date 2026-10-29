/* LBPMATCH module=EBOOT.BIN start=0x089d38ec end=0x089d39a4 symbol=FUN_089d38ec lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc16f0[];
extern char DAT_08bc17a0[];
extern void *DAT_08be84a0;
extern void FUN_08970b6c(void *);
extern void FUN_08adbc24(void *, void *, int);
extern void FUN_089e0a0c(void *);
struct Link { struct Link *next; int a, b; void *obj; };
struct Self { const void *vt; char pad[44]; void *r0; void *r1; struct Link *head; };
void FUN_089d38ec(struct Self *self)
{
  struct Link *end = (struct Link *)&self->head;
  struct Link *n = self->head;
  self->vt = DAT_08bc16f0;
  while (n != end) {
    struct Link *next = n->next;
    if (n->obj != 0) FUN_08970b6c(n->obj);
    FUN_08adbc24(DAT_08be84a0, n, 16);
    n = next;
  }
  self->vt = DAT_08bc17a0;
  if (self->r1 != 0) FUN_08970b6c(self->r1);
  if (self->r0 != 0) FUN_08970b6c(self->r0);
  FUN_089e0a0c(self);
}
