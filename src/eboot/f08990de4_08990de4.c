/* LBPMATCH module=EBOOT.BIN start=0x08990de4 end=0x08990e44 symbol=FUN_08990de4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bbfbc8; extern void FUN_088050b8(void *); extern void FUN_0897489c(void *); extern void FUN_08a9e0cc(void *);
struct S { void *v; char pad[36]; void *a,*b; };
void FUN_08990de4(struct S *s) { s->v=&DAT_08bbfbc8; if(s->b) FUN_088050b8(s->b); if(s->a) FUN_088050b8(s->a); FUN_0897489c(s); FUN_08a9e0cc(s); }
