/* LBPMATCH module=EBOOT.BIN start=0x08a89f58 end=0x08a8a184 symbol=FUN_08a89f58 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); names and types await human review. */
extern int DAT_08bc9328;
extern void FUN_08a3535c(int *,int,int);
extern int FUN_08950f44(void), FUN_08a9b8a4(void *,void *), FUN_08a9d790(void *);
extern void FUN_08a9d390(void *,int), FUN_08a9bff8(void *);
void FUN_08a89f58(int *p,int b,int *q,int d,int e) {
 int i,j,buf[6], pair[2], result; (void)d;
 FUN_08a3535c(p,b,e); p[0]=(int)&DAT_08bc9328;
 p[86]=p[45]=p[46]=-1; p[38]=q[0]; p[39]=p[40]=p[41]=p[43]=p[44]=p[47]=p[48]=p[84]=p[85]=0; *(char *)(p+42)=0;
 for(i=0;i<4;i++) for(j=0;j<4;j++) p[52+i*4+j]=p[68+i*4+j]=(i==j)?0x3f800000:0;
 result=q[1];
 if(FUN_08950f44()) { if(result) { pair[0]=result; pair[1]=FUN_08a9b8a4(pair,(void *)result); result=FUN_08a9d790(pair); } else { FUN_08a9d390(buf,-1); FUN_08a9bff8(buf); result=-1; } FUN_08a9d390(buf,result); FUN_08a9bff8(buf); }
 FUN_08a9d390(buf,result); FUN_08a9bff8(buf); p[86]=result;
 p[64]=p[80]=0xbccccccd; p[65]=p[81]=0; p[66]=0xbc23d70a; p[82]=0xbed2f1aa; p[67]=p[83]=0x3f800000;
}

// Incomplete reconstruction: VFPU matrix operations are approximated in C; ABI and scheduling still differ.
// Initial Os compile differs in 134 words; requires explicit VFPU reconstruction and further type recovery.
// near miss from lane lbp15b (unreviewed)
