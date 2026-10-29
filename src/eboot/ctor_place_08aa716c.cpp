/* LBPMATCH module=EBOOT.BIN start=0x08aa716c end=0x08aa71c4 symbol=FUN_08aa716c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *DAT_08bcb314[];
extern "C" void *DAT_08bcb2c8[];
extern "C" void FUN_08aa70f4(void *o, int a, int b, int c, int d);
struct Sub {
  void **vt;
  int f1, f2, f3, pad2, f4;
};
struct Obj {
  void **vt;
  int pad[2];
  Sub sub;
  Obj(int a, int b, int c, int d)
  {
    FUN_08aa70f4(this, a, b, c, d);
    vt = DAT_08bcb2c8;
    sub.vt = DAT_08bcb314;
  }
};
extern "C" void FUN_08aa716c(Obj *o)
{
  const Sub &s = o->sub;
  int a = s.f1, b = s.f2, c = s.f3, d = s.f4;
  new (o) Obj(a, b, c, d);
}
