/* LBPMATCH module=EBOOT.BIN start=0x08886874 end=0x08886988 symbol=FUN_08886874 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Hdr { int color; struct Hdr *parent; struct Hdr *left; struct Hdr *right; } Hdr;
typedef struct Impl { int cmp; Hdr hdr; int count; } Impl;
typedef struct Ent { int a, b; } Ent;
typedef struct Node { int x, y, cap; char flag; char pad[3]; Impl impl; Ent *arr; } Node;
typedef struct Tab { void *vt; int a, b; Node *node; Impl impl; int cap; } Tab;
extern char DAT_08bb0c90[];
extern void *FUN_08b9eb88(void *, int, int);
extern void *FUN_08a9e838(int);
extern void *FUN_08a9e824(int);
void FUN_08886874(Tab *t, int cap)
{
  Impl *im = &t->impl;
  t->vt = DAT_08bb0c90;
  t->a = 0;
  t->b = 0;
  FUN_08b9eb88(&im->hdr, 0, 16);
  im->count = 0;
  im->hdr.right = &im->hdr;
  im->hdr.color = 0;
  im->hdr.parent = 0;
  im->hdr.left = &im->hdr;
  t->cap = cap;
  if (cap != 0) {
    Node *n = FUN_08a9e838(44);
    int c = t->cap;
    Impl *ni = &n->impl;
    n->cap = c;
    FUN_08b9eb88(&ni->hdr, 0, 16);
    ni->hdr.right = &ni->hdr;
    ni->count = 0;
    ni->hdr.color = 0;
    ni->hdr.parent = 0;
    ni->hdr.left = &ni->hdr;
    int end = c + 1;
    Ent *e = FUN_08a9e824(c << 3);
    int i = 0;
    Ent *p = e;
    while (++i != end) {
      p->a = 0;
      p->b = 0;
      p++;
    }
    t->node = n;
    n->arr = e;
    n->y = 0;
    n->x = 0;
    n->flag = 0;
  } else {
    t->node = 0;
  }
}
// NEAR ~25 words (69/69): this is a std::map-like constructor (vtable, empty header, then a heap node with its own empty header and an 8-byte-entry array).
// remaining: retail order of the five header stores in both blocks is [36,32,20,24,28] (ours 36,20,28,32,24), register assignment (retail s4=this s2=cap/cap+1 s3=node s1=hdr s0=impl) and loop shape (retail a0 starts 0 and enters at the increment, comparing against cap+1; ours starts li a0,1).
// tried: != / < tests, index vs pointer, end=c+1 local (best), inverted if (cap != 0) so the else store is out of line (matches layout).
// near miss from lane lbp8c (unreviewed)
