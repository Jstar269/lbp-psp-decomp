/* LBPMATCH module=EBOOT.BIN start=0x089ce210 end=0x089ce268 symbol=FUN_089ce210 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp14c, Codex GPT-6); names and types await human review. */
extern void *DAT_08bf0380, DAT_08bc1368;
extern void FUN_089e15dc(void *,void *,void *), FUN_088050b8(void *), FUN_089d1988(void *);
void FUN_089ce210(void **p) { p[0]=&DAT_08bc1368; FUN_089e15dc(DAT_08bf0380,&p[8],p[7]); if(p[8]) FUN_088050b8(p[8]); FUN_089d1988(p); }
// 11 words differ in initial scheduling; O2 also differs.
// near miss from lane lbp14c (unreviewed)
