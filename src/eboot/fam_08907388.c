/* LBPMATCH module=EBOOT.BIN start=0x08907388 end=0x089074a4 symbol=FUN_08907388 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct { int a,b; } Pair; typedef struct Obj Obj; typedef struct Vtable { void *a; void (*destroy)(Obj*); void *c; int (*init)(Obj*); } Vtable; struct Obj { Vtable *v; char pad[164]; int x,y; }; typedef struct { int a,b; long long pad[3]; } Large;
extern Vtable DAT_08bb5de8; extern void *DAT_08be84a8; extern void FUN_08a9c304(Large*,Pair*),FUN_08aaa9a0(Large*),FUN_08a9bff8(Large*),FUN_08839938(Obj*,int); extern int FUN_08a9d790(Pair*),FUN_08aaa780(int*),FUN_08aaa924(void*,Obj*); extern Obj *FUN_08a9e838(int);
Obj **FUN_08907388(Obj **out,Pair *p) { Pair q2,q,input; Large s; input.b=p->b; input.a=p->a; Obj *obj=0; FUN_08a9c304(&s,&input); FUN_08aaa9a0(&s); q.a=s.a; q.b=s.b; int id=FUN_08a9d790(&q); if(!FUN_08aaa780(&id)) { q2.a=s.a; q2.b=s.b; int id2=FUN_08a9d790(&q2); obj=FUN_08a9e838(176); FUN_08839938(obj,id2); obj->v=&DAT_08bb5de8; obj->x=0; obj->y=12; if(!obj->v->init(obj) || !FUN_08aaa924(DAT_08be84a8,obj)) { obj->v->destroy(obj); obj=0; } } *out=obj; FUN_08a9bff8(&s); return out; }




