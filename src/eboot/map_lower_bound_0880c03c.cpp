/* LBPMATCH module=EBOOT.BIN start=0x0880c03c end=0x0880c074 symbol=FUN_0880c03c lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/map_lower_bound_08805014.cpp (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::lower_bound (GCC 4.0) for unsigned keys. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; };
struct Tree { int compare; NodeBase header; unsigned count; };
inline bool less(const unsigned &a, const unsigned &b) { return a < b; }
inline const unsigned &key(const NodeBase *x) { return static_cast<const Node *>(x)->key; }
extern "C" NodeBase *FUN_0880c03c(Tree *t, const unsigned &k)
{
    NodeBase *x = t->header.parent;
    NodeBase *y = &t->header;
    while (x != 0)
        if (!less(key(x), k))
            y = x, x = x->left;
        else
            x = x->right;
    return y;
}
