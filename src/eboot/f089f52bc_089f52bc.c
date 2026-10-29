/* LBPMATCH module=EBOOT.BIN start=0x089f52bc end=0x089f531c symbol=FUN_089f52bc lang=c99 */
/* Clone of src/eboot/f08990de4_08990de4.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bc2ac0; extern void FUN_088050b8(void *); extern void FUN_0899e45c(void *); extern void FUN_08a9e0cc(void *);
struct S { void *v; char pad[36]; void *a,*b; };
void FUN_089f52bc(struct S *s) { s->v=&DAT_08bc2ac0; if(s->b) FUN_088050b8(s->b); if(s->a) FUN_088050b8(s->a); FUN_0899e45c(s); FUN_08a9e0cc(s); }
