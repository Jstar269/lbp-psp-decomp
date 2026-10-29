/* LBPMATCH module=EBOOT.BIN start=0x0891c124 end=0x0891c198 symbol=FUN_0891c124 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
typedef struct Obj Obj; typedef struct Other Other;
struct Other { void (**vt)(Other *,void *); }; struct Obj { void (**vt)(Obj *,void *); char pad[12]; unsigned char flag; char pad2[151]; Other *child; };
int FUN_0891c124(Obj *p,int a,int *out,int b,unsigned char c) { if(c) { p->child->vt[3](p->child,out); p->flag=1; *out=0; } else p->vt[5](p,out); return 1; }
// One word differs: redundant second-argument move in delay slot. Casting callee to one-argument prototype produced EXACT but obscures actual argument and was rejected.
// near miss from lane lbp13b (unreviewed)
