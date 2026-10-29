/* LBPMATCH module=EBOOT.BIN start=0x08988e20 end=0x08988ea8 symbol=FUN_08988e20 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Pair {
  int a;
  int b;
};
struct Obj {
  void *vt;
  short size;
  short rc;
  int x;
  Pair p;
};
struct Ref {
  Obj *obj;
  Ref(Obj *o) : obj(o) {}
  Ref(const Ref &);
};
extern "C" void *DAT_08bbf5f0[];
extern "C" void *DAT_08be84a0;
extern "C" void *FUN_08adbb84(void *heap, int size);
extern "C" Ref FUN_08988e20(int x, const Pair *p)
{
  Obj *o = (Obj *)FUN_08adbb84(DAT_08be84a0, 20);
  if (o) {
    o->rc = 1;
    o->vt = DAT_08bbf5f0;
    o->x = x;
    o->p = *p;
    o->size = 20;
  }
  return Ref(o);
}
// NEAR 9 words (store order of the five field stores; all 120 permutations tried, none EXACT).
// Same shape as the sibling factory that is EXACT; retail here emits the vt/size/x/p stores in a different interleave with the size halfword last.
// near miss from lane lbp12c (unreviewed)
