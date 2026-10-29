/* LBPMATCH module=EBOOT.BIN start=0x0885ad64 end=0x0885b068 symbol=FUN_0885ad64 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct O { void (**vt)(struct O *); int refs, x; char data[20]; } O;
typedef struct S { char pad[204]; unsigned count; char pad2[8]; char *items; int x; unsigned limit; } S;
extern char DAT_08bbf4f4[], DAT_08bbf500[], DAT_08bef8f4;
extern int DAT_08be8420, DAT_08be8424, DAT_08be8428; extern O **DAT_08be841c;
extern void *FUN_08844188(void *,void *), *FUN_0884364c(void *), *FUN_08843570(void *), *FUN_088436b0(void *), *FUN_08adb810(int,int,int,int);
extern int FUN_08ba0d98(void *,void *), FUN_08b9e714(void *,void *,int);
extern void FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08855434(O *), FUN_0888c1b4(void *,O **);
void FUN_0885ad64(S *s, void *arg) {
 void *node=FUN_0884364c(FUN_08844188(arg,DAT_08bbf4f4));
 while(node) { if(!FUN_08ba0d98(*(char **)((char *)node+32)+8,DAT_08bbf500)) {
 O *p; char tmp[20], *found=0; unsigned i;
 FUN_08ad3088(&DAT_08bef8f4); FUN_08ad3088(&DAT_08bef8f4);
 if (DAT_08be8424 < DAT_08be8420) p=DAT_08be841c[DAT_08be8424++]; else { DAT_08be8428++; p=FUN_08adb810(32,16,0,0); }
 if(p) FUN_08855434(p); FUN_08ad2810(&DAT_08bef8f4); FUN_08ad2810(&DAT_08bef8f4);
 FUN_0888c1b4(FUN_08843570(node),&p);
 for(i=s->count;i<s->limit;i++) if(!FUN_08b9e714(p->data,s->items+i*20,20)) { found=s->items+i*20; break; }
 __builtin_memcpy(tmp,s->items+s->count*20,20); __builtin_memcpy(s->items+s->count*20,found,20); __builtin_memcpy(found,tmp,20); s->count++;
 if(p) { int n; FUN_08ad3088(&DAT_08bef8f4); n=--p->refs; FUN_08ad2810(&DAT_08bef8f4); if(!n) p->vt[2](p); }
 } node=FUN_088436b0(node); }
}
// 188 words differ; object pool declarations and control flow need reconstruction; unaligned swap included.
// near miss from lane lbp15d (unreviewed)
