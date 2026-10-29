/* LBPMATCH module=EBOOT.BIN start=0x08a5f18c end=0x08a5f24c symbol=FUN_08a5f18c lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Rc { virtual ~Rc(); int refs; };
struct A { char x; };
struct B { char x; };
struct Self {
  const void *vt;
  char pad[388];
  Rc *rc;
  char pad2[68];
  A *a;
  B *b;
};
extern "C" char DAT_08bc6978[];
extern "C" void FUN_08a1d34c(A *);
extern "C" void FUN_08a1def0(B *);
extern "C" void FUN_08a9e0cc(void *);
extern "C" void FUN_08adb8a4(void *);
extern "C" void FUN_08a722cc(void *);
extern "C" void FUN_08a5f18c(Self *self)
{
  self->vt = DAT_08bc6978;
  A *a = self->a;
  if (a) { FUN_08a1d34c(a); FUN_08a9e0cc(a); }
  B *b = self->b;
  if (b) { FUN_08a1def0(b); FUN_08a9e0cc(b); }
  Rc *r = self->rc;
  if (r) {
    if (--r->refs == 0) {
      r->~Rc();
      FUN_08adb8a4(r);
    }
  }
  FUN_08a722cc(self);
}
