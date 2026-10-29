/* LBPMATCH module=EBOOT.BIN start=0x08944cac end=0x08944d28 symbol=FUN_08944cac lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char DAT_08bb7258, DAT_08bb7530;
extern void FUN_088eaf2c(void *), FUN_088eaa24(void *,void *), FUN_0894a260(void *);
void FUN_08944cac(void **p) { void **a=p+2, **b=p+8; p[0]=&DAT_08bb7258; FUN_088eaf2c(a); FUN_088eaf2c(b); FUN_088eaa24(b,b[2]); FUN_088eaa24(a,a[2]); p[0]=&DAT_08bb7530; FUN_0894a260(p); }
// Ten words differ: saved register allocation and subobject load bases.
// near miss from lane lbp13b (unreviewed)
