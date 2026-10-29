/* LBPMATCH module=EBOOT.BIN start=0x0884ec60 end=0x0884edd0 symbol=FUN_0884ec60 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct W5 { int w[5]; } __attribute__((packed));
struct Obj {
  virtual void v0();
  virtual void destroy();
  int refs;
  char pad[16];
  W5 key;
  char pad2[8];
  unsigned char flag;
};
struct Owner;
extern "C" Obj DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);
extern "C" void FUN_08849dc4(Owner *o);
extern "C" Obj *FUN_08a9e838(unsigned size);
extern "C" void FUN_0884dff0(Obj *self, Obj *a, Owner *b, int c);
extern "C" int FUN_0884ab18(Owner *o, struct Ref *r);

struct Ref {
  Obj *p;
  Ref(Obj *q) : p(q) {}
  Ref(const Ref &o) {
    Obj *q = o.p;
    p = q;
    if (q) { FUN_08ad3088(&DAT_08bef8f4); ++q->refs; FUN_08ad2810(&DAT_08bef8f4); }
  }
  ~Ref() {
    Obj *q = p;
    if (q) {
      FUN_08ad3088(&DAT_08bef8f4);
      int r = --q->refs;
      FUN_08ad2810(&DAT_08bef8f4);
      if (r == 0) q->destroy();
    }
  }
};

extern "C" int FUN_0884ec60(Owner *self, const W5 *key, unsigned char flag)
{
  FUN_08849dc4(self);
  Obj *mem = FUN_08a9e838(92);
  Ref a(mem);
  FUN_0884dff0(mem, mem, self, 2);
  a.p->key = *key;
  a.p->flag = flag;
  Ref b(a);
  return FUN_0884ab18(self, &b);
}
// NEAR: same family as 0x0884e0cc: retail keeps an extra copy of the new object pointer (s1 for the a1 argument) and an extra lui copy; see wip/FUN_0884e0cc_lbp11b.cpp.
// near miss from lane lbp11b (unreviewed)
