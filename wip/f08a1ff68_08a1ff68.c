/* LBPMATCH module=EBOOT.BIN start=0x08a1ff68 end=0x08a1ffac symbol=FUN_08a1ff68 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
struct Buf { int unused; unsigned *cur; }; extern struct Buf *DAT_08bdc188; extern unsigned DAT_08bf5e20;
void FUN_08a1ff68(void) { unsigned *p=DAT_08bdc188->cur; unsigned x=DAT_08bf5e20; DAT_08bdc188->cur=p+2; p[1]=(x & 0xffffff)|0x0a000000; p[0]=((x & 0x0fffffff)>>24 <<16)|0x10000000; }

// O2 leaves four scheduling differences; Os differs 13 words.
// near miss from lane lbp14d (unreviewed)
