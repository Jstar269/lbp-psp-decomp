/* LBPMATCH module=EBOOT.BIN start=0x08891b40 end=0x08891b94 symbol=FUN_08891b40 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp13b, Codex GPT-6); names and types await human review. */
typedef struct Node { int color; struct Node *parent,*left,*right; int key; } Node;
typedef struct { int unused; Node head; } Tree;
Node *FUN_08891b40(Tree *t, int *key) { Node *x=t->head.parent, *y=&t->head; while (x) { if (x->key < *key) x=x->right; else { y=x; x=x->left; } } if (y != &t->head && !(*key < y->key)) return y; return &t->head; }

// Tree lower-bound layout differs; structured C and O2 tried.
// near miss from lane lbp13b (unreviewed)
