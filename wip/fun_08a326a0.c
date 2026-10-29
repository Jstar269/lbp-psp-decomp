/* LBPMATCH module=EBOOT.BIN start=0x08a326a0 end=0x08a3286c symbol=FUN_08a326a0 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern void FUN_08a34774(void *,void *,int), FUN_08a56ec8(void *,void *,void *), FUN_08954e6c(void *,void *,int,int), FUN_0895541c(void *); extern int FUN_08954cc4(void *);
typedef struct Stream { char pad[4]; char *cur; char pad2[12]; int size; char pad3[24]; void *flag; } Stream;
static inline void put(Stream *s,int value) { if(!FUN_08954cc4(s->flag)) __builtin_memcpy(s->cur,&value,4); s->cur+=4; s->size+=4; }
void FUN_08a326a0(char *self, Stream **stream) { float f; int v; Stream *s;
 FUN_08a34774(self,stream,0x4f445541); FUN_08a56ec8(self+188,stream,self);
 s=*stream; f=*(float *)(self+616); __builtin_memcpy(&v,&f,4); put(s,v);
 s=*stream; put(s,*(unsigned short *)(self+620)); s=*stream; put(s,*(int *)(self+624)); s=*stream; put(s,*(int *)(self+628)); s=*stream; put(s,0);
 FUN_08954e6c(*stream,self+632,1,80); FUN_0895541c(stream);
}
// 102 words differ; stream inline ordering and float temporary differ.
// near miss from lane lbp13d (unreviewed)
