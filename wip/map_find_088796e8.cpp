/* LBPMATCH module=EBOOT.BIN start=0x088796e8 end=0x0887977c symbol=FUN_088796e8 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { char key[1]; };
struct Iter { NodeBase *n; };
struct Tree {
    int compare; NodeBase header; unsigned count;
    Iter end() { Iter i = { &header }; return i; }
    Iter lower_bound(const char *k);
    Iter find(const char *k);
};
extern "C" int FUN_08ba0d98(const char *, const char *);
inline Iter Tree::lower_bound(const char *k)
{
    NodeBase *y = &header;
    NodeBase *x = header.parent;
    while (x != 0) {
        if (!(FUN_08ba0d98(static_cast<Node *>(x)->key, k) < 0)) { y = x; x = x->left; }
        else x = x->right;
    }
    Iter r = { y };
    return r;
}
inline Iter Tree::find(const char *k)
{
    Iter j = lower_bound(k);
    return (j.n == end().n || FUN_08ba0d98(k, static_cast<Node *>(j.n)->key) < 0) ? end() : j;
}
extern "C" NodeBase *FUN_088796e8(Tree *t, const char *k)
{
    return t->find(k).n;
}
// NEAR 20 words: structure matches; register roles differ (retail s1=end, s2=y, s0=result copy with beq/bgez branches; ours s2=end, s1=y, result in a1).
// Tried: hand loop, inline lower() helper, iterator struct, find() member, local end first, O2/402x/410/171 profiles.
// near miss from lane lbp9c (unreviewed)
