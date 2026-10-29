/* LBPMATCH module=EBOOT.BIN start=0x0883d698 end=0x0883d7f0 symbol=FUN_0883d698 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Ref { char pad0[8]; int count; char pad1[8]; char lock[1]; };
struct T8 { char b[8]; };
struct Elem { int a, b, c, d; Ref *ref; T8 tail; };
struct Vec { int p0; Elem *end; };

extern "C" void FUN_08ad3088(char *lock);
extern "C" void FUN_08ad2810(char *lock);
extern "C" void FUN_088050b8(Ref *r);
extern "C" void FUN_08840ae8(Elem *e);

extern "C" Elem *FUN_0883d698(Vec *v, Elem *first, Elem *last)
{
  Elem *dst = first;
  Elem *src = last;
  int n = v->end - last;
  while (n > 0) {
    Ref *r = src->ref;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    n--;
    if (r) {
      FUN_08ad3088(r->lock);
      r->count++;
      FUN_08ad2810(r->lock);
    }
    Ref *old = dst->ref;
    dst->ref = r;
    if (old)
      FUN_088050b8(old);
    dst->tail = src->tail;
    src++;
    dst++;
  }
  Elem *const &e = v->end;
  Elem *stop = e;
  for (; dst != stop; dst++)
    FUN_08840ae8(dst);
  v->end = (Elem *)((char *)v->end - (((char *)last - (char *)first) & ~3));
  return first;
}
// NEAR: everything matches except retail keeps `s8 = &v->end` (addiu s8,a0,4 in the prologue) live and loads the destroy-loop end with `lw s1,0(s8)`
// (ours: lw s1,4(s5)); ours saves 7 regs instead of 8 (frame 48 both). Tried: pointer-to-field local, const reference binding, __normal_iterator-style It(const T&) ctor: all folded to 4(s5).
// near miss from lane lbp12a (unreviewed)
