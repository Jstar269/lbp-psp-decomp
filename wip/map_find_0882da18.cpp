/* LBPMATCH module=EBOOT.BIN start=0x0882da18 end=0x0882dab8 symbol=FUN_0882da18 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. map find on (int,unsigned) keys: lower_bound then end check; matching idiom: end kept as a separate local pointer from y. */
struct Key { int first; int second; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Key key; };
struct Tree { int compare; NodeBase header; unsigned count; };
inline bool less(const Key &a, const Key &b) { return a.first < b.first || (!(b.first < a.first) && a.second < b.second); }
extern "C" NodeBase *FUN_0882da18(Tree *t, const Key &k)
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
// NEAR ~30 words (41 vs 40 words): retail loads the next node straight into x's register (`lw a2,12(a2)`; left arm out of line: `j test; lw a2,8(a2)`),
// result register is a2 (`move a2,t1` / `move a2,a0`, `move v0,a2` in jr delay slot); ours goes through v0 and returns in a0.
// Tried: ternary / early returns / separate result var / Iter wrapper structs / gcc404xs-O2 (adds the guard). Key{int,int}, less with !(b.first<a.first).
// near miss from lane lbp12b (unreviewed)
