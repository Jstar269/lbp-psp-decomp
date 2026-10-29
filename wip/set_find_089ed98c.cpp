/* LBPMATCH module=EBOOT.BIN start=0x089ed98c end=0x089ed9ec symbol=FUN_089ed98c lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp9c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; };
struct Tree { int compare; NodeBase header; unsigned count; };
static inline NodeBase *lower(NodeBase *x, NodeBase *y, const unsigned &k)
{
    while (x != 0) {
        if (!(static_cast<Node *>(x)->key < k)) { y = x; x = x->left; }
        else x = x->right;
    }
    return y;
}
extern "C" NodeBase *FUN_089ed98c(Tree *t, const unsigned *k)
{
    NodeBase *j = lower(t->header.parent, &t->header, *k);
    return (j == &t->header || *k < static_cast<Node *>(j)->key) ? &t->header : j;
}
// NEAR 16 words at O2 (loop shape matches). Retail reloads *k after the loop (lw v0,0(a1)) and keeps it hoisted (a3) in the loop; ours CSEs them and also threads the empty-tree path to a direct return.
// Tried: Os (different shape), O2, gcc402x/410/171 profiles, find with inline lower_bound(x,y,k) vs hand loop.
// near miss from lane lbp9c (unreviewed)
