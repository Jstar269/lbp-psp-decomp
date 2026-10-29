/* LBPMATCH module=EBOOT.BIN start=0x088cf978 end=0x088cf9f0 symbol=FUN_088cf978 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char *DAT_08beed14,*DAT_08beed8c;
extern void *FUN_088d7f9c(void); extern void FUN_088f73dc(void *),FUN_088e4020(void *,void *,int);
void FUN_088cf978(void) { char *a,*b,*q; unsigned short i; void *v; FUN_088f73dc(FUN_088d7f9c()); a=DAT_08beed14; b=DAT_08beed8c; i=*(unsigned short *)(a+596); b[86]=1; if (i==65535) v=0; else { q=*(char **)(a+336)+i*40; v=q ? *(void **)(q+4) : 0; } FUN_088e4020(b,v,1); }
// Twenty words differ after index load; retail retains zero extension and shift order.
// near miss from lane lbp13b (unreviewed)
