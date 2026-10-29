/* LBPMATCH module=EBOOT.BIN start=0x089d9b80 end=0x089d9bf0 symbol=FUN_089d9b80 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp6b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Obj { int a; short b; unsigned short count; int type; };
extern "C" void FUN_08970b6c(Obj *o);
struct Ref {
  Obj *p;
  Ref(const Ref &o) : p(o.p) { if (p) p->count++; }
  ~Ref() { if (p) FUN_08970b6c(p); }
};
extern "C" int FUN_089de898(void *self, Ref *r);
extern "C" int FUN_089d9b80(void *self, Ref *src)
{
  int r = 0;
  if ((unsigned)(src->p->type - 3000) >= 2) {
    Ref tmp(*src);
    r = FUN_089de898(self, &tmp);
  }
  return r;
}
// ref-counted pointer temporary (copy-ctor increments, destructor releases); no exceptions.
