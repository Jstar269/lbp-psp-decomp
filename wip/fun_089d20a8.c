/* LBPMATCH module=EBOOT.BIN start=0x089d20a8 end=0x089d222c symbol=FUN_089d20a8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char *DAT_08be85fc; extern float FUN_08b84224(float); extern void FUN_089694b0(void *), FUN_089690c8(void *), FUN_08977bb4(void *,void *,void *,void *,int), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_088050b8(void *);
void FUN_089d20a8(char *self,const char *src) {
 short buf[4]; char *p,*head=self+184,*v,*old;
 __builtin_memcpy(buf,src,8);
 if(buf[2]!=32767) buf[2]=(int)FUN_08b84224((float)buf[2]/ *(float *)(*(char **)(self+40)+8));
 if(buf[3]!=32767) buf[3]=(int)FUN_08b84224((float)buf[3]/ *(float *)(*(char **)(self+40)+8));
 FUN_089694b0(self+56); FUN_08977bb4(self+24,buf,self+56,head,1); FUN_089690c8(self+56);
 for(p=*(char **)head;p!=head;p=*(char **)p) {
  v=*(char **)(DAT_08be85fc+*(int *)(p+16)*4+12);
  if(v) { FUN_08ad3088(v+20); ++*(int *)(v+8); FUN_08ad2810(v+20); FUN_08ad3088(v+20); ++*(int *)(v+8); FUN_08ad2810(v+20); }
  old=*(char **)(p+20); *(char **)(p+20)=v; if(old) FUN_088050b8(old); if(v) FUN_088050b8(v);
 }
 *(unsigned *)(self+4)&=~8u;
}
// Floating-point and reference handling layout differ.
// near miss from lane lbp13c (unreviewed)
