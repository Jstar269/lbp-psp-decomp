/* LBPMATCH module=EBOOT.BIN start=0x08a1acb0 end=0x08a1ad68 symbol=FUN_08a1acb0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
extern char DAT_08bc36e8[];
extern char DAT_08bc3734[];
extern int DAT_08bcb448;
struct Px { char c[4]; };
struct Sub { void *vt; int a, b, c, d; };
struct Buf { struct Px *data; int a, b, c; };
struct Obj { void *vt; int w, h; struct Sub sub; struct Buf buf; };
extern struct Px *FUN_08a9e824(int);
void FUN_08a1acb0(struct Obj *self, int w, int h)
{
  int n = w * h;
  int i;
  struct Px *p;
  struct Sub *s = &self->sub;
  struct Buf *b = &self->buf;
  self->w = w;
  self->h = h;
  s->vt = DAT_08bc3734;
  s->a = w;
  s->b = h;
  s->c = w;
  s->d = DAT_08bcb448;
  self->vt = DAT_08bc36e8;
  b->data = 0;
  b->a = w;
  b->b = w;
  b->c = h;
  p = FUN_08a9e824(n * 4);
  if (n != 0) {
    struct Px *q = p;
    i = 0;
    do {
      q->c[0] = 0;
      q->c[1] = 0;
      q->c[2] = 0;
      q->c[3] = 0;
      i++;
      q++;
    } while (n != i);
  }
  b->data = p;
}
// NEAR ~32 words: retail uses separate base registers for the inline sub-object initialisers (a3=this, t0=this+12, s1=this+32, each a distinct inline-ctor 'this'); ours merges them. Loop shape (if (n != 0) do { 4x sb } while) matches.
// near miss from lane lbp11d (unreviewed)
