/* LBPMATCH module=EBOOT.BIN start=0x08927480 end=0x08927564 symbol=FUN_08927480 lang=c++ */
/* Clone of src/eboot/map_insert_locked_08870308.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { unsigned key; unsigned val; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Value v; };
struct Tree { int compare; NodeBase header; unsigned count; };
struct Heap { char pad[32]; char lock[1]; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void *FUN_08adbb84(Heap *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, NodeBase *z, NodeBase *p, NodeBase *header);
template <class T> struct Alloc {
    T *allocate(unsigned n)
    {
        Heap *h = sys_heap();
        FUN_08ad3088(h->lock);
        void *r = FUN_08adbb84(h, n * sizeof(T));
        FUN_08ad2810(h->lock);
        return (T *)r;
    }
    void construct(Value *p, const Value &v) { new (p) Value(v); }
};
extern "C" Node *FUN_08927480(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < static_cast<Node *>(p)->v.key);
    Alloc<Node> a;
    Node *z = a.allocate(1);
    a.construct(&z->v, v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
