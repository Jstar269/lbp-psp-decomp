/* LBPMATCH module=EBOOT.BIN start=0x0880c280 end=0x0880c2dc symbol=_ZN12Map_0880c2804findERKj lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::find (GCC 4.0) for unsigned keys, written as the member function (the free-function form allocates registers differently): lower-bound walk, then end() unless the key matches (retail if-converts the end test into movz). */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; };
struct Iter { NodeBase *node; Iter(NodeBase *n) : node(n) {} bool operator==(const Iter &o) const { return node == o.node; } };
struct Less { bool operator()(const unsigned &a, const unsigned &b) const { return a < b; } };
struct Map_0880c280 {
    Less comp; NodeBase header; unsigned count;
    Node *begin_() { return static_cast<Node *>(header.parent); }
    Node *end_() { return static_cast<Node *>(&header); }
    static const unsigned &key(const NodeBase *x) { return static_cast<const Node *>(x)->key; }
    static Node *left(NodeBase *x) { return static_cast<Node *>(x->left); }
    static Node *right(NodeBase *x) { return static_cast<Node *>(x->right); }
    Iter end() { return Iter(end_()); }
    Iter find(const unsigned &k);
};
Iter Map_0880c280::find(const unsigned &k)
{
    Node *x = begin_();
    Node *y = end_();
    while (x != 0)
        if (!comp(key(x), k))
            y = x, x = left(x);
        else
            x = right(x);
    Iter j = Iter(y);
    if (j == end()) return end();
    if (comp(k, key(j.node))) return end();
    return j;
}
// NEAR: 2 words+shape: retail keeps beqz branch ending (no if-conversion) where ours emits movn a2,a0,v0; tried ternary, if/return variants, cached end, Iter copies, Os/O2/gcc402x/410/171.
// near miss from lane lbp11d (unreviewed)
