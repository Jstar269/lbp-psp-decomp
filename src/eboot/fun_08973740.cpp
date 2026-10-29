/* LBPMATCH module=EBOOT.BIN start=0x08973740 end=0x0897376c symbol=FUN_08973740 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); unsigned flags; };
struct Parent { char pad[24]; Obj *obj; };
extern "C" void FUN_08973740(Parent *p) { Obj *o = p->obj; if (o->flags & 4) o->f8(); }
