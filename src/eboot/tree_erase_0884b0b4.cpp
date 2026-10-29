/* LBPMATCH module=EBOOT.BIN start=0x0884b0b4 end=0x0884b2cc symbol=FUN_0884b0b4 lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp11c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
struct Node { int pad[2]; Node *left; Node *right; int pad2[3]; };
struct Tree { int pad; };
struct Heap { char pad[32]; char lock[1]; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
inline void put_node(Node *p)
{
    Heap *h = sys_heap();
    FUN_08ad3088(h->lock);
    FUN_08adbc24(h, p, sizeof(Node));
    FUN_08ad2810(h->lock);
}
extern "C" void FUN_0884b0b4(Tree *t, Node *n)
{
    while (n) {
        FUN_0884b0b4(t, n->right);
        Node *next = n->left;
        put_node(n);
        n = next;
    }
}
