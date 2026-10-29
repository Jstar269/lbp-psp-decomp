/* LBPMATCH module=EBOOT.BIN start=0x0887952c end=0x08879588 symbol=FUN_0887952c lang=c99 */
/* Clone of src/eboot/f088794c4_088794c4.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bb07d0,DAT_08bb0804,DAT_08bb0828,DAT_08bb0848; extern void FUN_0888b898(void *); extern void FUN_0894a260(void *);
struct S { void *v; char a[8]; void *w; char b[8]; char c[1]; };
void FUN_0887952c(struct S *s) { s->v=&DAT_08bb07d0; s->w=&DAT_08bb0804; FUN_0888b898(s->c); s->w=&DAT_08bb0828; s->v=&DAT_08bb0848; FUN_0894a260(s); }
