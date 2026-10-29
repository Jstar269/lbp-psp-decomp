/* LBPMATCH module=EBOOT.BIN start=0x088ef7f8 end=0x088ef8a0 symbol=FUN_088ef7f8 lang=c99 */
/* Ghidra pseudocode (lbpgen.py tag g14) corrected by hand (lane lbp13a, Codex GPT-6): named global and iterator locals; names and types await human review. */
extern char DAT_08beedc4;
extern void *FUN_088e6e1c(void *, void *), *FUN_088e7d14(void *, void *), *FUN_08b89838(void *);
extern void FUN_088ef50c(void *, void *, void *), FUN_08a9df6c(void *);
void FUN_088ef7f8(char **p) {
 char *key=*p; void *a=FUN_088e6e1c(&DAT_08beedc4,&key); void *b=FUN_088e7d14(&DAT_08beedc4,&key); void *i;
 for(i=a;i!=b;i=FUN_08b89838(i)) { }
 FUN_088ef50c(&DAT_08beedc4,a,b);
 if (*(void **)(*p+44)) FUN_08a9df6c(*(void **)(*p+44));
}
// 16 differences after missing two stack stores before call; iterator aggregate calling convention may explain them.
// near miss from lane lbp13a (unreviewed)
