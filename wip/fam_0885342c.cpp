/* LBPMATCH module=EBOOT.BIN start=0x0885342c end=0x0885370c symbol=FUN_0885342c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
extern "C" { extern char DAT_08bef8f4[]; extern char *DAT_08be84ac; void FUN_08ad3088(void *); void FUN_08ad2810(void *); void FUN_08adbc24(void *,void *,unsigned int); }
struct Ref { void **vtable; int count; };
struct Node { int unused[2]; Node *left,*right; int value; Ref *ref; };
struct Tree { void erase(Node *n) { while(n) { erase(n->right); Node *next=n->left; Ref *r=n->ref; if(r) { FUN_08ad3088(DAT_08bef8f4); int c=--r->count; FUN_08ad2810(DAT_08bef8f4); if (!c) ((void (*)(Ref *))r->vtable[2])(r); } char *heap=DAT_08be84ac; FUN_08ad3088(heap+32); FUN_08adbc24(heap,n,32); FUN_08ad2810(heap+32); n=next; } } };
extern "C" void FUN_0885342c(Tree *t,Node *n) { t->erase(n); }
// Recursive inlining depth, allocator and reference ownership need comparison with retail.
// near miss from lane lbp1a (unreviewed)
