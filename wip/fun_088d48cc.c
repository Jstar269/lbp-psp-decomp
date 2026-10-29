/* LBPMATCH module=EBOOT.BIN start=0x088d48cc end=0x088d4ae0 symbol=FUN_088d48cc lang=c99 rodata=0x08bab5d0 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_088d40b8(void *),FUN_08b9eb88(void *,int,int);
void FUN_088d48cc(char *p,unsigned *arg,char *ctx) { int i; unsigned a=arg[0],b=arg[1],n; float f;
 *(int *)(p+40)=2; *(short *)(p+124)=-1; *(short *)(p+130)=255; *(int *)(p+28)=0x31324546;
 *(short *)(p+20)=*(short *)(p+22)=*(short *)(p+24)=*(short *)(p+26)=0; *(int *)(p+32)=*(int *)(p+100)=*(int *)(p+104)=0; *(short *)(p+126)=0; *(int *)(p+56)=65535; for(i=0;i<5;i++) ((int *)p)[i]=0; *(int *)(p+36)=*(int *)(p+112)=*(int *)(p+116)=*(int *)(p+120)=0; p[143]=0;
 for(i=0;i<10;i++) { p[144+8*i]=0; p[145+8*i]=0; *(short *)(p+146+8*i)=0; *(int *)(p+148+8*i)=0; }
 *(int *)(p+56)=b; *(int *)(p+32)=a; *(int *)(p+36)=b; __builtin_memcpy(p+60,ctx+44,20); *(short *)(p+126)=*(short *)(ctx+72); FUN_08b9eb88(p+132,0,10); if(ctx[96]) *(int *)p |=2; FUN_088d40b8(p); n=*(unsigned *)(ctx+80); if(n>2000000000) n=2000000000; *(unsigned *)(p+16)=n; *(short *)(p+128)=*(int *)(ctx+76); f=*(float *)(ctx+88); if(f>5.0f) f=5.0f; p[142]=(unsigned)f; *(int *)(p+108)=1536; __builtin_memcpy(p+80,*(char **)(ctx+24)+12,20);
}
// 144 words differ; initialization ordering and constant placement remain unresolved.
// near miss from lane lbp13d (unreviewed)
