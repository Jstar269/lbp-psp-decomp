/* LBPMATCH module=EBOOT.BIN start=0x088e5f80 end=0x088e60a0 symbol=FUN_088e5f80 lang=c99 rodata=0x08bb49a0 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern int DAT_08bb440c; extern void *DAT_08beee0c;
extern int FUN_088e3e74(void *,int,int,int); extern void FUN_088f3748(void *,void *);
void FUN_088e5f80(char *self, const char *src, int arg) {
 struct { int kind, start, count, unused; void *p, *q; } msg;
 if (FUN_088e3e74(self,14,arg,DAT_08bb440c)) {
  *(const char **)(self+140)=src; __builtin_memcpy(self+120,src,20);
  msg.count=*(int *)(self+40); msg.start=(*(int *)(self+36)-1)*msg.count+1;
  switch (*(int *)(self+28)) {
   case 10: msg.kind=0; break; case 11: msg.kind=9; break; case 12: msg.kind=8; break;
   case 13: msg.kind=7; msg.q=self+146; break; case 14: msg.kind=4; msg.p=self+120; break;
  }
  FUN_088f3748(DAT_08beee0c,&msg);
 }
}

// Switch layout and copy scheduling need work.
// near miss from lane lbp13c (unreviewed)
