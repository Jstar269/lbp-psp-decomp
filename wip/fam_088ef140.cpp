/* LBPMATCH module=EBOOT.BIN start=0x088ef140 end=0x088ef420 symbol=FUN_088ef140 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
struct Ref { virtual void a(); virtual void b(); virtual void destroy(); int count; };
struct Node { int a,b; Node *next,*child; int c; Ref *ref; };
struct Alloc { char pad[32]; char lock[4]; };
extern Alloc *DAT_08be84ac; extern char DAT_08bef8f4[];
extern "C" void FUN_08ad3088(void *); extern "C" void FUN_08ad2810(void *); extern "C" void FUN_08adbc24(Alloc *,void *,int);
inline void release(Ref *r) { if (r) { FUN_08ad3088(DAT_08bef8f4); int n = --r->count; FUN_08ad2810(DAT_08bef8f4); if (!n) r->destroy(); } }
inline void erase(void *self, Node *n) { while(n) { erase(self,n->child); Node *next=n->next; release(n->ref); Alloc *a=DAT_08be84ac; FUN_08ad3088(a->lock); FUN_08adbc24(a,n,24); FUN_08ad2810(a->lock); n=next; } }

extern "C" void FUN_088ef140(void *self, Node *n) { erase(self,n); }

// Recursive helper compiled separately; retail inlines five levels. Further work should model a recursive member.
// near miss from lane lbp1a (unreviewed)
