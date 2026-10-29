/* LBPMATCH module=EBOOT.BIN start=0x08931bb8 end=0x08931c30 symbol=FUN_08931bb8 lang=c++ */
/* Clone of src/eboot/map_clear_pair_08805edc.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8a, Claude Sonnet 5.5); exact match verified; names and types await human review. The four header stores are written in the order that yields the retail store order. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; unsigned val; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" void FUN_08adbc24(void *heap, void *p, unsigned size);
extern "C" void FUN_08931a00(Tree *t, Node *x);
extern void *DAT_08be84a0;
inline void put_node(Node *p) { FUN_08adbc24(DAT_08be84a0, p, sizeof(Node)); }
extern "C" void FUN_08931bb8(Tree *t)
{
    Node *x = static_cast<Node *>(t->header.parent);
    while (x != 0) {
        FUN_08931a00(t, static_cast<Node *>(x->right));
        Node *y = static_cast<Node *>(x->left);
        put_node(x);
        x = y;
    }
    t->count = 0;
    t->header.left = &t->header;
    t->header.parent = 0;
    t->header.right = &t->header;
}
