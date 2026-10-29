/* LBPMATCH module=EBOOT.BIN start=0x088cd494 end=0x088cd5d4 symbol=FUN_088cd494 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern void *DAT_08beee0c;
extern void FUN_08b9eb88(void *, int, unsigned), FUN_088e666c(void *, int, void *);
extern int FUN_08895bd8(void *,void *);
unsigned FUN_088cd494(char *self, void *obj, unsigned limit) {
 unsigned count=0; short i=0;
 while (count<limit) {
  int n=i++;
  char buf[20]; struct { char data[20]; char flag; } msg;
  if (n >= (unsigned char)self[61]) break;
  FUN_08b9eb88(buf,0,20);
  __builtin_memcpy(buf,self+1080+n*16,16);
  if (!FUN_08895bd8(obj,buf)) {
   ++count; __builtin_memcpy(msg.data,buf,20); msg.flag=1;
   FUN_088e666c(DAT_08beee0c,12,&msg);
  }
 }
 return count;
}

// Both O2 and Os differ; loop and stack layouts remain unresolved.
// near miss from lane lbp13c (unreviewed)
