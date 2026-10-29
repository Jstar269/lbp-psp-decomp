/* LBPMATCH module=EBOOT.BIN start=0x0892fd5c end=0x0892fe20 symbol=FUN_0892fd5c lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp11d, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::_M_insert (GCC 4.0): insert_left, then the node from a stateless allocator over the game heap, placement-new of the value, _Rb_tree_insert_and_rebalance (0x08b899e4), ++count. The heap pointer is read through an inline accessor's local static: GCC 4.0 makes that object weak (its own .gnu.linkonce.b section, placed by lbpmatch at _ZZ9game_heapvE4heap from symbols/EBOOT.BIN.txt), and a weak object's load may trap, so sched1 does not hoist it above the insert_left branches, as in retail; with a plain extern global it is hoisted (13 words differ). */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { int key; int val; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Value v; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, NodeBase *z, NodeBase *p, NodeBase *header);
inline void *&game_heap() { static void *heap; return heap; }
template <class T> struct Alloc {
    T *allocate(unsigned n) { return (T *)FUN_08adbb84(game_heap(), n * sizeof(T)); }
    void construct(Value *p, const Value &v) { new (p) Value(v); }
};
extern "C" Node *FUN_0892fd5c(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < static_cast<Node *>(p)->v.key);
    Alloc<Node> a;
    Node *z = a.allocate(1);
    a.construct(&z->v, v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
