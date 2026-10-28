/* LBPMATCH module=EBOOT.BIN start=0x08850498 end=0x088505e0 symbol=FUN_08850498 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
struct Key { int unused; char *ptr; unsigned int tag; };
struct Node { int unused[2]; Node *left,*right; Key key; };
struct Tree { int unused; Node *header,*root,*first; };
struct Result { Node *node; bool inserted; };
extern "C" int FUN_08b9e714(const void *,const void *,unsigned int);
extern "C" Node *FUN_08b898a8(Node *);
extern "C" Node *FUN_08850374(Tree *,Node *,Node *,Key *);
static int cmp(Key *a,Key *b) { if (!a->tag && !b->tag) return FUN_08b9e714(a->ptr+12,b->ptr+12,20); return a->tag-b->tag; }
extern "C" Result FUN_08850498(Tree *t,Key *k) {
 Node *x=t->root, *y=(Node *)&t->header; bool left=true;
 while(x) { left=cmp(k,&x->key)<0; y=x; x=left?x->left:x->right; }
 Node *p=y;
 if(left) { if(y==t->first) { Result r={FUN_08850374(t,0,y,k),true}; return r; } p=FUN_08b898a8(y); }
 if(cmp(&p->key,k)<0) { Result r={FUN_08850374(t,0,y,k),true}; return r; }
 Result r={p,false}; return r;
}
// Return pair and tree insertion control flow reconstructed; compiler layout and return ABI remain to investigate.
// near miss from lane lbp1a (unreviewed)
