/* LBPMATCH module=EBOOT.BIN start=0x0885a98c end=0x0885aa4c symbol=FUN_0885a98c lang=c++ */
/* Clone of src/eboot/FUN_0885a518.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj {
  virtual void v0();
  virtual void destroy();
  int refs;
};
struct Lock { int x; };
struct Self { char pad[216]; char sub[1]; };
extern "C" Lock DAT_08bef8f4;
extern "C" void FUN_0885cacc(Obj **out, Self *self);
extern "C" void *FUN_08875f58(Obj *o, int *k);
extern "C" void FUN_08847554(void *dst, void *src, int a, int b);
extern "C" void FUN_08ad3088(void *lock);
extern "C" void FUN_08ad2810(void *lock);

extern "C" void *FUN_0885a98c(Self *self)
{
  Obj *o;
  int k = 0;
  FUN_0885cacc(&o, self);
  void *r = FUN_08875f58(o, &k);
  Obj *p = o;
  if (p) {
    FUN_08ad3088(&DAT_08bef8f4);
    int n = p->refs - 1;
    p->refs = n;
    FUN_08ad2810(&DAT_08bef8f4);
    if (n == 0) p->destroy();
  }
  FUN_08847554(self->sub, r, 0, 1);
  return self->sub;
}
