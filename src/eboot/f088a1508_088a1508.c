/* LBPMATCH module=EBOOT.BIN start=0x088a1508 end=0x088a152c symbol=FUN_088a1508 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb2410, DAT_08bee3f0;
extern void FUN_08a9e0cc(void *);
struct Obj { void *v; unsigned char flag; };
void FUN_088a1508(struct Obj *p) { p->v = &DAT_08bb2410; if (p->flag) DAT_08bee3f0 = 0; FUN_08a9e0cc(p); }

