/* LBPMATCH module=EBOOT.BIN start=0x088afc3c end=0x088afc94 symbol=FUN_088afc3c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane lbp4b, Claude Sonnet 5.5): placement new of a copy-constructed value in a heap node (null check on the member address comes from the throw() placement new); constructor symbol appended; exact match verified; names and types await human review. */
inline void *operator new(unsigned int, void *p) throw() { return p; }
struct Value { Value(const Value &); unsigned a; unsigned b; };
struct Node { unsigned x; unsigned y; Value v; };
extern "C" void *FUN_08adbb84(void *heap, unsigned size);
inline void *&game_heap() { static void *heap; return heap; }
extern "C" Node *FUN_088afc3c(int unused, const Value *src)
{
    Node *z = (Node *)FUN_08adbb84(game_heap(), sizeof(Node));
    new (&z->v) Value(*src);
    return z;
}
