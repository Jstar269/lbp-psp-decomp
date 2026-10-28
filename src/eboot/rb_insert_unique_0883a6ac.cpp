/* LBPMATCH module=EBOOT.BIN start=0x0883a6ac end=0x0883a794 symbol=_Z12FUN_0883a6acP4TreeRKj lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/rb_insert_unique_088054dc.cpp (lbpclone.py tag c10): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. A std::map/std::set<unsigned> insert_unique instance (libstdc++ 4.0 _Rb_tree::insert_unique, written out with plain structs): FUN_08b898a8 is _Rb_tree_decrement, FUN_08839d28 the instance's _M_insert. */
struct Node { int color; Node *parent; Node *left; Node *right; unsigned key; };
struct Tree { int compare; Node header; unsigned count; };
struct Pair { Node *first; bool second; Pair(Node *a, bool b) : first(a), second(b) {} };
extern "C" Node *FUN_08b898a8(Node *n);
extern "C" Node *FUN_08839d28(Tree *t, Node *x, Node *y, const unsigned &v);
Pair FUN_0883a6ac(Tree *t, const unsigned &v)
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
            return Pair(FUN_08839d28(t, x, y, v), true);
        else
            j = FUN_08b898a8(j);
    }
    if (j->key < v)
        return Pair(FUN_08839d28(t, x, y, v), true);
    return Pair(j, false);
}
