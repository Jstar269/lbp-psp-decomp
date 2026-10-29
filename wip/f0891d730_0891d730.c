/* LBPMATCH module=EBOOT.BIN start=0x0891d730 end=0x0891d774 symbol=FUN_0891d730 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
extern void *FUN_08a9e838(int);
int FUN_0891d730(int *p) { int *q=FUN_08a9e838(8); q[1]=0; p[43]=8; q[0]=0; p[42]=(int)q; return q != 0; }
// One word: compiler folds pointer non-null after dereference; retail preserves comparison.
// near miss from lane lbp14d (unreviewed)
