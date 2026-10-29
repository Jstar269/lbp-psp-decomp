/* LBPMATCH module=EBOOT.BIN start=0x08898644 end=0x08898750 symbol=FUN_08898644 lang=c++ */
/* Clone of src/eboot/map_insert_08885cb0.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Inner;
extern "C" void FUN_088985c4(Inner *, const Inner *);
struct Inner { int a; int b; int c; int d; Inner(const Inner &o) { FUN_088985c4(this, &o); } };
struct Key { int hi; unsigned lo; };
struct Value { Key key; Inner in; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Value v; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, NodeBase *z, NodeBase *p, NodeBase *header);
struct Heap { char pad[32]; char lock[1]; };
extern "C" Heap *DAT_08be84ac;
inline bool less(const Key &a, const Key &b) { return a.hi < b.hi || (a.hi == b.hi && a.lo < b.lo); }
extern "C" Node *FUN_08898644(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || less(v.key, static_cast<Node *>(p)->v.key));
    Heap *h = DAT_08be84ac;
    FUN_08ad3088(h->lock);
    Node *z = (Node *)FUN_08adbb84(h, sizeof(Node));
    FUN_08ad2810(h->lock);
    new (&z->v) Value(v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
