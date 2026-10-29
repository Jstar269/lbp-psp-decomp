/* LBPMATCH module=EBOOT.BIN start=0x089ee3b4 end=0x089ee4b4 symbol=FUN_089ee3b4 lang=c++ cc=gcc404xs-O2 */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::erase(first, last) (GCC 4.0) for a set/map with 8-byte values. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; unsigned val; };
extern "C" void FUN_08adbc24(void *heap, void *p, unsigned size);
extern "C" NodeBase *FUN_08b89838(NodeBase *x);
extern "C" NodeBase *FUN_08b89b70(NodeBase *z, NodeBase *header);
extern "C" void FUN_089ee1b4(struct Tree *t, Node *x);
extern void *DAT_08be84a0;
struct Iter {
    NodeBase *node;
    Iter(NodeBase *n) : node(n) {}
    Iter operator++(int) { Iter t = *this; node = FUN_08b89838(node); return t; }
    bool operator==(const Iter &o) const { return node == o.node; }
    bool operator!=(const Iter &o) const { return node != o.node; }
};
struct Tree {
    int compare; NodeBase header; unsigned count;
    Iter begin() { return Iter(header.left); }
    Iter end() { return Iter(&header); }
    void put_node(NodeBase *p) { FUN_08adbc24(DAT_08be84a0, p, 24); }
    void erase(Iter pos) {
        NodeBase *y = FUN_08b89b70(pos.node, &header);
        put_node(y);
        --count;
    }
    void clear() {
        Node *x = static_cast<Node *>(header.parent);
        while (x != 0) {
            FUN_089ee1b4(this, static_cast<Node *>(x->right));
            Node *y = static_cast<Node *>(x->left);
            put_node(x);
            x = y;
        }
        count = 0;
        header.left = &header;
        header.parent = 0;
        header.right = &header;
    }
    void erase(Iter first, Iter last) {
        if (first == begin() && last == end())
            clear();
        else
            while (first != last)
                erase(first++);
    }
};
extern "C" void FUN_089ee3b4(Tree *t, NodeBase *first, NodeBase *last)
{
    t->erase(Iter(first), Iter(last));
}
// NEAR: layout and every instruction match (cc=gcc404xs-O2); only the register assignment differs: retail keeps the tree in s1 and the current node in s2, ours the reverse (32 words). Tried: free-function loop, Iter by value, erase(first++) variants, if/early-return, store orders (CLPR matches the clear stores).
// near miss from lane lbp8a (unreviewed)
