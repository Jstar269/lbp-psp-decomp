/* LBPMATCH module=EBOOT.BIN start=0x08a6ae00 end=0x08a6ae78 symbol=FUN_08a6ae00 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
extern char DAT_08bc7890; extern void FUN_08a5f124(void *,int,int,unsigned char);
void FUN_08a6ae00(int *p,int a,int b,unsigned char c) { char *q=(char *)p; FUN_08a5f124(p,a,b,c); p[0]=(int)&DAT_08bc7890; p[146]=1; q[561]=0; q[562]=0; q[563]=0; p[141]=0; p[142]=0; p[143]=0; p[145]=1; p[144]=1; if(p[17]==31) q[55]=c; }



// Eight words differ due to ordering of constructor field stores; three orders tried.
// near miss from lane lbp13b (unreviewed)
