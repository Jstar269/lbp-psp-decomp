/* LBPMATCH module=EBOOT.BIN start=0x08aa7f10 end=0x08aa7f98 symbol=FUN_08aa7f10 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13a, Codex GPT-6); names and types await human review. */
extern char DAT_08bcaf28, DAT_08bcaf74; extern void FUN_08aa7eb4(void *,int,int,int); extern char *FUN_08a9e824(int);
void FUN_08aa7f10(void **p,int w,int h) {
 int n=w*h, i; char *buf,*q; FUN_08aa7eb4(p,w,h,w); p[0]=&DAT_08bcaf28; p[3]=&DAT_08bcaf74;
 buf=FUN_08a9e824(n*3); q=buf; for(i=0;++i!=n+1;) { q[0]=0; q[1]=0; q[2]=0; q+=3; } p[8]=buf;
}
// 21 differences; loop form and saved register assignments differ.
// near miss from lane lbp13a (unreviewed)
