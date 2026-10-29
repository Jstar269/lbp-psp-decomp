/* LBPMATCH module=EBOOT.BIN start=0x08aa6c00 end=0x08aa6c34 symbol=FUN_08aa6c00 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char DAT_08bcb398;
void FUN_08aa6c00(void **p, void *a, void *b, void *c, void *d) { void **q=p+5; p[1]=a; p[2]=b; p[3]=c; p[4]=d; p[0]=&DAT_08bcb398; q[0]=0; q[3]=b; q[1]=a; q[2]=c; }
// Twelve differing words: stores scheduled and addressed differently; explicit subobject pointer folded.
// near miss from lane lbp13b (unreviewed)
