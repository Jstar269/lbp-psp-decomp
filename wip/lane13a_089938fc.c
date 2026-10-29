/* LBPMATCH module=EBOOT.BIN start=0x089938fc end=0x08993990 symbol=FUN_089938fc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
typedef struct Ref { int a,b,count,c,d; char lock[4]; } Ref; typedef struct Pair { int a,b; } Pair;
extern void FUN_08877780(Ref **, Pair *), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_088050b8(void *);
Ref **FUN_089938fc(Ref **out, int unused, Pair *p) {
 Ref *r; Pair q; q.b=p->b; q.a=p->a; Ref *v; FUN_08877780(&r,&q); v=r; *out=v;
 if (v) { FUN_08ad3088(v->lock); ++v->count; FUN_08ad2810(v->lock); }
 if(r) FUN_088050b8(r); return out;
}
// 2 words differ: initial loads v0/v1 swapped; O2 differs by 6.
// near miss from lane lbp13a (unreviewed)
