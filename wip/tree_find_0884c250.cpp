/* LBPMATCH module=EBOOT.BIN start=0x0884c250 end=0x0884c34c symbol=FUN_0884c250 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Obj { char pad[12]; char bytes[20]; };
struct Key { int a; Obj *obj; int id; };
struct Node : NodeBase { Key key; };
extern "C" int FUN_08b9e714(const void *a, const void *b, unsigned n);
inline bool less(const Key &x, const Key &y)
{
    if (x.id != 0 || y.id != 0)
        return x.id - y.id < 0;
    return FUN_08b9e714(x.obj->bytes, y.obj->bytes, 20) < 0;
}
struct Tree { int comp; NodeBase header; unsigned count; };
extern "C" NodeBase *FUN_0884c250(Tree *t, const Key *k)
{
    Node *x = static_cast<Node *>(t->header.parent);
    NodeBase *end = &t->header;
    Node *y = static_cast<Node *>(end);
    while (x != 0) {
        if (!less(x->key, *k)) {
            y = x;
            x = static_cast<Node *>(x->left);
        } else {
            x = static_cast<Node *>(x->right);
        }
    }
    if (y == end)
        return end;
    if (less(*k, y->key))
        return end;
    return y;
}
// NEAR: ~46 words differ (layout only). Retail puts the two memcmp blocks out of line (after the early-return path, each ending j back with srl in the delay slot) and keeps the sub path as the fallthrough; ours (Os) inlines memcmp right after the sub path. O2 gives a different layout (duplicated epilogue). End test: retail uses branches (beqzl), ours movn/movz. Tried: && and || forms, r variable, nested ifs, early returns.
// near miss from lane lbp8a (unreviewed)
