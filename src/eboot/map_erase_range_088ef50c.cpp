/* LBPMATCH module=EBOOT.BIN start=0x088ef50c end=0x088ef63c symbol=FUN_088ef50c lang=c++ */
/* Clone of src/eboot/map_erase_range_088eb018.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8b, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Shared { void (**vtbl)(Shared *); int count; };
struct Node : NodeBase { unsigned key; Shared *val; };
struct Tree { int compare; NodeBase header; unsigned count; };
struct Heap { char pad[32]; char lock[1]; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
struct Mutex { int a; };
extern Mutex DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
extern "C" NodeBase *FUN_08b89838(NodeBase *n);
extern "C" NodeBase *FUN_08b89b70(NodeBase *n, NodeBase *header);
extern "C" void FUN_088ef420(Tree *t);
inline void release(Shared *p)
{
    if (p) {
        FUN_08ad3088(&DAT_08bef8f4);
        int n = --p->count;
        FUN_08ad2810(&DAT_08bef8f4);
        if (n == 0)
            p->vtbl[2](p);
    }
}
inline void put_node(Node *p)
{
    Heap *h = sys_heap();
    FUN_08ad3088(h->lock);
    FUN_08adbc24(h, p, sizeof(Node));
    FUN_08ad2810(h->lock);
}
extern "C" void FUN_088ef50c(Tree *t, NodeBase *first, NodeBase *last)
{
    if (first == t->header.left && last == &t->header) {
        FUN_088ef420(t);
        return;
    }
    while (first != last) {
        NodeBase *next = FUN_08b89838(first);
        Node *y = static_cast<Node *>(FUN_08b89b70(first, &t->header));
        release(y->val);
        put_node(y);
        --t->count;
        first = next;
    }
}
