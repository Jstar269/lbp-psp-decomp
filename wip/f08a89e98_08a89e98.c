/* LBPMATCH module=EBOOT.BIN start=0x08a89e98 end=0x08a89ee0 symbol=FUN_08a89e98 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp14d, Codex GPT-6); names and types await human review. */
extern int DAT_08bc9328; extern void FUN_08a31c30(void *,int);
void FUN_08a89e98(int *p,int a) { FUN_08a31c30(p,a); p[0]=(int)&DAT_08bc9328; p[86]=-1; p[45]=-1; p[46]=-1; p[47]=0; p[48]=0; }
// Six store-order differences at O2; revisit typed fields and scheduling.
// near miss from lane lbp14d (unreviewed)
