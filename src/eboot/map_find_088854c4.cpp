/* LBPMATCH module=EBOOT.BIN start=0x088854c4 end=0x08885560 symbol=FUN_088854c4 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. map find on (int,unsigned) keys: lower_bound then end check; matching idiom: end kept as a separate local pointer from y. */
struct Key { int first; unsigned second; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Key key; };
struct Tree { int compare; NodeBase header; unsigned count; };
inline bool less(const Key &a, const Key &b) { return a.first < b.first || (a.first == b.first && a.second < b.second); }
extern "C" NodeBase *FUN_088854c4(Tree *t, const Key &k)
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
