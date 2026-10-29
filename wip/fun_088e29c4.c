/* LBPMATCH module=EBOOT.BIN start=0x088e29c4 end=0x088e2af8 symbol=FUN_088e29c4 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13c, Codex GPT-6); names and types await human review. */
extern char *DAT_08beed14; extern void *DAT_08beee0c; extern int DAT_08bb4410;
extern int FUN_08ba0d98(void *,void *); extern void FUN_08b9eb88(void *,int,int), FUN_088f3b0c(void *,void *);
void FUN_088e29c4(char *self, char *src, char *page) {
 char *fallback=*(char **)(DAT_08beed14+452); int start, last, i; char buf[20];
 if (!FUN_08ba0d98(src,fallback)) src=fallback;
 start=(*(int *)(page+8)-1)*DAT_08bb4410; page[5]=1; *(int *)(page+12)=DAT_08bb4410;
 last=(unsigned char)src[61]; if ((unsigned)(start+DAT_08bb4410)<(unsigned)last) last=start+DAT_08bb4410; --last;
 for(i=start;i<=last;i++) { FUN_08b9eb88(buf,0,20); __builtin_memcpy(buf,src+1080+i*16,16); FUN_088f3b0c(DAT_08beee0c,buf); }
 if(last<start) self[85]=1;
}
// Loop register allocation and layout need work.
// near miss from lane lbp13c (unreviewed)
