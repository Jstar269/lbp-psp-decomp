/* LBPMATCH module=EBOOT.BIN start=0x0896a778 end=0x0896a7fc symbol=FUN_0896a778 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); exact match verified; names and types await human review. */
struct Obj { virtual void a(); virtual void b(); virtual void c(); virtual void d(); virtual void e(); virtual void f(); virtual void g(); virtual void run(float); int flags; };
struct Parent { char pad[24]; Obj *a; Obj *b; };
extern "C" void FUN_0896a778(Parent *p, float t) { if (p->a->flags & 4) p->a->run(t); if (p->b->flags & 4) p->b->run(t); }

