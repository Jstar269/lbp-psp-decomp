/* LBPMATCH module=EBOOT.BIN start=0x0883aadc end=0x0883ac04 symbol=FUN_0883aadc lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); exact match verified; names and types await human review. */
struct Ref { virtual void f(); virtual void destroy(); int count; char data[20]; int kind; };
struct Target { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void send(void *, Ref **); };
struct Owner { char pad[152]; Target *target; char pad2[4]; void *queue; };
extern "C" void *FUN_08a50fbc();
extern "C" char *FUN_08a51e74(void *, unsigned);
extern "C" unsigned *FUN_0894b31c(void *);
extern "C" void *FUN_08a9e838(unsigned);
extern "C" void FUN_08957204(void *);
extern "C" void FUN_0883aadc(Owner *self, unsigned id) {
 char *p = FUN_08a51e74(FUN_08a50fbc(), id) + 64;
 unsigned *q = FUN_0894b31c(self->queue); q[1] = 0x4d4a424f;
 Ref *obj = (Ref *)FUN_08a9e838(32); FUN_08957204(obj); Ref *r = obj;
 __builtin_memcpy(obj->data, p, 20); r->kind = 4;
 self->target->send(q, &r);
 if (r && --r->count == 0) r->destroy();
}




