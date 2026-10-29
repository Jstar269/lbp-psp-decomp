/* LBPMATCH module=EBOOT.BIN start=0x088bc14c end=0x088bc244 symbol=FUN_088bc14c lang=c++ */
/* Clone of src/eboot/map_insert_088b777c.cpp (lbpclone.py tag c16): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane lbp8c, Claude Sonnet 5.5); exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int DAT_08bef8f4;
extern "C" void FUN_08ad3088(void *);
extern "C" void FUN_08ad2810(void *);
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
extern "C" void FUN_08b899e4(bool insert_left, void *z, void *p, void *header);
inline void *&game_heap() { static void *heap; return heap; }
struct Rc { int pad; int count; };
struct Handle {
    Rc *r;
    Handle(const Handle &o) {
        Rc *rr = o.r;
        r = rr;
        if (rr) { FUN_08ad3088(&DAT_08bef8f4); rr->count++; FUN_08ad2810(&DAT_08bef8f4); }
    }
};
struct Value { unsigned key; Handle h; };
struct NodeBase { int color; NodeBase *parent; NodeBase *left; NodeBase *right; };
struct Node : NodeBase { Value v; };
struct Tree { int compare; NodeBase header; unsigned count; };
extern "C" Node *FUN_088bc14c(Tree *t, NodeBase *x, NodeBase *p, const Value &v)
{
    bool insert_left = (x != 0 || p == &t->header || v.key < static_cast<Node *>(p)->v.key);
    Node *z = (Node *)FUN_08adbb84(game_heap(), sizeof(Node));
    new (&z->v) Value(v);
    FUN_08b899e4(insert_left, z, p, &t->header);
    ++t->count;
    return z;
}
