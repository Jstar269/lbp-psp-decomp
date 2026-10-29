/* LBPMATCH module=EBOOT.BIN start=0x089228cc end=0x08922940 symbol=FUN_089228cc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern int *DAT_08bedb20; extern void FUN_08ad3088(void *),FUN_08ad2810(void *),FUN_08922798(void *),FUN_089222cc(void *);
void FUN_089228cc(void) { int *p=DAT_08bedb20; int *lock=p+2; FUN_08ad3088(lock); if(p[1]==0) FUN_08922798(p); else if(p[1]==5) FUN_089222cc(p); FUN_08ad2810(lock); }


// 18 words differ due to branch layout; O2 worsened it.
// near miss from lane lbp13b (unreviewed)
