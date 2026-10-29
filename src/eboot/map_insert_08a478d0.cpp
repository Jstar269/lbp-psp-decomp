/* LBPMATCH module=EBOOT.BIN start=0x08a478d0 end=0x08a479a4 symbol=FUN_08a478d0 lang=c++ cc=gcc404xs-O2 */
/* Clone of src/eboot/map_insert_089edb64.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. libstdc++ std::_Rb_tree::_M_insert (GCC 4.0) in an -O2 unit; the heap pointer is the local static of an inline accessor (see the -Os instances). */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { unsigned key; unsigned val; };
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
extern "C" Node *FUN_08a478d0(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < static_cast<Node *>(p)->v.key);
    Alloc<Node> a;
    Node *z = a.allocate(1);
    a.construct(&z->v, v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
