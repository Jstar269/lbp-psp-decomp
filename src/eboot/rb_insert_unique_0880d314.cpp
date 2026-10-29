/* LBPMATCH module=EBOOT.BIN start=0x0880d314 end=0x0880d3fc symbol=_Z12FUN_0880d314P4TreeRKs lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { int color; Node *parent; Node *left; Node *right; short key; };
struct Tree { int compare; Node header; unsigned count; };
struct Pair { Node *first; bool second; Pair(Node *a, bool b) : first(a), second(b) {} };
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_0880d250(Tree *t, Node *x, Node *y, const short &v);
Pair FUN_0880d314(Tree *t, const short &v)
{
    Node *x = t->header.parent;
    Node *y = &t->header;
    bool comp = true;
    while (x != 0) {
        y = x;
        comp = v < x->key;
        x = comp ? x->left : x->right;
    }
    Node *j = y;
    if (comp) {
        if (j == t->header.left)
            return Pair(FUN_0880d250(t, x, y, v), true);
        else
            j = FUN_08b898a8(j);
    }
    if (j->key < v)
        return Pair(FUN_0880d250(t, x, y, v), true);
    return Pair(j, false);
}
