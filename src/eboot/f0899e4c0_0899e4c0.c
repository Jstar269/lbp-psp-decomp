/* LBPMATCH module=EBOOT.BIN start=0x0899e4c0 end=0x0899e524 symbol=FUN_0899e4c0 lang=c99 */
/* Clone of src/eboot/f0899e45c_0899e45c.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern char DAT_08bc04a8;
extern void FUN_0890451c(void *);
extern void FUN_088050b8(void *);
struct S { void *v; char a[4]; void *p; char b[12]; void *q; char c[4]; char d[1]; };
void FUN_0899e4c0(struct S *s) {
 s->v = &DAT_08bc04a8;
 FUN_0890451c(s->d);
 if (s->q) FUN_088050b8(s->q);
 if (s->p) FUN_088050b8(s->p);
}
