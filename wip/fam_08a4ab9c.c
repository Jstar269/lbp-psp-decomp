/* LBPMATCH module=EBOOT.BIN start=0x08a4ab9c end=0x08a4ad7c symbol=FUN_08a4ab9c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef struct Obj { int a,b,count,pad[2]; char lock[1]; } Obj;
extern void *DAT_08be84a8; extern char DAT_08bc5c5c[],DAT_08bc5c84[];
extern Obj *FUN_08aaab30(void *,char *); extern void FUN_08ad3088(void *),FUN_08ad2810(void *),FUN_088050b8(Obj *);
static void set(Obj **dst,char *name) { Obj *v=FUN_08aaab30(DAT_08be84a8,name),*old; if(v) { FUN_08ad3088(v->lock); ++v->count; FUN_08ad2810(v->lock); FUN_08ad3088(v->lock); ++v->count; FUN_08ad2810(v->lock); } old=*dst; *dst=v; if(old) FUN_088050b8(old); if(v) FUN_088050b8(v); }
void FUN_08a4ab9c(Obj **a,Obj **b,void *unused,Obj **c) { set(a,DAT_08bc5c5c); set(b,DAT_08bc5c5c); set(c,DAT_08bc5c84); }
// Three resource assignments and reference counts reconstructed; scheduling and inlining remain unverified.
// near miss from lane lbp1a (unreviewed)
