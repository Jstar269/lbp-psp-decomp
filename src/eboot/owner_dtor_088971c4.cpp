/* LBPMATCH module=EBOOT.BIN start=0x088971c4 end=0x08897298 symbol=FUN_088971c4 lang=c++ */
/* Clone of src/eboot/owner_dtor_08884634.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Heap { char pad[32]; char lock[1]; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { char payload[24]; };
struct Tree { int compare; NodeBase header; unsigned count; };
struct Inner { char pad[16]; Tree map; int f40; };
struct Owner { void *vtbl; int f4; int f8; Inner *inner; Tree map; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
extern "C" void FUN_08a9e0c4(int);
extern "C" void FUN_08a9e0cc(void *);
extern "C" void FUN_0887a8c8(Tree *t, NodeBase *x);
extern "C" void FUN_0889604c(Tree *t, NodeBase *root);
extern void *DAT_08bb1090;
inline void put_node(Node *x)
{
    Heap *heap = sys_heap();
    FUN_08ad3088(heap->lock);
    FUN_08adbc24(heap, x, sizeof(Node));
    FUN_08ad2810(heap->lock);
}
inline void erase_tree(Tree *t)
{
    NodeBase *x = t->header.parent;
    while (x) {
        FUN_0887a8c8(t, x->right);
        NodeBase *y = x->left;
        put_node(static_cast<Node *>(x));
        x = y;
    }
}
inline void destroy_tree(Tree *t) { FUN_0889604c(t, t->header.parent); }
extern "C" void FUN_088971c4(Owner *o)
{
    Inner *in = o->inner;
    o->vtbl = &DAT_08bb1090;
    if (in) {
        Tree *t = &in->map;
        if (in->f40)
            FUN_08a9e0c4(in->f40);
        erase_tree(t);
        FUN_08a9e0cc(in);
    }
    destroy_tree(&o->map);
}
