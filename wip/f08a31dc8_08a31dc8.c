/* LBPMATCH module=EBOOT.BIN start=0x08a31dc8 end=0x08a31e0c symbol=FUN_08a31dc8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
extern int DAT_08bc7fd8; extern void FUN_08a31c30(void *, int); extern void FUN_08a556e8(void *);
void FUN_08a31dc8(void **p, int a) { FUN_08a31c30(p,a); p[0]=&DAT_08bc7fd8; p[39]=p+39; p[40]=p+39; p[45]=0; FUN_08a556e8(p+47); }


// One word differs: store uses base s0 rather than subobject pointer v1.
// near miss from lane lbp14d (unreviewed)
