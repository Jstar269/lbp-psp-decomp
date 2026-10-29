/* LBPMATCH module=EBOOT.BIN start=0x0884b2cc end=0x0884b36c symbol=FUN_0884b2cc lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp12b, Claude Sonnet 5.5); exact match verified; names and types await human review. Tree clear: inlined erase loop (as tree_erase_0884b0b4), header reset; the four header stores are in the order found by search. */
struct Node { int pad[2]; Node *left; Node *right; int pad2[3]; };
struct Tree { int pad; int header[1]; Node *root; Node *leftmost; Node *rightmost; unsigned count; };
struct Heap { char pad[32]; char lock[1]; };
inline Heap *&sys_heap() { static Heap *heap; return heap; }
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void FUN_08adbc24(Heap *heap, void *p, unsigned size);
extern "C" void FUN_0884b0b4(Tree *t, Node *n);
inline void put_node(Node *p)
{
    Heap *h = sys_heap();
    FUN_08ad3088(h->lock);
    FUN_08adbc24(h, p, sizeof(Node));
    FUN_08ad2810(h->lock);
}
extern "C" void FUN_0884b2cc(Tree *t)
{
    Node *n = t->root;
    while (n) {
        FUN_0884b0b4(t, n->right);
        Node *next = n->left;
        put_node(n);
        n = next;
    }
    t->count = 0;
    t->leftmost = (Node *)t->header;
    t->root = 0;
    t->rightmost = (Node *)t->header;
}
