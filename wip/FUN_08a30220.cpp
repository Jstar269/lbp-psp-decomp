/* LBPMATCH module=EBOOT.BIN start=0x08a30220 end=0x08a302c0 symbol=FUN_08a30220 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9a, Claude Sonnet 5.5); near miss. */
struct Pool;
struct Obj {
  virtual void destroy();
  char pad[20];
  Pool *pool;
};
struct Pool {
  Obj *base;
  Obj **freelist;
  unsigned cap;
  int nfree;
  int nlive;
};
extern "C" void FUN_08adb8a4(void *p);
extern "C" void FUN_08a30220(Obj *o)
{
  Pool *p = o->pool;
  if (o < p->base || o >= p->base + p->cap) {
    p->nlive--;
    o->destroy();
    FUN_08adb8a4(o);
    return;
  }
  int n = p->nfree - 1;
  p->freelist[n] = o;
  p->nfree = n;
  o->destroy();
}
// NEAR: layout (non-pool path first) and instruction mix match; 26 words differ only in register choice:
// retail holds the pool in a3 and the free list in a2, loads the vtable slot into a1 (non-pool) / t9 (pool);
// ours uses a2/a1/v0. An inlined Pool::release member made the layout worse (31 words).
// near miss from lane lbp9a (unreviewed)
