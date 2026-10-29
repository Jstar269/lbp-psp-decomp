/* LBPMATCH module=EBOOT.BIN start=0x08aa7954 end=0x08aa797c symbol=FUN_08aa7954 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14b, Codex GPT-6); exact match verified; names and types await human review. */
extern void FUN_08aa78dc(void *, int, int, int, int);
void FUN_08aa7954(int *p) { int *q = p + 3; if (p) FUN_08aa78dc(p,q[1],q[2],q[3],q[5]); }
// 10 words differ: compiler moves the null check before the loads; O2 removes it.
// near miss from lane lbp14b (unreviewed)
