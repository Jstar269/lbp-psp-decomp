/* LBPMATCH module=EBOOT.BIN start=0x08a2397c end=0x08a239bc symbol=FUN_08a2397c lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
struct Buf { int unused; unsigned *cur; }; extern struct Buf *DAT_08bdc18c; extern unsigned DAT_08bf5e20;
void FUN_08a2397c(unsigned *arg) { unsigned *p=DAT_08bdc18c->cur; unsigned x=*arg; DAT_08bdc18c->cur=p+2; p[1]=(x & 0xffffff)|0x0a000000; p[0]=((x & 0x0fffffff)>>24 <<16)|0x10000000; }



// Four words differ in constant load and OR scheduling at O2.
// near miss from lane lbp14d (unreviewed)
