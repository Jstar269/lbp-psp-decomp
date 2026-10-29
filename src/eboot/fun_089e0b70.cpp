/* LBPMATCH module=EBOOT.BIN start=0x089e0b70 end=0x089e0b9c symbol=FUN_089e0b70 lang=c++ */
/* Clone of src/eboot/fun_08973740.cpp (lbpclone.py tag c22): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); exact match verified; names and types await human review. */
struct Obj { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); unsigned flags; };
struct Parent { char pad[24]; Obj *obj; };
extern "C" void FUN_089e0b70(Parent *p) { Obj *o = p->obj; if (o->flags & 4) o->f8(); }
