/* LBPMATCH module=EBOOT.BIN start=0x0883d9ec end=0x0883dbac symbol=FUN_0883d9ec lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void FUN_088406cc(void *,int), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_088050b8(void *);
char *FUN_0883d9ec(char *self) {
 char *base,*dst,*src,*ref,*old; int n,id,i;
 if(self[220]) return 0;
 base=*(char **)self; n=*(int *)(self+12);
 if(n==(*(char **)(self+4)-base)/28) {
  id=*(int *)base; FUN_088406cc(base,0); base=*(char **)self; dst=base; src=base+28;
  for(i=(*(char **)(self+4)-src)/28;i>0;--i,src+=28,dst+=28) {
   ref=*(char **)(src+16); __builtin_memcpy(dst,src,16);
   if(ref) { FUN_08ad3088(ref+20); ++*(int *)(ref+8); FUN_08ad2810(ref+20); }
   old=*(char **)(dst+16); *(char **)(dst+16)=ref; if(old) FUN_088050b8(old); __builtin_memcpy(dst+20,src+20,8);
  }
  n=--*(int *)(self+12); FUN_088406cc(base+n*28,1); n=*(int *)(self+12);
 } else { id=n; if(*(int *)(base+n*28)!=-1) id=*(int *)(base+n*28); }
 dst=*(char **)self+n*28; *(int *)(self+120)=n; *(int *)dst=id; return dst;
}
// Array loop and register allocation differ.
// near miss from lane lbp13c (unreviewed)
