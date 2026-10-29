/* LBPMATCH module=EBOOT.BIN start=0x08a7480c end=0x08a74984 symbol=FUN_08a7480c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15b, Codex GPT-6); names and types await human review. */
extern int DAT_08bc7fd8;
extern void FUN_08a3535c(int *,int,int), FUN_08a556e8(void *), FUN_08a55714(void *,void *), FUN_08b9eb88(void *,int,int), FUN_08a556bc(void *), FUN_08a55004(void *,void *), FUN_08811284(float,void *);
extern void *FUN_08a9e838(int);
void FUN_08a7480c(int *p,int b,int *q,char flag,int e) {
 int i,j,mat[16]; void *v; FUN_08a3535c(p,b,e); p[0]=(int)&DAT_08bc7fd8;
 p[39]=p[40]=(int)(p+39); p[41]=p[42]=p[43]=p[45]=p[46]=0; FUN_08a556e8(p+47);
 for(i=0;i<4;i++) for(j=0;j<4;j++) p[76+i*4+j]=(i==j)?0x3f800000:0;
 p[93]=0; *(char *)(p+94)=0; p[96]=0; *(short *)(p+97)=0;
 if(q) { FUN_08a55714(p+47,q); if(flag && *q) { v=FUN_08a9e838(40); FUN_08a556bc(v); p[47]=(int)v; FUN_08a55004((void *)*q,v); } p[92]=q[28]; }
 else FUN_08b9eb88(p+47,0,116);
 FUN_08811284(*(float *)(p+74),mat); for(i=0;i<12;i++) p[20+i]=mat[i]; p[32]=p[68]; p[33]=p[69]; p[34]=p[70]; p[35]=0x3f800000;
 if(q) p[92]=q[28]; p[44]=p[38]=0;
}

// Incomplete reconstruction: VFPU matrix operations are approximated in C; ABI and scheduling still differ.
// Initial Os compile differs in 95 words; requires explicit VFPU reconstruction and further type recovery.
// near miss from lane lbp15b (unreviewed)
