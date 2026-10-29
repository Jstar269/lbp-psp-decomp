/* LBPMATCH module=EBOOT.BIN start=0x088784ac end=0x088786e4 symbol=FUN_088784ac lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct Ref { void (**v)(struct Ref *); int refs; char pad[12]; char *data; } Ref;
extern char DAT_08bef8f4, DAT_08bb0758;
extern void FUN_0886e018(void *,int), FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08855b64(Ref **), FUN_08af767c(void *), FUN_08af72b0(void *,void *,int), FUN_08af7480(void *,void *);
static inline void retain(Ref *p) { if(p) { FUN_08ad3088(&DAT_08bef8f4); ++p->refs; FUN_08ad2810(&DAT_08bef8f4); } }
static inline void release(Ref *p,int slot) { if(p) { int n; FUN_08ad3088(&DAT_08bef8f4); n=--p->refs; FUN_08ad2810(&DAT_08bef8f4); if(!n) p->v[slot](p); } }
void FUN_088784ac(void **self, Ref **arg, unsigned value) {
 Ref *p,*old,*out; char data[24], state[96];
 FUN_0886e018(self,4); self[13]=0; self[14]=0; p=*arg; self[0]=&DAT_08bb0758; self[12]=0; self[15]=0; self[16]=0; self[17]=0; self[18]=0; self[19]=(void *)value;
 retain(p); old=self[13]; self[13]=p; release(old,1);
 FUN_08855b64(&out); __builtin_memcpy(data,((Ref *)self[13])->data+12,20); *(unsigned *)(data+20)=value;
 FUN_08af767c(state); FUN_08af72b0(state,data,24); FUN_08af7480(state,(char *)out+12);
 retain(out); old=self[5]; self[5]=out; release(old,2); release(out,2);
}
// 94 words differ; unaligned local block and stack/register allocation remain unresolved.
// near miss from lane lbp15d (unreviewed)
