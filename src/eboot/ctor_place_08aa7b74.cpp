/* LBPMATCH module=EBOOT.BIN start=0x08aa7b74 end=0x08aa7bcc symbol=FUN_08aa7b74 lang=c++ */
/* Clone of src/eboot/ctor_place_08aa716c.cpp (lbpclone.py tag c18): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" void *DAT_08bcb144[];
extern "C" void *DAT_08bcb0f8[];
extern "C" void FUN_08aa7afc(void *o, int a, int b, int c, int d);
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
    FUN_08aa7afc(this, a, b, c, d);
    vt = DAT_08bcb0f8;
    sub.vt = DAT_08bcb144;
  }
};
extern "C" void FUN_08aa7b74(Obj *o)
{
  const Sub &s = o->sub;
  int a = s.f1, b = s.f2, c = s.f3, d = s.f4;
  new (o) Obj(a, b, c, d);
}
