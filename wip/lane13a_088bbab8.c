/* LBPMATCH module=EBOOT.BIN start=0x088bbab8 end=0x088bbb4c symbol=FUN_088bbab8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
extern char *DAT_08bedb1c; extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
void FUN_088bbab8(void) {
 int i; char *p, *lock;
 for(i=0;i!=2;i++) { p=DAT_08bedb1c; lock=p+0x614; FUN_08ad3088(lock); FUN_08ad3088(lock); (i+p)[0x6b0]=0; FUN_08ad2810(lock); FUN_08ad2810(lock); }
 p=DAT_08bedb1c; lock=p+0x614; FUN_08ad3088(lock); p[0x6f4]=0; FUN_08ad2810(lock);
}
// One word differs: commutative addu operands reversed; swapping source operands did not change it.
// near miss from lane lbp13a (unreviewed)
