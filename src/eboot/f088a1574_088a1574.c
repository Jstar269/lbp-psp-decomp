/* LBPMATCH module=EBOOT.BIN start=0x088a1574 end=0x088a1598 symbol=FUN_088a1574 lang=c99 */
/* Clone of src/eboot/f088a14e4_088a14e4.c (lbpclone.py tag c21): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); exact match verified; names and types await human review. */
extern int DAT_08bb2360, DAT_08bee3e0;
struct Obj { void *v; unsigned char flag; };
void FUN_088a1574(struct Obj *p) { p->v = &DAT_08bb2360; if (p->flag) DAT_08bee3e0 = 0; }
