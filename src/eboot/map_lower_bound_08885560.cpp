/* LBPMATCH module=EBOOT.BIN start=0x08885560 end=0x088855b8 symbol=FUN_08885560 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. std::pair<int,unsigned> keyed lower_bound. */
struct Key { int first; unsigned second; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Key key; };
struct Tree { int compare; NodeBase header; unsigned count; };
inline bool less(const Key &a, const Key &b) { return a.first < b.first || (a.first == b.first && a.second < b.second); }
extern "C" NodeBase *FUN_08885560(Tree *t, const Key &k)
{
    NodeBase *x = t->header.parent;
    NodeBase *y = &t->header;
    while (x != 0)
        if (!less(static_cast<Node *>(x)->key, k))
            y = x, x = x->left;
        else
            x = x->right;
    return y;
}
