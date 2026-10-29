/* LBPMATCH module=EBOOT.BIN start=0x089ab4f0 end=0x089ab578 symbol=FUN_089ab4f0 lang=c++ */
/* Clone of src/eboot/pooled_ref_factory_vt_08993684.cpp (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void *DAT_08bc0788[];
extern "C" void *DAT_08be84a0;
extern "C" void *FUN_08adbb84(void *heap, int size);
extern "C" Ref FUN_089ab4f0(int x, const Pair *p)
{
  Obj *o = (Obj *)FUN_08adbb84(DAT_08be84a0, 20);
  if (o) {
    o->rc = 1;
    o->vt = DAT_08bc0788;
    o->x = x;
    o->p = *p;
    o->size = 20;
  }
  return Ref(o);
}
