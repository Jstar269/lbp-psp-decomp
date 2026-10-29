/* LBPMATCH module=EBOOT.BIN start=0x089e1438 end=0x089e14c0 symbol=FUN_089e1438 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
extern char DAT_08bc1c40; extern void FUN_0896b21c(void *), FUN_089e1168(void *);
void FUN_089e1438(unsigned *p,unsigned *q,unsigned x) {
 unsigned flags; FUN_0896b21c(p); flags=p[1]|0x3002; p[11]=-1; p[1]=flags; p[9]=-1; p[10]=-1;
 p[0]=(unsigned)&DAT_08bc1c40; p[7]=x; p[1]=flags|(q[1]&2); q[2]=(unsigned)p; p[6]=(unsigned)q; p[8]=0; FUN_089e1168(p);
}
// 16 words differ due to scheduling and store ordering at Os and O2.
// near miss from lane lbp13a (unreviewed)
