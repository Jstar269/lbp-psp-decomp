/* LBPMATCH module=EBOOT.BIN start=0x088b526c end=0x088b5468 symbol=FUN_088b526c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
struct Pair { int a,b; }; struct Large { int a,b; char pad[32]; }; struct Obj { int a,b,count; char pad[8]; char lock[4]; };
extern void *DAT_08be84a8; extern "C" void FUN_08a9c304(Large*,Pair*), FUN_08946ce8(Large*), FUN_08a9bff8(Large*), FUN_08877780(Obj**,Pair*), FUN_088050b8(Obj*), FUN_08ad3088(void*),FUN_08ad2810(void*); extern "C" int FUN_08aaab78(Pair*); extern "C" Obj *FUN_08aaaa80(void*,Large*); extern "C" void FUN_088c32b8(void*,Obj**,Pair*,int,int); extern "C" long long FUN_0883d904(void*,void*);
inline void inc(Obj *p) { if(p) { FUN_08ad3088(p->lock); p->count++; FUN_08ad2810(p->lock); } }
extern "C" void FUN_088b526c(void *self, Pair *p, int x, int y) { Pair input=*p; Large s; FUN_08a9c304(&s,&input); FUN_08946ce8(&s); Pair tmp={s.a,s.b}; int flag=FUN_08aaab78(&tmp); Obj *a; if (!flag) { tmp.a=s.a; tmp.b=s.b; FUN_08877780(&a,&tmp); } else { a=FUN_08aaaa80(DAT_08be84a8,&s); inc(a); } Obj *v=a; inc(v); if(a) FUN_088050b8(a); if(!flag) { Obj *t=v; inc(t); FUN_088c32b8(self,&t,&input,x,y); if(t) FUN_088050b8(t); } else { struct {int id; Obj *obj;} t={v->b,v}; inc(v); FUN_0883d904((char*)self+84,&t); if(t.obj) FUN_088050b8(t.obj); } if(v) FUN_088050b8(v); FUN_08a9bff8(&s); }

// Stack layout and C++ temporary lifetime differ; initial reconstruction is 115 words off.
// near miss from lane lbp1a (unreviewed)
