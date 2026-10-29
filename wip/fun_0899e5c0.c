/* LBPMATCH module=EBOOT.BIN start=0x0899e5c0 end=0x0899e5e8 symbol=FUN_0899e5c0 lang=c99 rodata=0x08bab59c */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp15b, Codex GPT-6): typed fields; names and types await human review. */
struct Inner { int pad; int zero; char flag; char pad2[3]; float a,b,c; }; struct Obj { char pad[164]; struct Inner i; };
extern void FUN_0896c2a8(struct Obj *);
void FUN_0899e5c0(struct Obj *p) { p->i.flag=1; p->i.zero=0; p->i.b=1.0f; p->i.a=p->i.c; FUN_0896c2a8(p); }


// Seven words differ: scheduling and inner pointer; inline helper differed by eight.
// near miss from lane lbp15b (unreviewed)
