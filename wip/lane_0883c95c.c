/* LBPMATCH module=EBOOT.BIN start=0x0883c95c end=0x0883cc1c symbol=FUN_0883c95c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct { char p[4]; char *cur; char p2[12]; int off; char p3[24]; void *owner; } Stream;
typedef struct { char pad[32]; int n1; void *p1; int n2,n3; void *p2; int n4,n5; void *p3; char data[20]; int n6; void *p6; int n7; void *p7; } Obj;
extern void FUN_0883c870(void *,Stream **,int,Obj *,int);
extern int FUN_08954cc4(void *); extern void FUN_08954e6c(Stream *,const void *,int,int); extern void FUN_0895541c(Stream **);
static inline void put(Stream *s,int v) { if(!FUN_08954cc4(s->owner)) __builtin_memcpy(s->cur,&v,4); s->off+=4; s->cur+=4; }
void FUN_0883c95c(void *a,Stream **s,Obj *o,int d) {
 int n; FUN_0883c870(a,s,0x4d5a5045,o,d);
 put(*s,o->n1); FUN_08954e6c(*s,o->p1,1,o->n1);
 n=o->n2; put(*s,n); put(*s,o->n3); if(o->n3) n=o->n3; FUN_08954e6c(*s,o->p2,1,n);
 n=o->n4; put(*s,n); put(*s,o->n5); FUN_08954e6c(*s,o->data,1,20); if(o->n5) n=o->n5; FUN_08954e6c(*s,o->p3,1,n);
 put(*s,o->n6); FUN_08954e6c(*s,o->p6,1,o->n6); put(*s,o->n7); FUN_08954e6c(*s,o->p7,1,o->n7); FUN_0895541c(s);
}

// Near: stream writer register allocation and scheduling differ; O2 also tested.
// near miss from lane lbp15d (unreviewed)
