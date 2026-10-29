/* LBPMATCH module=EBOOT.BIN start=0x08995480 end=0x08995520 symbol=FUN_08995480 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { int a; short b; unsigned short count; int type; };
extern "C" void FUN_08970b6c(Obj *o);
struct Ref {
  Obj *p;
  Ref(const Ref &o) : p(o.p) { if (p) p->count++; }
  ~Ref() { if (p) FUN_08970b6c(p); }
};
extern "C" void FUN_089951a4(void *self, const Ref &r);
extern "C" void FUN_089745b8(void *self, const Ref &r);
extern "C" void FUN_08995480(void *self, Ref *src)
{
  FUN_089951a4(self, Ref(*src));
  FUN_089745b8(self, Ref(*src));
}
// ref-counted pointer temporaries passed as const Ref& (full-expression temporaries keep separate stack slots; block-scoped locals share one).
