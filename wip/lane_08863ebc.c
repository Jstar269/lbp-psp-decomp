/* LBPMATCH module=EBOOT.BIN start=0x08863ebc end=0x088640ec symbol=FUN_08863ebc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp15d, Codex GPT-6); names and types await human review. */
typedef struct Ref { void (**vtable)(struct Ref *); int refs; } Ref;
typedef struct { char pad[200]; unsigned index, count; char *entries; } State;
extern char DAT_08bef8f4, *DAT_08bedd84, *DAT_08bedd88;
extern void FUN_08b9eb88(void *, int, unsigned);
extern const char *FUN_088876ac(void);
extern int FUN_08baa704(void *), FUN_08baa724(int, void *, void *, int, int, int, int), FUN_08baa734(int);
extern void FUN_08863de8(Ref **), FUN_08887c4c(void *, int *), FUN_088953fc(Ref **, void *, void *, Ref **, int, int);
extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
static inline void release(Ref *p) { if (p) { int n; FUN_08ad3088(&DAT_08bef8f4); n = --p->refs; FUN_08ad2810(&DAT_08bef8f4); if (!n) p->vtable[2](p); } }
int FUN_08863ebc(State *s) {
 char name[12]; const char *src; int id; Ref *r, *out; int err[2]; int ok;
 FUN_08b9eb88(name,0,12); src=FUN_088876ac(); __builtin_memcpy(name,src,8); name[8]=src[8];
 while (s->index < s->count) {
  id=FUN_08baa704(name); if(id<0) return 0;
  FUN_08863de8(&r);
  int result=FUN_08baa724(id,s->entries+s->index*36,(char *)r+12,0,0,0,0);
  if(result<0) { err[0]=result==(int)0x80550705 ? 2:3; err[1]=result==(int)0x80550705 ? 403:result; FUN_08887c4c(DAT_08bedd84,err); ok=0; }
  else { FUN_088953fc(&out,DAT_08bedd88,s->entries+s->index*36,&r,1,0); release(out); ++s->index; FUN_08baa734(id); ok=1; }
  release(r); if (!ok) break;
 }
 return 1;
}
// 140 words differ: stack layout, unaligned destination copy, and two distinct error objects remain unresolved.
// near miss from lane lbp15d (unreviewed)
