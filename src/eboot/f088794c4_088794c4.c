/* LBPMATCH module=EBOOT.BIN start=0x088794c4 end=0x08879520 symbol=FUN_088794c4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb07d0,DAT_08bb0804,DAT_08bb0828,DAT_08bb0848; extern void FUN_0888b898(void *); extern void FUN_0894a260(void *);
struct S { void *v; char a[8]; void *w; char b[8]; char c[1]; };
void FUN_088794c4(struct S *s) { s->v=&DAT_08bb07d0; s->w=&DAT_08bb0804; FUN_0888b898(s->c); s->w=&DAT_08bb0828; s->v=&DAT_08bb0848; FUN_0894a260(s); }
