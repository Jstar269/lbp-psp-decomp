/* LBPMATCH module=EBOOT.BIN start=0x0887a718 end=0x0887a8c8 symbol=FUN_0887a718 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp13d, Codex GPT-6); names and types await human review. */
extern "C" { void *FUN_08879808(void *,const char *); int FUN_08ba0d98(const char *,const char *); void FUN_0887a220(void *,void *); void FUN_0887a1a0(void *,void *); void *FUN_0887a564(void *,void *,void *); void FUN_08ad3088(void *); void FUN_08ad2810(void *); extern char DAT_08bef8f4; }
struct Ref { void **v; int count; };
static inline void release(Ref *p) { if(p) { FUN_08ad3088(&DAT_08bef8f4); int n=--p->count; FUN_08ad2810(&DAT_08bef8f4); if(!n) ((void (*)(Ref *))p->v[1])(p); } }
extern "C" void *FUN_0887a718(char *self,const char *key) {
 char *it=(char *)FUN_08879808(self,key);
 if(it != self+4 && FUN_08ba0d98(key,it+16)>=0) return it+36;
 Ref *a=0,*b=0; FUN_0887a220(&a,&b); release(b);
 struct Temp { char key[20]; char rest[12]; Ref *ref; } temp;
 __builtin_memcpy(temp.key,key,20);
 struct Other { int x; char y; int z; } other; other.x=0; other.y=0; other.z=0;
 FUN_0887a1a0(temp.rest,&other); it=(char *)FUN_0887a564(self,it,&temp);
 release(temp.ref); release(a); return it+36;
}
// 74 words differ; stack layout and reference lifetime need refinement.
// near miss from lane lbp13d (unreviewed)
