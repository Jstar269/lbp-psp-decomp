/* LBPMATCH module=EBOOT.BIN start=0x08870058 end=0x08870308 symbol=FUN_08870058 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
struct Node { int a,b; Node *next,*child; }; struct Alloc { char pad[32]; char lock[4]; }; extern Alloc *DAT_08be84ac;
extern "C" void FUN_08ad3088(void *), FUN_08ad2810(void *), FUN_08adbc24(Alloc *, void *, int);
extern "C" inline __attribute__((used)) void FUN_08870058(void *self, Node *n) { while(n) { FUN_08870058(self,n->child); Node *next=n->next; Alloc *a=DAT_08be84ac; FUN_08ad3088(a->lock); FUN_08adbc24(a,n,24); FUN_08ad2810(a->lock); n=next; } }
// Recursive inline form emits fewer levels than retail (161 differing words); inspect inlining and allocator wrapper.
// near miss from lane lbp1a (unreviewed)
