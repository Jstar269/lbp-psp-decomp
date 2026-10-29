/* LBPMATCH module=EBOOT.BIN start=0x08864ad8 end=0x08864b30 symbol=FUN_08864ad8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern void *DAT_08bedba4; extern void FUN_0887c328(void *,void *); extern void FUN_088648dc(void *);
struct S { char pad[200]; struct { int a,b; } x; };
int FUN_08864ad8(struct S *s) { FUN_0887c328(DAT_08bedba4,&s->x); if (s->x.b==6) FUN_088648dc(s); return 1; }


// 20 words differ in register allocation and branch layout; O2 and inline member tested.
// near miss from lane lbp14b (unreviewed)
