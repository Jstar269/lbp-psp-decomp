/* LBPMATCH module=EBOOT.BIN start=0x088afcd4 end=0x088afe34 symbol=FUN_088afcd4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void *DAT_08be84a0; extern char *FUN_08adbb84(void *,int); extern void FUN_08adbc24(void *,void *,int), FUN_08b88fac(void *,void *), FUN_08b88fc8(void *);
void FUN_088afcd4(char *self, char **iter) {
 char *head=self+12, *cur=*iter, *next=*(char **)cur, *prev, *p; short a[3];
 prev=*(char **)((cur==*(char **)head ? head:cur)+4); if(next==head) next=*(char **)head;
 a[0]=*(short *)(prev+8); a[1]=*(short *)(next+8);
 p=FUN_08adbb84(DAT_08be84a0,12); if(p+8) __builtin_memcpy(p+8,a,4); FUN_08b88fac(p,self+20);
 a[1]=*(short *)(*iter+8); a[2]=*(short *)(next+8);
 p=FUN_08adbb84(DAT_08be84a0,16); if(p+8) { __builtin_memcpy(p+8,a,4); *(short *)(p+12)=a[2]; } FUN_08b88fac(p,self+28);
 cur=*iter; next=*(char **)cur; if(next==head) next=*(char **)head; FUN_08b88fc8(cur); FUN_08adbc24(DAT_08be84a0,cur,12); *iter=next;
}
// List and temporary layout require refinement.
// near miss from lane lbp13c (unreviewed)
