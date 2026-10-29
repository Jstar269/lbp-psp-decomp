/* LBPMATCH module=EBOOT.BIN start=0x088f3b0c end=0x088f3ca4 symbol=FUN_088f3b0c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void *DAT_08be84a0,*DAT_08bedc30; extern char DAT_08bef8f4;
extern void *FUN_08adbb84(void *,int); extern void FUN_08b88fac(void *,void *),FUN_088ed040(void *,int),FUN_08896abc(void *,void *,void *),FUN_08881018(void *,int,void *,int),FUN_08ad3088(void *),FUN_08ad2810(void *);
void FUN_088f3b0c(char *self,const char *src) { char data[20],tmp[20]; int *ref; char *node; int n;
 __builtin_memcpy(data,src,20); *(int *)(self+68)=19; node=FUN_08adbb84(DAT_08be84a0,28); if(node+8) __builtin_memcpy(node+8,data,20); FUN_08b88fac(node,self+312); FUN_088ed040(self,1); FUN_08896abc(&ref,DAT_08bedc30,data);
 if(!ref) { *(int *)(self+72)=1; __builtin_memcpy(tmp,data,20); FUN_08881018(*(void **)(self+64),10,tmp,0); } else { FUN_08ad3088(&DAT_08bef8f4); n=--ref[1]; FUN_08ad2810(&DAT_08bef8f4); if(!n) (*(void (**)(void *))(*(char **)ref+8))(ref); }
}
// 101 words differ; stack layout and reference handling remain unresolved.
// near miss from lane lbp13d (unreviewed)
