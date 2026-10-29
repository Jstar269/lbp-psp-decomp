/* LBPMATCH module=EBOOT.BIN start=0x08aa8278 end=0x08aa82d4 symbol=FUN_08aa8278 lang=c99 */
/* Clone of src/eboot/ctor_chain_08aa821c.c (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. Matching idiom: the unused second parameter is a 4-byte char[4] struct passed by value (its stack home is the retail sw a1,0(sp)); the four fields are read into locals before the null test (retail loads them ahead of the branch). */
extern char DAT_08bcb0dc[];
extern char DAT_08bcb090[];
struct W { char c[4]; };
struct Sub { void *vt; int a, b, c, d, e; };
struct Obj { void *vt; int f1, f2; struct Sub sub; };
extern void FUN_08aa81a4(struct Obj *, int, int, int, int);
void FUN_08aa8278(struct Obj *self, struct W x)
{
  struct Sub *s = &self->sub;
  int a = s->a, b = s->b, c = s->c, e = s->e;
  if (self != 0) {
    FUN_08aa81a4(self, a, b, c, e);
    self->vt = DAT_08bcb090;
    s->vt = DAT_08bcb0dc;
  }
}
