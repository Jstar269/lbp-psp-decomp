/* LBPMATCH module=EBOOT.BIN start=0x088eaf2c end=0x088eb018 symbol=FUN_088eaf2c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); exact match verified; names and types await human review. */
typedef struct Ref { void **vtable; int count; } Ref;
typedef struct Node { int pad[2]; struct Node *left,*right; int value; Ref *ref; } Node;
typedef struct Tree { int pad; Node *header,*root,*first,*last; int count; } Tree;
extern char DAT_08bef8f4[]; extern char *DAT_08be84ac;
extern void FUN_08ad3088(void *),FUN_08ad2810(void *),FUN_08adbc24(void *,void *,unsigned int),FUN_088eaa24(Tree *,Node *);
void FUN_088eaf2c(Tree *t) { Node *n=t->root; while(n) { Ref *r; Node *next; char *heap; FUN_088eaa24(t,n->right); r=n->ref; next=n->left; if(r) { int c; FUN_08ad3088(DAT_08bef8f4); c=--r->count; FUN_08ad2810(DAT_08bef8f4); if(!c) ((void (*)(Ref *))r->vtable[2])(r); } heap=DAT_08be84ac; FUN_08ad3088(heap+32); FUN_08adbc24(heap,n,24); FUN_08ad2810(heap+32); n=next; } t->first=(Node *)&t->header; t->root=0; t->last=(Node *)&t->header; t->count=0; }


