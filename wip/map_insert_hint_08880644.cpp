/* LBPMATCH module=EBOOT.BIN start=0x08880644 end=0x088807f0 symbol=FUN_08880644 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { int key; };
struct Tree { int compare; NodeBase header; unsigned count; };
struct Result { Node *first; bool second; Result(Node *f, bool s) : first(f), second(s) {} };
extern "C" NodeBase *FUN_08b898a8(NodeBase *n);
extern "C" NodeBase *FUN_08b89838(NodeBase *n);
extern "C" long long FUN_08880478(Tree *t, NodeBase *x, NodeBase *p, const int &k);
static inline Node *insert(Tree *t, NodeBase *x, NodeBase *p, const int &k) { return (Node *)FUN_08880478(t, x, p, k); }
extern "C" Result FUN_0888055c(Tree *t, const int &k);
static inline int key_of(NodeBase *n) { return static_cast<Node *>(n)->key; }
extern "C" Node *FUN_08880644(Tree *t, NodeBase *pos, const int &k)
{
    if (pos == &t->header) {
        if (t->count > 0 && key_of(t->header.right) < k)
            return insert(t, 0, t->header.right, k);
        return FUN_0888055c(t, k).first;
    } else if (k < key_of(pos)) {
        NodeBase *before = pos;
        if (pos == t->header.left)
            return insert(t, t->header.left, t->header.left, k);
        before = FUN_08b898a8(before);
        if (key_of(before) < k) {
            if (before->right == 0)
                return insert(t, 0, before, k);
            return insert(t, pos, pos, k);
        }
        return FUN_0888055c(t, k).first;
    } else if (key_of(pos) < k) {
        NodeBase *after = pos;
        if (pos == t->header.right)
            return insert(t, 0, t->header.right, k);
        after = FUN_08b89838(after);
        if (k < key_of(after)) {
            if (pos->right == 0)
                return insert(t, 0, pos, k);
            return insert(t, after, after, k);
        }
        return FUN_0888055c(t, k).first;
    }
    return static_cast<Node *>(pos);
}
// NEAR ~4 words (position shift): retail does "move s0,a1" at entry (before the first bne) and saves s0 before it; ours moves a1 to s0 only in the second branch and saves ra first. Matching idiom used: FUN_08880478 declared returning long long (non-tail calls as retail), wrapped by insert(). Tried: unconditional position copy at the top.
// near miss from lane lbp8b (unreviewed)
