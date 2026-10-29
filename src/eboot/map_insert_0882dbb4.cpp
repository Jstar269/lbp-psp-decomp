/* LBPMATCH module=EBOOT.BIN start=0x0882dbb4 end=0x0882dca4 symbol=FUN_0882dbb4 lang=c++ cc=gcc404xs-Os */
/* Hand-written reconstruction from the disassembly (lane lbp8d, Claude Sonnet 5.5), after src/eboot/map_insert_0880c990.cpp: std::_Rb_tree::_M_insert for a three-int key ordered by its first two ints; exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { int a; int b; int c; };
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
inline bool less(const Value &x, const Value &y)
{
    if (x.a < y.a) return true;
    if (y.a < x.a) return false;
    return x.b < y.b;
}
extern "C" Node *FUN_0882dbb4(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || less(v, static_cast<Node *>(p)->v));
    Alloc<Node> a;
    Node *z = a.allocate(1);
    a.construct(&z->v, v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
