/* LBPMATCH module=EBOOT.BIN start=0x08885dbc end=0x08885ee0 symbol=_Z12FUN_08885dbcP4TreeRK3Key lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. A std::map/std::set insert_unique instance (libstdc++ 4.0 _Rb_tree::insert_unique) with a two-field key ordered by a signed then an unsigned field: FUN_08b898a8 is _Rb_tree_decrement, FUN_08885cb0 the instance's _M_insert. */
struct Key { int a; unsigned b; };
struct Node { int color; Node *parent; Node *left; Node *right; Key key; };
struct Tree { int compare; Node header; unsigned count; };
struct Pair { Node *first; bool second; Pair(Node *a, bool b) : first(a), second(b) {} };
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_08885cb0(Tree *t, Node *x, Node *y, const Key &v);
inline bool less(const Key &p, const Key &q) { return p.a < q.a || (p.a == q.a && p.b < q.b); }
Pair FUN_08885dbc(Tree *t, const Key &v)
{
    Node *x = t->header.parent;
    Node *y = &t->header;
    bool comp = true;
    while (x != 0) {
        y = x;
        comp = less(v, x->key);
        x = comp ? x->left : x->right;
    }
    Node *j = y;
    if (comp) {
        if (j == t->header.left)
            return Pair(FUN_08885cb0(t, x, y, v), true);
        else
            j = FUN_08b898a8(j);
    }
    if (less(j->key, v))
        return Pair(FUN_08885cb0(t, x, y, v), true);
    return Pair(j, false);
}
// NEAR (~56 words): second half (predecessor test, _M_insert call, Pair return) matches; the descent loop differs: retail keeps comp in v1 (copied from the compare result a3 at the end of each iteration, li a3,1 in the back-edge delay slot) and loads the node key before the search key; ours uses a3 alone. Tried: && / || / !(q<p) forms, local bool, if/else, expanded compare.
// near miss from lane lbp8a (unreviewed)
