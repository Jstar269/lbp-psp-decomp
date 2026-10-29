/* LBPMATCH module=EBOOT.BIN start=0x0887a47c end=0x0887a564 symbol=_Z12FUN_0887a47cP4TreeRK4Name lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. A std::map/std::set insert_unique instance (libstdc++ 4.0 _Rb_tree::insert_unique) keyed by a C string ordered with strcmp (FUN_08ba0d98): FUN_08b898a8 is _Rb_tree_decrement, FUN_0887a378 the instance's _M_insert. */
struct Name { char s[1]; };
struct Node { int color; Node *parent; Node *left; Node *right; Name key; };
struct Tree { int compare; Node header; unsigned count; };
struct Pair { Node *first; bool second; Pair(Node *a, bool b) : first(a), second(b) {} };
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_0887a378(Tree *t, Node *x, Node *y, const Name &v);
extern "C" int FUN_08ba0d98(const char *a, const char *b);
inline bool less(const Name &p, const Name &q) { return FUN_08ba0d98(p.s, q.s) < 0; }
Pair FUN_0887a47c(Tree *t, const Name &v)
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
            return Pair(FUN_0887a378(t, x, y, v), true);
        else
            j = FUN_08b898a8(j);
    }
    if (less(j->key, v))
        return Pair(FUN_0887a378(t, x, y, v), true);
    return Pair(j, false);
}
