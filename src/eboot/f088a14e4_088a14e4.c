/* LBPMATCH module=EBOOT.BIN start=0x088a14e4 end=0x088a1508 symbol=FUN_088a14e4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb2410, DAT_08bee3f0;
struct Obj { void *v; unsigned char flag; };
void FUN_088a14e4(struct Obj *p) { p->v = &DAT_08bb2410; if (p->flag) DAT_08bee3f0 = 0; }
