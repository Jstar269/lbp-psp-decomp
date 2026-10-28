/* LBPMATCH module=EBOOT.BIN start=0x089edd0c end=0x089ede34 symbol=FUN_089edd0c lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp1a, Codex GPT-6); names and types await human review. */
typedef struct Node { int color; struct Node *parent,*left,*right; unsigned key; } Node; typedef struct Tree { int x; Node *root,*first,*last; } Tree; extern Node *FUN_08b898a8(Node *), *FUN_089edc38(Tree*,Node*,Node*,unsigned*);
unsigned long long FUN_089edd0c(Tree *tree,unsigned *key) { Node *n=tree->root,*candidate=(Node*)((char*)tree+4),*found; while(n) { candidate=n; if(*key<n->key) n=n->left; else n=n->right; } found=candidate; if(candidate!=(Node*)((char*)tree+4) && candidate->key<=*key) { if(candidate->key==*key) return (unsigned)candidate; } else if(candidate!=tree->first) { found=FUN_08b898a8(candidate); if(*key<=found->key) return (unsigned)found; } found=FUN_089edc38(tree,0,candidate,key); return ((unsigned long long)1<<32)|(unsigned)found; }
// Return pair ABI and tree-search control flow differ; 74 words differ.
// near miss from lane lbp1a (unreviewed)
