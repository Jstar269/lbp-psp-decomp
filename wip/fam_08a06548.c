/* LBPMATCH module=EBOOT.BIN start=0x08a06548 end=0x08a066cc symbol=FUN_08a06548 lang=c99 cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef struct { int *start,*end,*limit; } Vec; extern char DAT_08bb1740[]; extern void FUN_08b886b0(char*) __attribute__((noreturn)), FUN_08b8829c(void) __attribute__((noreturn)), FUN_08a9e0cc(void*), FUN_08b9e8cc(void*,void*,unsigned); extern int *FUN_08a9e838(unsigned);
void FUN_08a06548(Vec *v,int *pos,int *value) { int *end=v->end; if(end!=v->limit) { if(end) *end=end[-1]; unsigned n=(char*)(end-1)-(char*)pos; int x=*value; v->end=end+1; n &= ~3u; FUN_08b9e8cc((char*)end-n,pos,n); *pos=x; } else { unsigned size=end-v->start; if(size==0x3fffffff) FUN_08b886b0(DAT_08bb1740); unsigned count=size ? size*2 : 1; if(count<size) count=0x3fffffff; if(count>0x3fffffff) FUN_08b8829c(); int *base=FUN_08a9e838(count*4); unsigned before=(char*)pos-(char*)v->start; int *place=(int*)((char*)base+before); FUN_08b9e8cc(base,v->start,before); if(place) *place=*value; int after=(char*)v->end-(char*)pos; ++place; FUN_08b9e8cc(place,pos,after); int *newend=(int*)((char*)place+after); if(v->start) FUN_08a9e0cc(v->start); v->limit=base+count; v->end=newend; v->start=base; } }
// Vector insertion: 65 words differ; growth branch and register allocation need further work.



// Vector insertion with noreturn and O2: 93 words differ; Os has 95.
// near miss from lane lbp1a (unreviewed)
