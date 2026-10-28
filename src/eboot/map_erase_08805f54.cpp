/* LBPMATCH module=EBOOT.BIN start=0x08805f54 end=0x0880610c symbol=FUN_08805f54 lang=c++ cc=gcc404xs-Os */
/* Clone of src/eboot/map_erase_08805b6c.cpp (lbpclone.py tag c11): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. libstdc++'s std::_Rb_tree::_M_erase (GCC 4.0) for a map with an 8-byte value and a stateless allocator over the game heap; GCC inlines the recursion 8 levels deep (max-inline-recursive-depth-auto), which needs the default -Os inline limits of gcc404xs-Os. */
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { unsigned key; unsigned val; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" void FUN_08adbc24(void *heap, void *p, unsigned size);
extern void *DAT_08be84a0;
inline void put_node(Node *p) { FUN_08adbc24(DAT_08be84a0, p, sizeof(Node)); }
extern "C" void FUN_08805f54(Tree *t, Node *x)
{
    while (x != 0) {
        FUN_08805f54(t, static_cast<Node *>(x->right));
        Node *y = static_cast<Node *>(x->left);
        put_node(x);
        x = y;
    }
}
