/* LBPMATCH module=EBOOT.BIN start=0x089d377c end=0x089d3834 symbol=FUN_089d377c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc16f0[];
struct Ref { char pad[6]; unsigned short count; };
struct Pair { int key; struct Ref *ref; };
struct Link { struct Link *next; struct Link *prev; };
struct Self { const void *vt; char pad[52]; struct Link list; };
extern void FUN_089d831c(struct Self *, int, int);
extern void FUN_089d3558(struct Link *, struct Pair *);
extern void FUN_08970b6c(struct Ref *);
void FUN_089d377c(struct Self *self, int a1, int key, struct Ref **rp, int t0)
{
  struct Ref *r;
  struct Pair p;
  FUN_089d831c(self, a1, t0);
  r = *rp;
  self->vt = DAT_08bc16f0;
  struct Link *l = &self->list;
  self->list.next = l;
  l->prev = l;
  if (r != 0) r->count++;
  p.key = key;
  p.ref = r;
  if (r != 0) r->count++;
  FUN_089d3558(&self->list, &p);
  if (p.ref != 0) FUN_08970b6c(p.ref);
  if (r != 0) FUN_08970b6c(r);
}
