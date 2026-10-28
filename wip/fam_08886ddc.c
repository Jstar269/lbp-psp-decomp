/* LBPMATCH module=EBOOT.BIN start=0x08886ddc end=0x088871c4 symbol=FUN_08886ddc lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef unsigned int u32;
typedef struct Ref { void **vtable; int count; } Ref;
typedef struct Node { char pad[24]; u32 value; char flag; char pad2[3]; u32 active; Ref *ref; } Node;
typedef struct Obj { char pad[4]; void (*callback)(Ref **,void *); void *arg; void *queue; char tree[20]; u32 count, limit; } Obj;
extern char DAT_08bef8f4[];
extern void FUN_08ad3088(void *), FUN_08ad2810(void *);
extern Node *FUN_08885394(void *,void *), *FUN_08886138(void *,void *);
extern void FUN_088858f4(void *,void *);
static void assign(Ref **dst, Ref *src) {
 Ref *old;
 if (src) { FUN_08ad3088(DAT_08bef8f4); ++src->count; FUN_08ad2810(DAT_08bef8f4); }
 old=*dst; *dst=src;
 if (old) { int n; FUN_08ad3088(DAT_08bef8f4); n=--old->count; FUN_08ad2810(DAT_08bef8f4); if (!n) ((void (*)(Ref *))old->vtable[2])(old); }
}
int FUN_08886ddc(Obj *o, void *key, Ref **ref, unsigned char replace, u32 value, u32 flags) {
 Node *n=FUN_08885394(o->tree,key);
 if (n != (Node *)(o->tree+4)) {
  if (!replace) return 0;
 } else {
  n=FUN_08886138(o->tree,key);
 }
 assign(&n->ref,*ref); n->value=value; n->active=(flags&1)?0:1;
 if (flags&4) n->flag=1;
 if (o->queue) FUN_088858f4(o->queue,key);
 return 1;
}
// Incomplete: eviction and insertion queue path remain to reconstruct; separate inserted node layout is unresolved.
// near miss from lane lbp1a (unreviewed)
