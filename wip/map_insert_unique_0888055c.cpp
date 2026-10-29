/* LBPMATCH module=EBOOT.BIN start=0x0888055c end=0x08880644 symbol=FUN_0888055c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { int key; };
struct Tree { int compare; NodeBase header; unsigned count; };
struct Result { Node *first; bool second; Result(Node *f, bool s) : first(f), second(s) {} };
extern "C" NodeBase *FUN_08b898a8(NodeBase *n);
extern "C" Node *FUN_08880478(Tree *t, NodeBase *x, NodeBase *p, const int &k);
extern "C" Result FUN_0888055c(Tree *t, const int &k)
{
    NodeBase *y = &t->header;
    NodeBase *x = t->header.parent;
    bool comp = true;
    while (x) {
        y = x;
        comp = k < static_cast<Node *>(x)->key;
        x = comp ? x->left : x->right;
    }
    NodeBase *j = y;
    if (comp) {
        if (j == t->header.left)
            return Result(FUN_08880478(t, 0, y, k), true);
        j = FUN_08b898a8(j);
    }
    if (static_cast<Node *>(j)->key < k)
        return Result(FUN_08880478(t, 0, y, k), true);
    return Result(static_cast<Node *>(j), false);
}
// NEAR 8 words (register only): retail keeps the loop flag in v0 (li v0,1 ... slt v0) and loads the final true separately (li a1,1); ours merges the constants into a1. Tried: bool/int flag, pair template, ternary vs if, comp as second, O2/402x/410.
// near miss from lane lbp8b (unreviewed)
