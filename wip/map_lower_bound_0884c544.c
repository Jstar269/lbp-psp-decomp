/* LBPMATCH module=EBOOT.BIN start=0x0884c544 end=0x0884c5e0 symbol=FUN_0884c544 lang=c99 */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
typedef struct Name { int f0; int f4; int f8; char text[20]; } Name;
typedef struct Key { int f0; Name *name; int n; } Key;
typedef struct Node { int color; struct Node *parent; struct Node *left; struct Node *right; Key key; } Node;
typedef struct Tree { int f0; Node header; } Tree;
extern int FUN_08b9e714(const char *, const char *, int);
static inline int key_less(const Key *a, const Key *b)
{
    if (a->n != 0 || b->n != 0)
        return a->n - b->n < 0;
    return FUN_08b9e714(a->name->text, b->name->text, 20) < 0;
}
Node *FUN_0884c544(Tree *t, const Key *key)
{
    Node *result = &t->header;
    Node *x = t->header.parent;
    while (x) {
        if (key_less(&x->key, key)) {
            x = x->right;
        } else {
            result = x;
            x = x->left;
        }
    }
    return result;
}
// NEAR ~3 words structural: retail has the memcmp-call block outlined after the loop exit (jump over it to epilogue) but loop entered by j to a bottom test (Os style); Os inlines the call, O2 copies the loop header. Tried key_less forms, for(;;), O2.
// near miss from lane lbp8b (unreviewed)
