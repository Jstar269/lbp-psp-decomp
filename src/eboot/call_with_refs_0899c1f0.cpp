/* LBPMATCH module=EBOOT.BIN start=0x0899c1f0 end=0x0899c290 symbol=FUN_0899c1f0 lang=c++ */
/* Clone of src/eboot/call_with_refs_08995480.cpp (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { int a; short b; unsigned short count; int type; };
extern "C" void FUN_08970b6c(Obj *o);
struct Ref {
  Obj *p;
  Ref(const Ref &o) : p(o.p) { if (p) p->count++; }
  ~Ref() { if (p) FUN_08970b6c(p); }
};
extern "C" void FUN_0899c064(void *self, const Ref &r);
extern "C" void FUN_089745b8(void *self, const Ref &r);
extern "C" void FUN_0899c1f0(void *self, Ref *src)
{
  FUN_0899c064(self, Ref(*src));
  FUN_089745b8(self, Ref(*src));
}
// ref-counted pointer temporaries passed as const Ref& (full-expression temporaries keep separate stack slots; block-scoped locals share one).
