/* LBPMATCH module=EBOOT.BIN start=0x0887b3d8 end=0x0887b660 symbol=FUN_0887b3d8 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct Ref { void (**v)(struct Ref *); int refs; } Ref;
extern char DAT_08bef8f4, DAT_08bb07a8;
extern void FUN_0888f6c8(void *), FUN_0888f6d0(void *), FUN_0887a024(void *,void *,void *,int), FUN_0887a0fc(void *), FUN_0887a220(void *,Ref **), FUN_0887b02c(void *,void *,void *,int,int,int), FUN_08ad3088(void *), FUN_08ad2810(void *);
extern void *FUN_08a9e838(int); extern int FUN_0886c86c(void *,void *), FUN_08b9e714(void *,void *,int);
static inline void retain(Ref *p) { if(p) { FUN_08ad3088(&DAT_08bef8f4); ++p->refs; FUN_08ad2810(&DAT_08bef8f4); } }
static inline void release(Ref *p,int slot) { if(p) { int n; FUN_08ad3088(&DAT_08bef8f4); n=--p->refs; FUN_08ad2810(&DAT_08bef8f4); if(!n) p->v[slot](p); } }
void **FUN_0887b3d8(void **self, char *ctx, const char *src, void **arg) {
 char data[20]; Ref *p,*old; void **obj;
 FUN_0888f6c8(ctx+44); __builtin_memcpy(data,src,20); FUN_0887a024(self,ctx,data,1);
 if(!*self) { p=FUN_08a9e838(180); FUN_0887a0fc(p); FUN_0887a220(self,&p); release(p,1); FUN_0887b02c(ctx,data,self,0,0,2); }
 FUN_0888f6d0(ctx+44); obj=*self;
 if(obj && !FUN_0886c86c(arg,obj+8)) { obj[8]=arg[0]; p=arg[1]; retain(p); old=obj[9]; obj[9]=p; release(old,2); obj[10]=arg[2]; obj=*self; obj[11]=(void *)(arg[2] || (arg[1] && FUN_08b9e714((char *)arg[1]+12,&DAT_08bb07a8,20))); obj=*self; old=obj[7]; obj[7]=0; release(old,1); }
 return self;
}
// 147 words differ; stack frame and register allocation differ despite matching initial instruction sequence.
// near miss from lane lbp15d (unreviewed)
