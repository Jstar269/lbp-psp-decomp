/* LBPMATCH module=EBOOT.BIN start=0x08897e14 end=0x08897eb0 symbol=FUN_08897e14 lang=c++ */
/* Clone of src/eboot/map_find_088854c4.cpp (lbpclone.py tag c19): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. map find on (int,unsigned) keys: lower_bound then end check; matching idiom: end kept as a separate local pointer from y. */
struct Key { int first; unsigned second; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Key key; };
struct Tree { int compare; NodeBase header; unsigned count; };
inline bool less(const Key &a, const Key &b) { return a.first < b.first || (a.first == b.first && a.second < b.second); }
extern "C" NodeBase *FUN_08897e14(Tree *t, const Key &k)
{
    NodeBase *x = t->header.parent;
    NodeBase *e = &t->header;
    NodeBase *y = &t->header;
    while (x != 0)
        if (!less(static_cast<Node *>(x)->key, k))
            y = x, x = x->left;
        else
            x = x->right;
    if (y == e || less(k, static_cast<Node *>(y)->key)) y = e;
    return y;
}
