/* LBPMATCH module=EBOOT.BIN start=0x08805418 end=0x088054dc symbol=FUN_08805418 lang=c++ cc=gcc404xs-Os */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { unsigned key; unsigned val; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Value v; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, NodeBase *z, NodeBase *p, NodeBase *header);
extern void *DAT_08be84a0;
template <class T> struct Alloc {
    T *allocate(unsigned n) { return (T *)FUN_08adbb84(DAT_08be84a0, n * sizeof(T)); }
    void construct(Value *p, const Value &v) { new (p) Value(v); }
};
extern "C" Node *FUN_08805418(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < static_cast<Node *>(p)->v.key);
    Alloc<Node> a;
    Node *z = a.allocate(1);
    a.construct(&z->v, v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
