/* LBPMATCH module=EBOOT.BIN start=0x0894cf6c end=0x0894cfcc symbol=FUN_0894cf6c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
struct V { void *x[2]; int (*a)(void *); void *pad[6]; char *(*b)(void *); }; struct O { struct V *v; }; struct S { char pad[168]; struct O *o; char *p; };
int FUN_0894cf6c(struct S *s) { int r=s->o->v->a(s->o); s->p=s->o->v->b(s->o)+16; return r; }
