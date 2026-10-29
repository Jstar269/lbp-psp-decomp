/* LBPMATCH module=EBOOT.BIN start=0x08956754 end=0x089567b4 symbol=FUN_08956754 lang=c99 */
/* Clone of src/eboot/f0894cf6c_0894cf6c.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
struct V { void *x[2]; int (*a)(void *); void *pad[6]; char *(*b)(void *); }; struct O { struct V *v; }; struct S { char pad[168]; struct O *o; char *p; };
int FUN_08956754(struct S *s) { int r=s->o->v->a(s->o); s->p=s->o->v->b(s->o)+16; return r; }
