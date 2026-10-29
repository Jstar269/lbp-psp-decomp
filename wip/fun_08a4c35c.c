/* LBPMATCH module=EBOOT.BIN start=0x08a4c35c end=0x08a4c488 symbol=FUN_08a4c35c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char DAT_08bc5cf0, DAT_08bc5ce0;
void FUN_08a4c35c(char *p, const char *a, int b,int c,int d,int e,int f,int g,int h,int i,const char *j,int k,int l,int m,int n) {
 *(void **)p=&DAT_08bc5cf0; *(int *)(p+28)=40; *(int *)(p+4)=0; __builtin_memcpy(p+8,a,20);
 *(void **)p=&DAT_08bc5ce0; *(int *)(p+32)=b; *(int *)(p+36)=c; *(int *)(p+40)=d; *(int *)(p+44)=e; *(int *)(p+48)=f; *(int *)(p+52)=g; *(int *)(p+56)=h; *(int *)(p+60)=i;
 __builtin_memcpy(p+64,j,20); *(int *)(p+84)=k; *(int *)(p+88)=l; *(int *)(p+92)=m; *(int *)(p+96)=n;
}
// 41 words differ; vtable store ordering and register scheduling need work.
// near miss from lane lbp13c (unreviewed)
